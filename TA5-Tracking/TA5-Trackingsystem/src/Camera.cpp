/*
 * camera.cpp
 *
 *  Created on: 12.11.2015
 *      Author: Jannik
 */

#include "Camera.h"

Camera::Camera(int cameraIndex) {

  capture = VideoCapture(cameraIndex);
  if (!capture.isOpened()) {
    //return -1;
  }

}

Camera::~Camera() {
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
