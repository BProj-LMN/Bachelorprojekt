/*
 * calibrateCamera_Settings.cpp
 *
 *  Created on: 15.11.2015
 *      Author: jannik
 */

#include "calibrateCamera_Settings.h"

void DistCalibSettings::read(const FileNode& node) {     //Read serialization for this class
  node["BoardSize_Width"] >> boardSize.width;
  node["BoardSize_Height"] >> boardSize.height;
  node["Calibrate_Pattern"] >> patternToUse;
  node["Square_Size"] >> squareSize;
  node["Calibrate_NrOfFrameToUse"] >> nrFrames;
  node["Calibrate_FixAspectRatio"] >> aspectRatio;
  node["Write_DetectedFeaturePoints"] >> bwritePoints;
  node["Write_extrinsicParameters"] >> bwriteExtrinsics;
  node["Write_outputFileName"] >> outputFileName;
  node["Calibrate_AssumeZeroTangentialDistortion"] >> calibZeroTangentDist;
  node["Calibrate_FixPrincipalPointAtTheCenter"] >> calibFixPrincipalPoint;
  node["Input_FlipAroundHorizontalAxis"] >> flipVertical;
  node["Show_UndistortedImage"] >> showUndistorsed;
  node["Input_Delay"] >> delay;
  interprate();
}

void DistCalibSettings::interprate() {
  goodInput = true;
  if (boardSize.width <= 0 || boardSize.height <= 0) {
    cerr << "Invalid Board size: " << boardSize.width << " " << boardSize.height << endl;
    goodInput = false;
  }
  if (squareSize <= 10e-6) {
    cerr << "Invalid square size " << squareSize << endl;
    goodInput = false;
  }
  if (nrFrames <= 0) {
    cerr << "Invalid number of frames " << nrFrames << endl;
    goodInput = false;
  }

  flag = 0;
  if (calibFixPrincipalPoint)
    flag |= CV_CALIB_FIX_PRINCIPAL_POINT;
  if (calibZeroTangentDist)
    flag |= CV_CALIB_ZERO_TANGENT_DIST;
  if (aspectRatio)
    flag |= CV_CALIB_FIX_ASPECT_RATIO;

  calibrationPattern = NOT_EXISTING;
  if (!patternToUse.compare("CHESSBOARD")) {
    calibrationPattern = CHESSBOARD;
  }
  if (!patternToUse.compare("CIRCLES_GRID")) {
    calibrationPattern = CIRCLES_GRID;
  }
  if (!patternToUse.compare("ASYMMETRIC_CIRCLES_GRID")) {
    calibrationPattern = ASYMMETRIC_CIRCLES_GRID;
  }
  if (calibrationPattern == NOT_EXISTING) {
    cerr << " Inexistent camera calibration mode: " << patternToUse << endl;
    goodInput = false;
  }

}

Mat DistCalibSettings::nextImage() {
  Mat result;
  if (inputCapture.isOpened()) {
    Mat view0;
    inputCapture >> view0;
    view0.copyTo(result);
  }
  return result;
}
