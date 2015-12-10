/*
 * camera.h
 *
 * function: store all information of one camera
 *           save/read all parameters to/from file
 *
 * author: Jannik Beyerstedt
 */

#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_

#define DEFAULT_FILENAME "cameraSettings-"

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>
using namespace cv;

#include <time.h>
using namespace std;

#include "myGlobalConstants.h"

class Camera {
  VideoCapture capture;
  int cameraID;
  string settingsFilename;
  Mat frameMask;
  bool frameMaskSet;

public:
  Mat cameraMatrix;
  Mat distCoeffs;
  Mat rvecs;
  Mat tvecs;
  Mat projMatr;
  bool intrinsicParamsLoaded;

public:
  Camera(int cameraIndex);
  Camera(int cameraIndex, string settingsFile);
  virtual ~Camera();

  VideoCapture get_capture();
  int correctDistortion(InputArray src, OutputArray dst);

  int readSettings(string settingsFile);  // read from temporarily filename
  int readSettings();                     // read from filename from constructor
  int saveSettings(string settingsFile);  // save to temporarily filename
  int saveSettings();                     // save to filename from constructor
  int get_cameraID();
  int set_frameMask(Rect frameMask);
  int get_newFrame(Mat& frame);
  int set_projMatr();

};

#endif /* SRC_CAMERA_H_ */
