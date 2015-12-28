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

#define TEST  // for testing the system without cameras

#define DEFAULT_FILENAME "cameraStorage-"

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>
using namespace cv;

#include <time.h>
#include <iostream>
using namespace std;

#include "myGlobalConstants.h"

class Camera {
  VideoCapture capture;
  int cameraID;
  string settingsFilename;
  Rect frameMaskRect;
  Mat frameMask;
  bool frameMaskSet;

  Point3f positionVector; // position            (o) - will be saved and loaded
  Point3f viewingCenter;  // central image point (p) - will be saved and loaded
  Point3f viewingRight;   // second image point  (t) - will be saved and loaded
  Point3f cameraRotation; // 3 euler rotations   (w) - will be computed
  Mat rotationMatrix;     // 3x3 float !!!

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
  int correctDistortion(Point2i src, Point2f dst);

  int readSettings(string settingsFile);  // read from temporarily filename
  int readSettings();                     // read from filename from constructor
  int saveSettings(string settingsFile);  // save to temporarily filename
  int saveSettings();                     // save to filename from constructor
  int get_cameraID();
  int set_frameMask(Rect frameMask);
  int get_newFrame(Mat& frame);
  int set_projMatr();

  // vector from Camera to object in world coordinates,
  // be shure to reload settings after changing intrinsic parameters
  int calcNewObjectRayVector(Point2f pixelPosition, Point3f objectRay);

private:
  int setupRotationMatrix(); // call after changing camera position information - or reload setting
  int calcObjectRayInCameraCoordinates(Point2f pixelPosition, Point3f objectRayCameraCoord);

};

#endif /* SRC_CAMERA_H_ */
