/*
 * camera.h
 *
 *  Created on: 12.11.2015
 *      Author: Jannik
 */

#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;


class Camera {
  VideoCapture capture;

public:
  Mat cameraMatrix;
  Mat distCoeffs;
  vector<Mat> rvecs;
  vector<Mat> tvecs;

public:
  Camera(int cameraIndex);
  virtual ~Camera();

  VideoCapture get_capture();

  void correctDistortion(InputArray src, OutputArray dst);

};

#endif /* SRC_CAMERA_H_ */
