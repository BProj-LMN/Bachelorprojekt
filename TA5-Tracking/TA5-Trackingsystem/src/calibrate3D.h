/*
 * calibrate3D.h
 *
 * function: calibrate position of cameras in world coordinates
 *
 * author: Daniel Friedrich
 */

#ifndef SRC_CALIBRATE3D_H_
#define SRC_CALIBRATE3D_H_

#define MAXPUNKTE 20

#include <fstream>
#include <string>
using namespace cv;

#include "Camera.h"
#include "myGlobalConstants.h"

void calibrate3D(Camera* cam1, Camera* cam2); // calibrate camera pair
void KamerabildHolen(VideoCapture *cap, Mat *frame);
void myMouseCallBackFunc(int event, int x, int y, int flags, void* userdata);
void speichern(void);

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
  VideoCapture cap = cam1->get_capture();
  Mat Kalliframe;
  cout << "Wollen Sie neue Kalibrierungspunkte eingeben oder abgespeicherte verwendnen? (n - neu; g - gespeichert)"
       << endl;
  cin >> Antwortvariable;
  if ('g' == Antwortvariable) { //gespeicherte Werte verwenden
    //TODO speicherung der Werte und Aufrufung
    cout << x << " alte Punkte wurden gefunden" << endl;
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
    speichern();
  }
  destroyWindow("Kallibild");
  cout << "Kalibrierung beendet" << endl;
}

void speichern(void) {
  f.open(SPEICHERORT, ios::out);
  for (int i = 0; i < MAXPUNKTE; i++) {
    f << KalibrierpixelX[i] << ";";
  }
  f << endl;
  for (int i = 0; i < MAXPUNKTE; i++) {
    f << KalibrierpixelY[i] << ";";
  }
  f << endl;
  for (int i = 0; i < MAXPUNKTE; i++) {
    f << KalibrierpunkteX[i] << ";";
  }
  f << endl;
  for (int i = 0; i < MAXPUNKTE; i++) {
    f << KalibrierpunkteY[i] << ";";
  }
  f.close();
}

void lesen(void) {
  f.open(SPEICHERORT, ios::in);

  /*for (int i = 0; i < MAXPUNKTE; i++) {
    f >> KalibrierpixelX[i] >> ";";
  }
  f >> endl;
  for (int i = 0; i < MAXPUNKTE; i++) {
    f >> KalibrierpixelY[i] >> ";";
  }
  f >> endl;
  for (int i = 0; i < MAXPUNKTE; i++) {
    f >> KalibrierpunkteX[i] >> ";";
  }
  f >> endl;
  for (int i = 0; i < MAXPUNKTE; i++) {
    f >> KalibrierpunkteY[i] >> ";";
  }*/
  f.close();
}

void KamerabildHolen(VideoCapture *cap, Mat *frame) {
  *cap >> *frame; // get a new frame from camera
  //cvtColor(*frame, *frame, CV_BGR2GRAY);
}

#endif /* SRC_CALIBRATE3D_H_ */
