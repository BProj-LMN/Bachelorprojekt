/*
 * Bachelorprojekt WS 2015/16 - HAW Hamburg - Quadrocopter-Tracking und Positionsregelung
 * TRACKING SYSTEM
 *
 * authors: Jannik Beyerstedt, Daniel Friedrich
 */

#define CAM1_FILENAME "cameraStorage1.xml"
#define CAM2_FILENAME "cameraStorage2.xml"

#include <iostream>
using namespace std;

#include "Socket.h"

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

//#include <tisgrabber.h>

#include "Camera.h"
#include "calibrate3D.h"
#include "calibrateCamera.h"
#include "ObjectDetection.h"
#include "myGlobalConstants.h"
#include "calibrateFrameMask.h"

void printHelp() {
  cout << "\n"
       << "zugelassene Optionen: loadConfig, calibrateCamera, calibrate3D, setFrameMask1, setFrameMask2, save, "
       << "tracking, loadAndTrack, save&exit, exit" << endl;
}

int main(int argc, const char** argv) {
  string options;

  Socket remoteInput(1362);
  string message;

  Camera cam1(0);
  Mat frame1;
  Camera cam2(1);
  Mat frame2;

  ObjectDetection detect1(&cam1);
  Point2i pixelPos1(0, 0);
  ObjectDetection detect2(&cam2);
  Point2i pixelPos2(0, 0);

  Point2f objectPos3D;

  try {

    /*
     * start directly to one mode by program argument or get input by user
     */
    if (argc > 1) {
      options = argv[1];
    } else {
      cout << "Guten Tag, hier ist das Tracking-System. Was wollen Sie?" << endl;
      printHelp();
      cin >> options;
    }

    while (1) {
      if (0 == options.compare("loadConfig")) {
        cout << "--> do loadConfig subroutine" << endl;
        cam1.readSettings(CAM1_FILENAME);
        cam2.readSettings(CAM2_FILENAME);

      } else if (0 == options.compare("calibrateCamera")) {
        cout << "--> do calibrateCamera subroutine" << endl;
        calibrateCameras(&cam1, &cam2);

      } else if (0 == options.compare("calibrate3D")) {
        cout << "--> do calibrate3D subroutine" << endl;
        calibrate3D(&cam1, &cam2);

      } else if (0 == options.compare("setFrameMask1")) {
        cout << "--> do calibrateFrameMask subroutine" << endl;
        calibrateFrameMask(&cam1);

      } else if (0 == options.compare("setFrameMask2")) {
        cout << "--> do calibrateFrameMask subroutine" << endl;
        calibrateFrameMask(&cam2);

      } else if (0 == options.compare("save")) {
        cout << "--> save camera object parameters" << endl;
        cam1.saveSettings(CAM1_FILENAME);
        cam2.saveSettings(CAM2_FILENAME);

      } else if (0 == options.compare("exit")) {
        cout << "--> terminating ... Auf Wiedersehen" << endl;
        return (0);

      } else if (0 == options.compare("save&exit")) {
        cout << "--> saving and terminating ... Auf Wiedersehen" << endl;
        cam1.saveSettings(CAM1_FILENAME);
        cam2.saveSettings(CAM2_FILENAME);
        return (0);

      } else if (0 == options.compare("tracking")) {
        cout << "--> do normal operation" << endl;
        break;

      } else if (0 == options.compare("loadAndTrack")) {
        cout << "--> loading config and track" << endl;
        cam1.readSettings(CAM1_FILENAME);
        cam2.readSettings(CAM2_FILENAME);
        break;

      } else {
        cout << "diese Eingabe ist nicht zugelassen" << endl;
      }

      printHelp();
      cin >> options;
    }

    /*
     * setup things
     */
    cam1.set_projMatr();
    cam2.set_projMatr();

    /*
     * set reference frame for tracking
     */
    cout << "waiting for reference frame..." << endl;
    namedWindow("reference frame 1", WINDOW_AUTOSIZE);
    namedWindow("reference frame 2", WINDOW_AUTOSIZE);
    for (int i = 0; i < 40; i++) {
      cam1.get_newFrame(frame1);
      cam2.get_newFrame(frame2);
      imshow("reference frame 1", frame1);
      imshow("reference frame 2", frame2);

      if (waitKey(30) >= 0) {
        break;
      }
    }
    detect1.setReferenceFrame(frame1);
    detect2.setReferenceFrame(frame2);
    cout << "reference frame set" << endl;
    destroyWindow("reference frame 1");
    destroyWindow("reference frame 2");

    /*
     * main tracking routine
     */
    namedWindow("tracking 1", WINDOW_NORMAL);
    namedWindow("tracking 2", WINDOW_NORMAL);

    while (1) {
      /*
       * evaluate remote input
       */
      remoteInput.evaluate();
      bool newMessage = remoteInput.get_message(message);

      if (newMessage) {
        // do something
        char answer[MESSAGE_LEN] = "some answer\n";
        remoteInput.sendMessage(answer);
      }

      /*
       * get frame and track object
       */
      cam1.get_newFrame(frame1);
      cam2.get_newFrame(frame2);

      if (detect1.detectObject(frame1, pixelPos1) != ERR) {
        circle(frame1, Point(pixelPos1.x, pixelPos1.y), 30, Scalar(255, 0, 0), 1);
      }
      imshow("tracking 1", frame1);
      if (detect2.detectObject(frame2, pixelPos2) != ERR) {
        circle(frame2, Point(pixelPos2.x, pixelPos2.y), 30, Scalar(255, 0, 0), 1);
      }
      imshow("tracking 2", frame2);

      if (waitKey(30) >= 0) {
        break;
      }

      /*
       * calculate 3D position
       */
      // TODO undistort

      // TODO triangulate
      cout << objectPos3D << endl;

      /*
       * send position via UDP socket
       * TODO: socket send
       */
    }

    /*
     * tidy everything up
     */
    destroyWindow("tracking 1");
    destroyWindow("tracking 2");
    cout << "windows destroyed" << endl;
    cout << "program successful terminated" << endl;

    return (0);

  } catch (cv::Exception & e) {
    cout << e.msg << endl;
  }

}
