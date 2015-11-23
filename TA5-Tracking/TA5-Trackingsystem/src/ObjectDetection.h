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
#include "globalConstants.h"

class ObjectDetection {
  Camera* cam;
  Mat refereceFrame;

public:
  ObjectDetection(Camera* cam);
  virtual ~ObjectDetection();
  
  void setReferenceFrame(Mat frame);
  void detectObject(Mat frame, int pixelPosition[2]);

private:
  int getObjectPosition(Mat thresholdImage, int objectPosition[2], Rect* boundingRectangle);
};

#endif /* SRC_OBJECTDETECTION_H_ */
