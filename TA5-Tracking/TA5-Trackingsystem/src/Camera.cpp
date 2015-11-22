/*
 * camera.cpp
 *
 *  Created on: 12.11.2015
 *      Author: Jannik
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
  capture = VideoCapture(cameraIndex);
  if (!capture.isOpened()) {
    //return -1;
  }

  this->settingsFilename = settingsFile;

  readSettings(settingsFile);
}

Camera::~Camera() {
  //saveSettings(settingsFilename); // TODO machen oder nicht??

  capture.release();
}

VideoCapture Camera::get_capture() {

  return capture;
}

void Camera::correctDistortion(InputArray src, OutputArray dst) {
  // TODO call undistortPoints()
  //cv::undistortPoints(src, dst,
  //                    *cameraMatrix, *distCoeffs);
}

int Camera::readSettings() {
  return readSettings(settingsFilename);
}

int Camera::readSettings(string settingsFile) {
  // TODO save settingsFile string local (potentially overwrite constructor settings) ??

  FileStorage fs(settingsFile, FileStorage::READ); // Read the settings
  if (!fs.isOpened()) {
    //cout << "Could not open the configuration file: \"" << settingsFile << "\"" << endl;
    return -1;
  }

  fs["cameraMatrix"] >> cameraMatrix;
  fs["distCoeffs"] >> distCoeffs;
  fs["rvecs"] >> rvecs;
  fs["tvecs"] >> tvecs;

  fs.release();                                    // close Settings file
  return 0;
}

int Camera::saveSettings() {
  return saveSettings(settingsFilename);
}

int Camera::saveSettings(string settingsFile) {
  FileStorage fs(settingsFile, FileStorage::WRITE); // Read the settings
  if (!fs.isOpened()) {
    //cout << "Could not open the configuration file: \"" << settingsFile << "\"" << endl;
    return -1;
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
  return 0;
}
