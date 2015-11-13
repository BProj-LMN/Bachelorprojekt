/*
 * objectDetection.h
 *
 *  Created on: 12.11.2015
 *      Author: Jannik
 */

#ifndef SRC_OBJECTDETECTION_H_
#define SRC_OBJECTDETECTION_H_

#include "Camera.h"

class ObjectDetection {
  Camera* cam;

public:
  ObjectDetection(Camera* cam);
  virtual ~ObjectDetection();
  
  void detectObject(Mat frame, vector<float>* pixelPosition);
};

#endif /* SRC_OBJECTDETECTION_H_ */
