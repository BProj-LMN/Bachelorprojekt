/*
 * frameMask.h
 *
 * function: set the camera frameMask
 *
 * author: Daniel Friedrich
 */

#include "Camera.h"
using namespace cv;

void roiMouseCallBackFunc(int event, int x, int y, int flags, void* userdata) {
  if (event == EVENT_LBUTTONDOWN) {
    cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    MauscallbackBekommen = 1;
    PixelX = x;
    PixelY = y;
  }
}

void executeSetFrameMask(Camera* cam) {
  Mat Pixelgesammelt = Mat::zeros(4, 2, CV_32S);
  Mat ROIBild;
  VideoCapture cap = cam->get_capture();
  namedWindow("ROIBild", 1);
  for (int i = 0; i < 4; i++) { //für die Eingabe der Pixel aus dem Bild per Klicken
    cout << "Bitte Punkt " << i + 1 << " im Bild anklicken (1-links, 2-rechts, 3-oben, 4-unten)" << endl;
    MauscallbackBekommen = 0;
    setMouseCallback("ROIBild", roiMouseCallBackFunc, NULL);
    while (0 == MauscallbackBekommen) {
      cam->get_newFrame(ROIBild);
      //flip(ROIBild, ROIBild, 0);
      //flip(ROIBild, ROIBild, 1);
      imshow("ROIBild", ROIBild);
      if (waitKey(30) >= 0) {
        break;
      }
    }
    Pixelgesammelt.at<int>(i, 0) = PixelX;
    Pixelgesammelt.at<int>(i, 1) = PixelY;
  }

  Rect frameMask = Rect(Pixelgesammelt.at<int>(0, 0), Pixelgesammelt.at<int>(2, 1),
                        (Pixelgesammelt.at<int>(1, 0) - Pixelgesammelt.at<int>(0, 0)),
                        (Pixelgesammelt.at<int>(3, 1) - Pixelgesammelt.at<int>(2, 1)));
  cam->set_frameMask(frameMask);

  destroyWindow("ROIBild");
}

void calibrateFrameMask(Camera* cam1, Camera* cam2) {
  executeSetFrameMask(cam1);
  executeSetFrameMask(cam2);

  cout << "frameMask set" << endl;
}

