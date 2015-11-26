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

  Socket remoteInput(61362);
  string message;

  Camera cam1(0);
  Camera cam2(1);
  VideoCapture cap1 = cam1.get_capture();
  VideoCapture cap2 = cam2.get_capture();

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

  //IC_InitLibrary(0);
  //HGRABBER hGrabber;
// if (IC_InitLibrary(0)) {
//    hGrabber = IC_CreateGrabber();
//  }
  //IC_ReleaseGrabber( hGrabber );

//  HGRABBER testcamera1 = IC_CreateGrabber();
  //cout << IC_GetAvailableFrameFilterCount();
  //IC_SetExpAbsVal(camera1, 0.5);
  // IC_ReleaseGrabber(&testcamera1);

  namedWindow("test1", 1);
  namedWindow("test2", 1);

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
    flip(frame1, frame1, 0);
    flip(frame1, frame1, 1);
    imshow("test1", frame1);

    cap2 >> frame2;
    flip(frame2, frame2, 0);
    flip(frame2, frame2, 1);
    imshow("test2", frame2);

    if (waitKey(30) >= 0) {
      break;
    }

  }

  return 0;

}
