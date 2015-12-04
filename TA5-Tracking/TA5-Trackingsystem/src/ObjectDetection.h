/*
 * objectDetection.h
 *
 * function: detect object in an image
 *
 * author: Jannik Beyerstedt
 */

#ifndef SRC_OBJECTDETECTION_H_
#define SRC_OBJECTDETECTION_H_

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;

#include "Camera.h"
#include "myGlobalConstants.h"

class ObjectDetection {
  Camera* cam;
  Mat refereceFrame;

public:
  ObjectDetection(Camera* cam);
  virtual ~ObjectDetection();
  
  int setReferenceFrame(Mat frame);
  int detectObject(Mat frame, int pixelPosition[2]);

private:
  int getObjectPosition(Mat thresImg, int objectPos[2], Rect* boundingRect);
};

#endif /* SRC_OBJECTDETECTION_H_ */
