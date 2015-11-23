/*
 * objectDetection.cpp
 *
 * function: detect object in an image
 *
 * author: Jannik Beyerstedt
 */

#include "ObjectDetection.h"

const static int SENSITIVITY_VALUE = 35;  // threshold for theshold()
const static int BLUR_SIZE = 10;  // for absdiff()

ObjectDetection::ObjectDetection(Camera* cam) {
  this->cam = cam;

}

ObjectDetection::~ObjectDetection() {

}

void ObjectDetection::setReferenceFrame(Mat frame) {
  this->refereceFrame = frame;
}
/*
 * input:  grayscale frame
 * output: int array with detected position {x, y}
 */
void ObjectDetection::detectObject(Mat frame, int pixelPosition[2]) {
  // TODO: only copy-pasted the code --> check integration !!!

  Mat diffImage, thresholdImage;
  Rect objectBounding = Rect(0, 0, 0, 0);

  // subtract background and create binary mask
  absdiff(refereceFrame, frame, diffImage); // output: grayscale
  threshold(diffImage, thresholdImage, SENSITIVITY_VALUE, 255, THRESH_BINARY); // output: binary

  // blur and threshold again to get rid of noise
  blur(thresholdImage, thresholdImage, cv::Size(BLUR_SIZE, BLUR_SIZE)); // output: grayscale
  threshold(thresholdImage, thresholdImage, SENSITIVITY_VALUE, 255, THRESH_BINARY); // output: binary

  int error = getObjectPosition(thresholdImage, pixelPosition, &objectBounding);

  if (0 == error) {
    int xpos = pixelPosition[0];
    int ypos = pixelPosition[1];
    circle(frame, Point(xpos, ypos), 30, Scalar(255, 0, 0), 1);

    rectangle(frame, objectBounding, Scalar(0, 255, 0), 2);

    imshow("final tracking", frame);
  }

}

int ObjectDetection::getObjectPosition(Mat thresholdImage, int objectPosition[2], Rect* boundingRectangle) {

  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  findContours(thresholdImage, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE); // retrieves external contours

  // TODO: merge the two nearby contours ! - with erode and dilate !?

  // if contours vector is empty, we have found no objects
  if (contours.size() == 0) {
    return ERROR;
  } else {
    // the largest contour is found at the end of the contours vector
    // we will simply assume that the biggest contour is the object we are looking for.
    vector<vector<Point> > largestContourVec;
    largestContourVec.push_back(contours.at(contours.size() - 1));

    // make a bounding rectangle around the largest contour then find its centroid
    // this will be the object's final estimated position.
    *boundingRectangle = boundingRect(largestContourVec.at(0));

    int xpos = boundingRectangle->x + boundingRectangle->width / 2;
    int ypos = boundingRectangle->y + boundingRectangle->height / 2;

    objectPosition[0] = xpos, objectPosition[1] = ypos;

    return OK;
  }

}
