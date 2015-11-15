/*
 * calibrateCamera.cpp
 *
 * function: calibrate distCoeffs of camera
 *
 * author: Jannik Beyerstedt
 * modified from: http://docs.opencv.org/2.4/doc/tutorials/calib3d/camera_calibration/camera_calibration.html
 *
 * TODO: ordentliches Beenden der Subroutine
 * TODO: prüfen, ob cameraMatrix und distCoeffs ordentlich abgespeichert werden
 */

#ifndef SRC_CALIBRATECAMERA_H_
#define SRC_CALIBRATECAMERA_H_

#include <iostream>
#include <sstream>
#include <time.h>
#include <stdio.h>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>

#ifndef _CRT_SECURE_NO_WARNINGS
# define _CRT_SECURE_NO_WARNINGS
#endif

using namespace cv;
using namespace std;

#include "calibrateCamera_Helpers.h"
#include "calibrateCamera_Settings.h"

enum {
  DETECTION = 0, CAPTURING = 1, CALIBRATED = 2
};

static void help() {
  cout << "Hi, this is the distortion correction subroutine" << endl;
}

int calibrateCamera(string inputFile, Mat& cameraMatrix, Mat& distCoeffs) {
  help();
  Settings s;
  const string inputSettingsFile = inputFile;
  FileStorage fs(inputSettingsFile, FileStorage::READ); // Read the settings
  if (!fs.isOpened()) {
    cout << "Could not open the configuration file: \"" << inputSettingsFile << "\"" << endl;
    return -1;
  }
  fs["Settings"] >> s;
  fs.release();                                         // close Settings file

  if (!s.goodInput) {
    cout << "Invalid input detected. Application stopping. " << endl;
    return -1;
  }

  vector<vector<Point2f> > imagePoints;
  //Mat cameraMatrix, distCoeffs;
  Size imageSize;
  int mode = s.inputType == Settings::IMAGE_LIST ? CAPTURING : DETECTION;
  clock_t prevTimestamp = 0;
  const Scalar RED(0, 0, 255), GREEN(0, 255, 0);
  const char ESC_KEY = 27;

  for (int i = 0;; ++i) {
    Mat view;
    bool blinkOutput = false;

    view = s.nextImage();

    //-----  If no more image, or got enough, then stop calibration and show result -------------
    if (mode == CAPTURING && imagePoints.size() >= (unsigned) s.nrFrames) {
      if (runCalibrationAndSave(s, imageSize, cameraMatrix, distCoeffs, imagePoints)) {
        mode = CALIBRATED;
      } else {
        mode = DETECTION;
      }
    }
    if (view.empty()) {         // If no more images then run calibration, save and stop loop.
      if (imagePoints.size() > 0) {
        runCalibrationAndSave(s, imageSize, cameraMatrix, distCoeffs, imagePoints);
      }
      break;
    }

    imageSize = view.size();  // Format input image.
    if (s.flipVertical) {
      flip(view, view, 0);
    }

    vector<Point2f> pointBuf;

    bool found;
    switch (s.calibrationPattern) // Find feature points on the input format
    {
      case Settings::CHESSBOARD:
        found = findChessboardCorners(view, s.boardSize, pointBuf,
        CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FAST_CHECK | CV_CALIB_CB_NORMALIZE_IMAGE);
        break;
      case Settings::CIRCLES_GRID:
        found = findCirclesGrid(view, s.boardSize, pointBuf);
        break;
      case Settings::ASYMMETRIC_CIRCLES_GRID:
        found = findCirclesGrid(view, s.boardSize, pointBuf, CALIB_CB_ASYMMETRIC_GRID);
        break;
      default:
        found = false;
        break;
    }

    if (found) {               // If done with success,
      // improve the found corners' coordinate accuracy for chessboard
      if (s.calibrationPattern == Settings::CHESSBOARD) {
        Mat viewGray;
        cvtColor(view, viewGray, COLOR_BGR2GRAY);
        cornerSubPix(viewGray, pointBuf, Size(11, 11), Size(-1, -1),
                     TermCriteria( CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 30, 0.1));
      }

      if (mode == CAPTURING &&  // For camera only take new samples after delay time
      (!s.inputCapture.isOpened() || clock() - prevTimestamp > s.delay * 1e-3 * CLOCKS_PER_SEC)) {
        imagePoints.push_back(pointBuf);
        prevTimestamp = clock();
        blinkOutput = s.inputCapture.isOpened();
      }

      // Draw the corners.
      drawChessboardCorners(view, s.boardSize, Mat(pointBuf), found);
    }

    //----------------------------- Output Text ------------------------------------------------
    string msg = (mode == CAPTURING) ? "100/100" : mode == CALIBRATED ? "Calibrated" : "Press 'g' to start";
    int baseLine = 0;
    Size textSize = getTextSize(msg, 1, 1, 1, &baseLine);
    Point textOrigin(view.cols - 2 * textSize.width - 10, view.rows - 2 * baseLine - 10);

    if (mode == CAPTURING) {
      if (s.showUndistorsed)
        msg = format("%d/%d Undist", (int) imagePoints.size(), s.nrFrames);
      else
        msg = format("%d/%d", (int) imagePoints.size(), s.nrFrames);
    }

    putText(view, msg, textOrigin, 1, 1, mode == CALIBRATED ? GREEN : RED);

    if (blinkOutput)
      bitwise_not(view, view);

    //------------------------- Video capture  output  undistorted ------------------------------
    if (mode == CALIBRATED && s.showUndistorsed) {
      Mat temp = view.clone();
      undistort(temp, view, cameraMatrix, distCoeffs);
    }

    //------------------------------ Show image and check for input commands -------------------
    imshow("Image View", view);
    char key = (char) waitKey(s.inputCapture.isOpened() ? 50 : s.delay);

    if (key == ESC_KEY)
      break;

    if (key == 'u' && mode == CALIBRATED)
      s.showUndistorsed = !s.showUndistorsed;

    if (s.inputCapture.isOpened() && key == 'g') {
      mode = CAPTURING;
      imagePoints.clear();
    }
  }

  // -----------------------Show the undistorted image for the image list ------------------------
  if (s.inputType == Settings::IMAGE_LIST && s.showUndistorsed) {
    Mat view, rview, map1, map2;
    initUndistortRectifyMap(cameraMatrix, distCoeffs, Mat(),
                            getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, imageSize, 1, imageSize, 0), imageSize,
                            CV_16SC2,
                            map1, map2);

    for (int i = 0; i < (int) s.imageList.size(); i++) {
      view = imread(s.imageList[i], 1);
      if (view.empty())
        continue;
      remap(view, rview, map1, map2, INTER_LINEAR);
      imshow("Image View", rview);
      char c = (char) waitKey();
      if (c == ESC_KEY || c == 'q' || c == 'Q')
        destroyWindow("Image View");
        break;
    }
  }

  return 0;
}

#endif /* SRC_CALIBRATECAMERA_H_ */

