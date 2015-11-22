/*
 * camera.h
 *
 *  Created on: 12.11.2015
 *      Author: Jannik
 */

#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_

#define DEFAULT_FILENAME "cameraSettings-"

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

class Camera {
  VideoCapture capture;
  int cameraID;
  string settingsFilename;

public:
  Mat cameraMatrix;
  Mat distCoeffs;
  vector<Mat> rvecs;
  vector<Mat> tvecs;

public:
  Camera(int cameraIndex);
  Camera(int cameraIndex, string settingsFile);
  virtual ~Camera();

  VideoCapture get_capture();
  void correctDistortion(InputArray src, OutputArray dst);

  int readSettings(string settingsFile);  // set filename
  int readSettings();                     // with filename from constructor
  int saveSettings(string settingsFile);  // set filename
  int saveSettings();                     // with filename from constructor

};

#endif /* SRC_CAMERA_H_ */
