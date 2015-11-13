/*
 * calibrate3D.h
 *
 *  Created on: 12.11.2015
 *      Author: Daniel
 */

#ifndef SRC_CALIBRATE3D_H_
#define SRC_CALIBRATE3D_H_

#include "Camera.h"

using namespace cv;


void calibrate3D(Camera* cam1, Camera* cam2); // calibrate camera pair


#endif /* SRC_CALIBRATE3D_H_ */
