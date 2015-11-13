
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
using namespace cv;

#include <iostream>
using namespace std;

#include "Camera.h"
#include "calibrate3D.h"
#include "calibrateCamera.h"
#include "ObjectDetection.h"


int main() {

  Camera cam1(0);
  VideoCapture cap = cam1.get_capture();





  return 0;

}
