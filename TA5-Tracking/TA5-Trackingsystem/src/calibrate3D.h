/*
 * calibrate3D.h
 *
 * function: calibrate position of cameras in world coordinates
 *
 * author: Daniel Friedrich
 */

#ifndef SRC_CALIBRATE3D_H_
#define SRC_CALIBRATE3D_H_

#define PUNKTE 20
#define MY_FILENAME "3DPointsandPixelKam-"

#include <fstream>
#include <string>
using namespace cv;

#include "Camera.h"
#include <opencv2/calib3d/calib3d.hpp>
#include "myGlobalConstants.h"

void calibrate3Deinzeln(Camera* cam, Mat Pixelmatrix);
void KamerabildHolen(VideoCapture *cap, Mat *frame);
void myMouseCallBackFunc(int event, int x, int y, int flags, void* userdata);
int speichern(int KamNr, Mat Pixelmatrix);
int lesen(Camera* cam, Mat Pixelmatrix);
void gleichungRechnenEinzeln(Camera* cam, Mat Pixelmatrix);

int x = 0;
/*
 Zettelwerte 1 - 15 X Y Z (X1 Y1 Z1 X2 Y2 Z2 X3 Y3 Z3 X.....)
 x y  z   x y   z   x y   z   x y  z   x y   z   x y   z   x y  z
 0 37 248 0 151 232 0 287 226 0 63 155 0 170 171 0 254 149 0 27 78
 x y   z  x y   z  x  y z   x   y z   x   y z  x   y z  x   y z   x   y z
 0 153 37 0 308 46 68 0 193 177 0 121 371 0 80 100 0 28 209 0 250 344 0 212

 Klötzchenwerte 1 - 5 X Y Z (X1 Y1 Z1 X2 Y2 Z2 X3 Y3 Z3 X.....)
 x   y   z   x   y   z   x   y   z  x   y   z   x   y   z
 605 233 175 465 112 168 364 112 81 225 233 115 134 112 131
 */

Mat Punktematrix = Mat::zeros(1, 1, 4); //rows, cols, type - 4 für unsigned int 32 bit (CV_32S)
Mat PunktematrixXYZ = Mat::zeros(PUNKTE, 3, CV_32F); //rows, cols, type
bool war_schon = 0;
char Antwortvariable = 0;
int PixelX, PixelY;
bool MauscallbackBekommen = 0;
#define SPEICHERORT "C:/Users/User/Desktop/Punkte.txt"

void myMouseCallBackFunc(int event, int x, int y, int flags, void* userdata) {

  if (event == EVENT_LBUTTONDOWN) {
    cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    MauscallbackBekommen = 1;
    PixelX = x;
    PixelY = y;
//     } else if  ( event == EVENT_RBUTTONDOWN ) {
//          cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
//     } else if  ( event == EVENT_MBUTTONDOWN ) {
//          cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
//     } else if ( event == EVENT_MOUSEMOVE ) {
//          cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
  }
}

void calibrate3D(Camera* cam1, Camera* cam2) {

  if (cam1->intrinsicParamsLoaded == 1 && cam2->intrinsicParamsLoaded == 1) {
    Punktematrix.at<int>(0, 0) = PUNKTE;
    Mat Pixelmatrix1 = Mat::zeros(PUNKTE, 2, CV_32S); //rows, cols, type - 4 für unsigned int 32 bit (CV_32S)
    Mat Pixelmatrix2 = Mat::zeros(PUNKTE, 2, CV_32S); //rows, cols, type - 4 für unsigned int 32 bit (CV_32S)

    cout << "Wollen Sie neue Kalibrierungspunkte eingeben oder abgespeicherte verwendnen? (n - neu; g - gespeichert)"
         << endl;
    cin >> Antwortvariable;
    if ('g' == Antwortvariable) { //gespeicherte Werte verwenden
      lesen(cam1, Pixelmatrix1);
      lesen(cam2, Pixelmatrix2);
      cout << "Punktematrix: " << Punktematrix << endl;
      cout << "PunktematrixXYZ: " << PunktematrixXYZ << endl;
      cout << "Pixelmatrix1: " << Pixelmatrix1 << endl;
      cout << "Pixelmatrix2: " << Pixelmatrix2 << endl;
      cout << "Wollen Sie auch Weltkoordinaten einlesen oder neue eintippen? (n - neu; g - gespeichert)" << endl;
      cin >> Antwortvariable;
      if ('n' == Antwortvariable) {
        calibrate3Deinzeln(cam1, Pixelmatrix1);
        calibrate3Deinzeln(cam2, Pixelmatrix2);
      }
      cout << Punktematrix.at<int>(0, 0) << " alte Punkte wurden gefunden" << endl;
    } else {

      for (int i = 0; i < PUNKTE; i++) { //für die Eingabe der Kalibrierpunkte
        cout << "Punkt " << i + 1 << "; Koordinate X: " << endl;
        cin >> PunktematrixXYZ.at<int>(i, 0);
        cout << "Punkt " << i + 1 << "; Koordinate Y: " << endl;
        cin >> PunktematrixXYZ.at<int>(i, 1);
        cout << "Punkt " << i + 1 << "; Koordinate Z: " << endl;
        cin >> PunktematrixXYZ.at<int>(i, 2);
      }

      for (int i = 0; i < PUNKTE; i++) { //für die Ausgabe/Best�tigund der Eingabe
        cout << "Punkt " << i + 1 << "; Koordinate X = " << PunktematrixXYZ.at<int>(i, 0) << endl;
        cout << "Punkt " << i + 1 << "; Koordinate Y = " << PunktematrixXYZ.at<int>(i, 1) << endl;
        cout << "Punkt " << i + 1 << "; Koordinate Z = " << PunktematrixXYZ.at<int>(i, 2) << endl;
      }
      calibrate3Deinzeln(cam1, Pixelmatrix1);
      calibrate3Deinzeln(cam2, Pixelmatrix2);
    }
    gleichungRechnenEinzeln(cam1, Pixelmatrix1);
    gleichungRechnenEinzeln(cam2, Pixelmatrix2);
    cout << "Kalibrierung beendet" << endl;
  } else {
    cout
        << "Kalibrierung konnte nicht abgeschlossen werden \nBitte erst Funktion \"calibrateCamera\" oder \"loadConfig\" aufrufen"
        << endl;
  }
}

void gleichungRechnenEinzeln(Camera* cam, Mat Pixelmatrix) {

  vector<Point3f> Weltvektor;
  vector<Point2f> Pixelvektor;

  Weltvektor.resize(PUNKTE);
  Pixelvektor.resize(PUNKTE);

  for (int i = 0; i < PUNKTE; i++) {
    Weltvektor[i] = cv::Point3f(PunktematrixXYZ.at<int>(i, 0), PunktematrixXYZ.at<int>(i, 1),
                                PunktematrixXYZ.at<int>(i, 2)); //TODO - Hexenwerk - warum Spaltenvektor?!?
    Pixelvektor[i] = cv::Point2f(Pixelmatrix.at<int>(i, 0), Pixelmatrix.at<int>(i, 1));
  }

  cout << "Weltvektor" << Weltvektor << endl;
  cout << "Pixelvektor" << Pixelvektor << endl;

  solvePnP(Weltvektor, Pixelvektor, cam->cameraMatrix, cam->distCoeffs, cam->rvecs, cam->tvecs, false,
           SOLVEPNP_ITERATIVE);

  cout << "tvec" << cam->tvecs << endl;
  cout << "rvec" << cam->rvecs << endl;

}

void calibrate3Deinzeln(Camera* cam, Mat Pixelmatrix) {

  Mat Kalliframe;
  int KamNr = cam->getID();
  VideoCapture cap = cam->get_capture();
  namedWindow("Kallibild", 1);
  for (int i = 0; i < PUNKTE; i++) { //für die Eingabe der Kalibrierpixel aus dem Bild per Klicken
    cout << "Bitte Punkt " << i + 1 << " im Bild anklicken" << endl;
    MauscallbackBekommen = 0;
    setMouseCallback("Kallibild", myMouseCallBackFunc, NULL);
    while (0 == MauscallbackBekommen) {

      KamerabildHolen(&cap, &Kalliframe);
      imshow("Kallibild", Kalliframe);
      if (waitKey(30) >= 0)
        break;
    }
    Pixelmatrix.at<int>(i, 0) = PixelX;
    Pixelmatrix.at<int>(i, 1) = PixelY;
  }
  speichern(KamNr, Pixelmatrix);
  cout << "Kamera" << KamNr << "done" << endl;
  destroyWindow("Kallibild");
}

int speichern(int KamNr, Mat Pixelmatrix) {
  stringstream pfad;
  pfad << MY_FILENAME << KamNr << ".xml";
  string settingsFilename = pfad.str();

  FileStorage fs(settingsFilename, FileStorage::WRITE); // Read the settings
  if (!fs.isOpened()) {
    cout << "Could not open the configuration file: \"" << settingsFilename << "\"" << endl;
    return -1;
  }

  time_t tm;
  time(&tm);
  struct tm *t2 = localtime(&tm);
  fs << "timestamp" << (int) tm;
  char buf[1024];
  strftime(buf, sizeof(buf) - 1, "%c", t2);
  fs << "datetime" << buf;

  fs << "Punktematrix" << Punktematrix;
  fs << "PunktematrixXYZ" << PunktematrixXYZ;
  fs << "Pixelmatrix" << Pixelmatrix;

  fs.release();                                    // close Settings file

  cout << Punktematrix << endl;
  cout << PunktematrixXYZ << endl;
  cout << Pixelmatrix << endl;

  return 1;
}

int lesen(Camera* cam, Mat Pixelmatrix) {
  int KamNr = cam->getID();
  stringstream pfad;
  pfad << MY_FILENAME << KamNr << ".xml";
  string settingsFilename = pfad.str();

  FileStorage fs(settingsFilename, FileStorage::READ); // Read the settings
  if (!fs.isOpened()) {
    cout << "Could not open the configuration file: \"" << settingsFilename << "\"" << endl;
    return -1;
  }

  fs["Punktematrix"] >> Punktematrix;
  fs["PunktematrixXYZ"] >> PunktematrixXYZ;
  fs["Pixelmatrix"] >> Pixelmatrix;

  fs.release();                                    // close Settings file
  return 1;
}

void KamerabildHolen(VideoCapture *cap, Mat *frame) {
  *cap >> *frame; // get a new frame from camera
  //cvtColor(*frame, *frame, CV_BGR2GRAY);
}

#endif /* SRC_CALIBRATE3D_H_ */
