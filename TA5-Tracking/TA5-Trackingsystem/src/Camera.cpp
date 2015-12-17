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

  capture = VideoCapture(cameraIndex);
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

int Camera::correctDistortion(InputArray src, OutputArray dst) {
  // TODO Task: call undistortPoints()
  //cv::undistortPoints(src, dst,
  //                    *cameraMatrix, *distCoeffs);

  return OK;
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

  fs["cameraMatrix"] >> cameraMatrix;
  fs["distCoeffs"] >> distCoeffs;
  fs["rvecs"] >> rvecs;
  fs["tvecs"] >> tvecs;

  fs.release();                                    // close Settings file
  intrinsicParamsLoaded = 1;
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

  fs << "cameraMatrix" << cameraMatrix;
  fs << "distCoeffs" << distCoeffs;
  fs << "rvecs" << rvecs;
  fs << "tvecs" << tvecs;

  fs.release();                                    // close Settings file
  return OK;
}

int Camera::set_frameMask(Rect frameMask) {
  Mat frame;
  capture >> frame;
  this->frameMask = Mat::zeros(frame.rows, frame.cols, CV_8U);
  this->frameMask(frameMask) = 255;

  frameMaskSet = 1;

  return OK;
}

int Camera::get_newFrame(Mat& frame) {
  capture >> frame;
  cvtColor(frame, frame, CV_BGR2GRAY);

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
