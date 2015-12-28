/*
 * camera.cpp
 *
 * function: store all information of one camera
 *           save/read all parameters to/from file
 *
 * author: Jannik Beyerstedt
 */

#include "Camera.h"

Camera::Camera(int cameraIndex) {
  this->cameraID = cameraIndex;
  intrinsicParamsLoaded = 0;
  frameMaskSet = 0;

#ifndef TEST
  capture = VideoCapture(cameraIndex);
#else
  if (0 == cameraIndex) {
    capture = VideoCapture("test/frameCam1-01.png");
  } else if (1 == cameraIndex) {
    capture = VideoCapture("test/frameCam2-01.png");
  }
#endif
  if (!capture.isOpened()) {
    //return -1;
  }

  // use default filename
  stringstream string;
  string << DEFAULT_FILENAME << cameraID;
  settingsFilename = string.str();
}

Camera::Camera(int cameraIndex, string settingsFile) {
  this->cameraID = cameraIndex;
  intrinsicParamsLoaded = 0;
  frameMaskSet = 0;

  capture = VideoCapture(cameraIndex);
  if (!capture.isOpened()) {
    //return -1;
  }

  this->settingsFilename = settingsFile;
}

Camera::~Camera() {
  capture.release();
  cout << "[INFO]Camera::~Camera - released capture" << endl;
}

VideoCapture Camera::get_capture() {
  return capture;
}

int Camera::get_cameraID() {
  return cameraID;
}

int Camera::correctDistortion(Point2i src, Point2f dst) {
  // TODO Task: call undistortPoints()
  //undistortPoints(src, dst, *cameraMatrix, *distCoeffs);

  return ERR;
}

int Camera::readSettings() {
  return readSettings(settingsFilename);
}

int Camera::readSettings(string settingsFile) {
  FileStorage fs(settingsFile, FileStorage::READ); // Read the settings
  if (!fs.isOpened()) {
    fprintf(stderr, "ERROR: Camera::readSettings - opening file \n");
    return ERR;
  }

  fs["frameMaskRect"] >> frameMaskRect;
  fs["cameraMatrix"] >> cameraMatrix;
  fs["distCoeffs"] >> distCoeffs;
  fs["rvecs"] >> rvecs;
  fs["tvecs"] >> tvecs;
  fs["tvecs"] >> tvecs;
  fs["positionVector"] >> positionVector;
  fs["viewingCenter"] >> viewingCenter;
  fs["viewingRight"] >> viewingRight;

  fs.release();                                    // close Settings file
  intrinsicParamsLoaded = 1;
  if (frameMaskRect.area() > 0) {
    frameMaskSet = 1;
  }

  setupRotationMatrix();

  return OK;
}

int Camera::saveSettings() {
  return saveSettings(settingsFilename);
}

int Camera::saveSettings(string settingsFile) {
  FileStorage fs(settingsFile, FileStorage::WRITE); // Read the settings
  if (!fs.isOpened()) {
    fprintf(stderr, "ERROR: Camera::saveSettings - opening file \n");
    return ERR;
  }

  time_t tm;
  time(&tm);
  struct tm *t2 = localtime(&tm);
  fs << "timestamp" << (int) tm;
  char buf[1024];
  strftime(buf, sizeof(buf) - 1, "%c", t2);
  fs << "datetime" << buf;

  fs << "frameMaskRect" << frameMaskRect;
  fs << "cameraMatrix" << cameraMatrix;
  fs << "distCoeffs" << distCoeffs;
  fs << "rvecs" << rvecs;
  fs << "tvecs" << tvecs;
  fs << "positionVector" << positionVector;
  fs << "viewingCenter" << viewingCenter;
  fs << "viewingRight" << viewingRight;

  fs.release();                                    // close Settings file
  return OK;
}

int Camera::set_frameMask(Rect frameMask) {
  if (frameMask.area() > 0) {
    Mat frame;
    capture >> frame;
    this->frameMask = Mat::zeros(frame.rows, frame.cols, CV_8U);
    this->frameMask(frameMask) = 255;

    this->frameMaskRect = frameMask;

    frameMaskSet = 1;
  } else {
    cout << "[ERROR] Camera::set_frameMask - no valid frameMask given in" << endl;
  }

  return OK;
}

int Camera::get_newFrame(Mat& frame) {
  capture >> frame;
#ifdef TEST
  if (capture.get(CAP_PROP_POS_FRAMES) >= capture.get(CAP_PROP_FRAME_COUNT)) {
    capture.set(CAP_PROP_POS_FRAMES, 0);
  }
#endif
  cvtColor(frame, frame, CV_BGR2GRAY);

  //vector<Mat> channels;
  //split(frame, channels);
  //frame = channels[0];

  if (frameMaskSet) {
    frame = frame & frameMask;
  }

  return OK;
}

int Camera::set_projMatr() {
  Mat rotMatr;
  Mat rtCombinedMatr;

  Rodrigues(rvecs, rotMatr);
  hconcat(rotMatr, tvecs, rtCombinedMatr);

  this->projMatr = cameraMatrix * rtCombinedMatr;

  cout << "rtCombined" << endl << rtCombinedMatr << endl;

  return OK;
}

int Camera::setupRotationMatrix() {
  // TODO
  // calculate rotation angles of viewingVectors
  // calculate rotation matrix for all 3 rotations at once

  Point3f r = viewingCenter - positionVector;
  Point3f s = viewingRight - positionVector;

  /*
   * MATLAB
   * cam1_w1 = -atan2(cam1_r(2), cam1_r(1));
   * cam1_w2 = -asin(cam1_r(3)/norm(cam1_r));
   *
   * Xaxis_new = rotate2_euler(cam1_w2) * rotate1_euler(cam1_w1) * baseXaxis;
   * Yaxis_new = rotate2_euler(cam1_w2) * rotate1_euler(cam1_w1) * baseYaxis;
   * rotatedSys1_Plane = cross(Xaxis_new, Yaxis_new);
   * cam1_ViewingPlane = cross(cam1_s', cam1_r');
   * cam1_w3 = -acos( dot(rotatedSys1_Plane, cam1_ViewingPlane) / ( norm(rotatedSys1_Plane)*norm(cam1_ViewingPlane) ) );
   */

  float w1 = -atan2(r.y, r.x);
  float w2 = -asin(r.z/ sqrt(r.x*r.x+r.y*r.y+r.z*r.z) );

  // TODO euler rotations

  return ERR;
}

int Camera::calcNewObjectRayVector(Point2f pixelPosition, Point3f objectRay) {
  // pixelPosition is float instead if int, because there are subpixel values after undistort

  // TODO implement
  // calculate object ray in world coordinates from pixel position

  Point3f objectRayCameraCoord;

  if (ERR == calcObjectRayInCameraCoordinates(pixelPosition, objectRayCameraCoord)) {
    return ERR;
  }

  // transform vector to world coordinates by multiplying rotationMatrix in front of the vector
  // TODO Matrix multiplication OR convert Point3f to Mat
  //objectRay = rotationMatrix * objectRayCameraCoord;

  return ERR;
}

int Camera::calcObjectRayInCameraCoordinates(Point2f pixelPosition, Point3f objectRay) {
  // TODO implement
  // calculate object ray from pixel value on the sensor. Vector is in camera coordinate system

  return ERR;
}
