/*
 * calibrate3D.h
 *
 * function: calibrate position of cameras in world coordinates
 *
 * author: Daniel Friedrich
 */

#ifndef SRC_CALIBRATE3D_H_
#define SRC_CALIBRATE3D_H_

#define MAXPUNKTE 30
#define MY_FILENAME "3DPointsandPixelKam-"

#include <fstream>
#include <string>
using namespace cv;

#include "Camera.h"
#include "myGlobalConstants.h"

void calibrate3Deinzeln(Camera* cam);
void calibrate3D(Camera* cam1, Camera* cam2); // calibrate camera pair
void KamerabildHolen(VideoCapture *cap, Mat *frame);
void myMouseCallBackFunc(int event, int x, int y, int flags, void* userdata);
int speichern(int KamNr);
int lesen(Camera* cam);

int x = 0;
int KalibrierpunkteAnzahl = 0;
int KalibrierpunkteX[MAXPUNKTE] = { 0 };
int KalibrierpunkteY[MAXPUNKTE] = { 0 };
int KalibrierpixelX[MAXPUNKTE] = { 0 };
int KalibrierpixelY[MAXPUNKTE] = { 0 };
bool war_schon = 0;
char Antwortvariable = 0;
int PixelX, PixelY;
bool MauscallbackBekommen = 0;
#define SPEICHERORT "C:/Users/User/Desktop/Punkte.txt"
fstream f;
//FILE *CSV; //TODO kann wahrscheinlich weg

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

  cout << "Wollen Sie neue Kalibrierungspunkte eingeben oder abgespeicherte verwendnen? (n - neu; g - gespeichert)" << endl;
  cin >> Antwortvariable;
  if ('g' == Antwortvariable) { //gespeicherte Werte verwenden //TODO Option nur Weltkoordinaten einlesen und dann klicken
	lesen(cam1);
	lesen(cam2);
    cout << KalibrierpunkteAnzahl << " alte Punkte wurden gefunden" << endl;
  } else {
    cout << "Wie viele Punkte wollen sie eingeben?" << endl; //TODO Maximale Zahl hinzufügen
    cin >> KalibrierpunkteAnzahl;
    cout << KalibrierpunkteAnzahl << " Punkte werden aufgenommen..." << endl;

    for (int i = 0; i < KalibrierpunkteAnzahl; i++) { //für die Eingabe der Kalibrierpunkte
      cout << "Punkt " << i + 1 << "; Koordinate X: " << endl;
      cin >> KalibrierpunkteX[i];
      cout << "Punkt " << i + 1 << "; Koordinate Y: " << endl;
      cin >> KalibrierpunkteY[i];
    }

    for (int i = 0; i < KalibrierpunkteAnzahl; i++) { //für die Ausgabe/Best�tigund der Eingabe
      cout << "Punkt " << i + 1 << "; Koordinate X = " << KalibrierpunkteX[i] << endl;
      cout << "Punkt " << i + 1 << "; Koordinate Y = " << KalibrierpunkteY[i] << endl;
    }
    calibrate3Deinzeln(cam1);
    calibrate3Deinzeln(cam2);
  }
  cout << "Kalibrierung beendet" << endl;
}

void calibrate3Deinzeln(Camera* cam) {
	Mat Kalliframe;
	int KamNr = cam->getID();
	VideoCapture cap = cam->get_capture();
    namedWindow("Kallibild", 1);
    for (int i = 0; i < KalibrierpunkteAnzahl; i++) { //für die Eingabe der Kalibrierpixel aus dem Bild per Klicken
      cout << "Bitte Punkt " << i + 1 << " im Bild anklicken" << endl;
      MauscallbackBekommen = 0;
      setMouseCallback("Kallibild", myMouseCallBackFunc, NULL);
      while (0 == MauscallbackBekommen) {

        KamerabildHolen(&cap, &Kalliframe);
        flip(Kalliframe, Kalliframe, 0);
        flip(Kalliframe, Kalliframe, 1);
        imshow("Kallibild", Kalliframe);
        if (waitKey(30) >= 0)
          break;
      }
      KalibrierpixelX[i] = PixelX;
      KalibrierpixelY[i] = PixelY;
    }
    speichern(KamNr);
	cout << "Kamera" << KamNr << "done" << endl;
	destroyWindow("Kallibild");
}

int speichern(int KamNr) {
	  stringstream pfad;
	  pfad << MY_FILENAME << KamNr;
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

	  fs << "KalibrierpunkteAnzahl" << KalibrierpunkteAnzahl;
	  fs << "KalibrierpunkteX" << KalibrierpunkteX;
	  fs << "KalibrierpunkteY" << KalibrierpunkteY;
	  fs << "KalibrierpixelX" << KalibrierpixelX;
	  fs << "KalibrierpixelY" << KalibrierpixelY;

	  fs.release();                                    // close Settings file
    return 1;
}

int lesen(Camera* cam) {
  int KamNr = cam->getID();
  stringstream pfad;
  pfad << MY_FILENAME << KamNr;
  string settingsFilename = pfad.str();

  FileStorage fs(settingsFilename, FileStorage::READ); // Read the settings
  if (!fs.isOpened()) {
    cout << "Could not open the configuration file: \"" << settingsFilename << "\"" << endl;
    return -1;
  }

  fs["KalibrierpunkteAnzahl"] >> KalibrierpunkteAnzahl;
  fs["KalibrierpunkteX"] >> KalibrierpunkteX;
  fs["KalibrierpunkteY"] >> KalibrierpunkteY;
  fs["KalibrierpixelX"] >> KalibrierpixelX;
  fs["KalibrierpixelY"] >> KalibrierpixelY;

  fs.release();                                    // close Settings file
  return 1;
}

void KamerabildHolen(VideoCapture *cap, Mat *frame) {
  *cap >> *frame; // get a new frame from camera
  //cvtColor(*frame, *frame, CV_BGR2GRAY);
}

#endif /* SRC_CALIBRATE3D_H_ */
