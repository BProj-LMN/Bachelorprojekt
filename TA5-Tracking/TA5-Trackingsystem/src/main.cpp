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

#include "Camera.h"
#include "calibrate3D.h"
#include "calibrateCamera.h"
#include "ObjectDetection.h"
#include "globalConstants.h"

int main(int argc, const char** argv) {
  string options;

  Socket remoteInput(61362);
  string message;

  Camera cam1(0);
  Camera cam2(1);
  VideoCapture cap1 = cam1.get_capture();

  Mat frame;

  cout << "Guten Tag, hier ist das Tracking-System. Was wollen Sie?" << endl;

  /*
   * start directly to one mode by program argument or get input by user
   */
  if (argc > 1) {
    options = argv[1];
  }else {
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
      return(0);

    } else if (0 == options.compare("tracking")) {
      cout << "--> do normal operation" << endl;
      break;

    } else {
      cout << "diese Eingabe ist nicht zugelassen" << endl;
    }

    cout << "zugelassene Optionen: loadConfig, calibrateCamera, calibrate3D, tracking, exit" << endl;
    cin >> options;
  }

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
    cap1 >> frame;
    imshow("foo", frame);

  }

  return 0;

}
