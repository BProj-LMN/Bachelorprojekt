/*
 * Bachelorprojekt WS 2015/16 - HAW Hamburg - Quadrocopter-Tracking und Positionsregelung
 * TRACKING SYSTEM
 *
 * authors: Jannik Beyerstedt, Daniel Friedrich
 */

#include <iostream>
using namespace std;

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
#include "Socket.h"

int main(int argc, const char** argv) {
  string options;

  Camera cam1(0);
  VideoCapture cap1 = cam1.get_capture();

  Socket remoteInput(61382);
  string message;

  namedWindow("foo", 1);
  Mat frame;

  cout << "Guten Tag, hier ist das Tracking-System. Was wünschen Sie?" << endl;
  while(1) {
    cout << "mögliche Optionen: loadConfig, calibrateCamera, calibrate3D, tracking" << endl;
    cin >> options;
    //cout << "Sie haben " << options << " gewählt" << endl;

    if(0 == options.compare("loadConfig")) {
      cout << "--> do loadConfig subroutine" << endl;

    }else if(0 == options.compare("calibrateCamera")) {
      cout << "--> do calibrateCamera subroutine" << endl;
      calibrateCamera("calibrateCamera0.xml", cam1.cameraMatrix, cam1.distCoeffs);

    }else if (0 == options.compare("calibrate3D")) {
      cout << "--> do calibrate3D subroutine" << endl;

    }else if (0 == options.compare("tracking")) {
      cout << "--> do normal operation" << endl;
      break;
    }else {
      cout << "diese Eingabe ist nicht zulässig" << endl;
    }
  }


  while (1) {
    /*
     * evaluate remote input
     */
    remoteInput.evaluate();
    int newMessage = remoteInput.get_message(message);

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
