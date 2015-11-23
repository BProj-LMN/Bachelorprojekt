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

  capture = VideoCapture(cameraIndex);
  if (!capture.isOpened()) {
    //return -1;
  }

  this->settingsFilename = settingsFile;
}

Camera::~Camera() {
  capture.release();
}

VideoCapture Camera::get_capture() {
  return capture;
}

int Camera::getID(){
	return cameraID;
}

void Camera::correctDistortion(InputArray src, OutputArray dst) {
  // TODO Task: call undistortPoints()
  //cv::undistortPoints(src, dst,
  //                    *cameraMatrix, *distCoeffs);
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
