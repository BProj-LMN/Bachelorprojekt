/*
 * objectDetection.cpp
 *
 *  Created on: 12.11.2015
 *      Author: Jannik
 */

#include "ObjectDetection.h"

ObjectDetection::ObjectDetection(Camera* cam) {
  this->cam = cam;

}

ObjectDetection::~ObjectDetection() {

}

void ObjectDetection::detectObject(Mat frame, vector<float>* pixelPosition) {
  // TODO
}
