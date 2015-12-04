/*
 * Bachelorprojekt WS 2015/16 - HAW Hamburg - Quadrocopter-Tracking und Positionsregelung
 * TRACKING SYSTEM
 *
 * authors: Jannik Beyerstedt, Daniel Friedrich
 */

#include <iostream>
using namespace std;

#include "Socket.h"

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

#include <tisgrabber.h>

#include "Camera.h"
#include "calibrate3D.h"
#include "calibrateCamera.h"
#include "ObjectDetection.h"
#include "myGlobalConstants.h"

int main(int argc, const char** argv) {
  string options;

  Socket remoteInput(1362);
  string message;

  Camera cam1(0);
  Camera cam2(1);
  VideoCapture cap1 = cam1.get_capture();
  VideoCapture cap2 = cam2.get_capture();


  ObjectDetection detect1(&cam1);
  ObjectDetection detect2(&cam2);
  Mat frame1, frame2;

  cout << "Guten Tag, hier ist das Tracking-System. Was wollen Sie?" << endl;

  /*
   * start directly to one mode by program argument or get input by user
   */
  if (argc > 1) {
    options = argv[1];
  } else {
    cin >> options;
  }

  while (1) {
    if (0 == options.compare("loadConfig")) {
      cout << "--> do loadConfig subroutine" << endl;
      // TODO load all config --> complete settings methods of Camera
      cam1.readSettings("cam1.xml");
      cam2.readSettings("cam2.xml");

    } else if (0 == options.compare("calibrateCamera")) {
      cout << "--> do calibrateCamera subroutine" << endl;
      calibrateCameras(&cam1, &cam2);

    } else if (0 == options.compare("calibrate3D")) {
      cout << "--> do calibrate3D subroutine" << endl;
      calibrate3D(&cam1, &cam2);

    } else if (0 == options.compare("exit")) {
      cout << "--> terminating ... Auf Wiedersehen" << endl;
      cam1.saveSettings("cam1.xml");
      cam2.saveSettings("cam2.xml");
      return (0);

    } else if (0 == options.compare("tracking")) {
      cout << "--> do normal operation" << endl;
      break;

    } else {
      cout << "diese Eingabe ist nicht zugelassen" << endl;
    }

    cout << "zugelassene Optionen: loadConfig, calibrateCamera, calibrate3D, tracking, exit" << endl;
    cin >> options;
  }

  int pixelPosition1[2];
  int pixelPosition2[2];

  for (int i = 0; i < 20; i++) {
    cap1 >> frame1;
    cap2 >> frame2;
    cvtColor(frame1, frame1, CV_BGR2GRAY);
    cvtColor(frame2, frame2, CV_BGR2GRAY);
    imshow("reference frame1", frame1);
    imshow("reference frame2", frame2);

    if (waitKey(30) >= 0) {
      break;
    }
  }

  //cap1 >> frame1;
  detect1.setReferenceFrame(frame1);
  detect2.setReferenceFrame(frame2);

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
     * do something
     */
    cap1 >> frame1;
    cap2 >> frame2;
    cvtColor(frame1, frame1, CV_BGR2GRAY);
    cvtColor(frame2, frame2, CV_BGR2GRAY);
    imshow("trackingbild_1", frame1);
    imshow("trackingbild_2", frame2);

    if(detect1.detectObject(frame1, pixelPosition1) !=ERR) {
      circle(frame1, Point(pixelPosition1[0], pixelPosition1[1]), 30, Scalar(255, 0, 0), 1);
      imshow("final_tracking1", frame1);
    }
    if(detect2.detectObject(frame2, pixelPosition2) != ERR) {
      circle(frame2, Point(pixelPosition2[0], pixelPosition2[1]), 30, Scalar(255, 0, 0), 1);
      imshow("final_tracking2", frame2);
    }
    if (waitKey(30) >= 0) {
      break;
    }

  }
  destroyWindow("reference frame1");
  destroyWindow("reference frame2");
  destroyWindow("trackingbild_1");
  destroyWindow("trackingbild_2");
  destroyWindow("final_tracking1");
  destroyWindow("final_tracking2");

  return 0;

}
