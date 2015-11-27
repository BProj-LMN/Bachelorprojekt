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
Mat Punktematrix = Mat::zeros(6,MAXPUNKTE,4); //rows, cols, type - 4 für unsigned int 32 bit (CV_32S)
//int Punktematrix.at<int>(0,0) = 0;
//int KalibrierpunkteX[MAXPUNKTE] = { 0 };  //Punktematrix.at<int>(x,1)
//int KalibrierpunkteY[MAXPUNKTE] = { 0 };  //Punktematrix.at<int>(x,2)
//int KalibrierpunkteZ[MAXPUNKTE] = { 0 };  //Punktematrix.at<int>(x,3)
//int KalibrierpixelX[MAXPUNKTE] = { 0 };   //Punktematrix.at<int>(x,4)
//int KalibrierpixelY[MAXPUNKTE] = { 0 };   //Punktematrix.at<int>(x,5)
bool war_schon = 0;
char Antwortvariable = 0;
int PixelX, PixelY;
bool MauscallbackBekommen = 0;
#define SPEICHERORT "C:/Users/User/Desktop/Punkte.txt"
fstream f;

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

  Punktematrix.at<int>(0,0) = 0; // TODO - Matrix anfangs auf null setzen

  cout << "Wollen Sie neue Kalibrierungspunkte eingeben oder abgespeicherte verwendnen? (n - neu; g - gespeichert)" << endl;
  cin >> Antwortvariable;
  if ('g' == Antwortvariable) { //gespeicherte Werte verwenden //TODO Option nur Weltkoordinaten einlesen und dann klicken
	lesen(cam1);
	lesen(cam2);
	cout << "Wollen Sie auch Weltkoordinaten einlesen oder neue eintippen? (n - neu; g - gespeichert)" << endl;
  	cin >> Antwortvariable;
	if('n' == Antwortvariable){
	  calibrate3Deinzeln(cam1);
	  calibrate3Deinzeln(cam2);
	}
    cout << Punktematrix.at<int>(0,0) << " alte Punkte wurden gefunden" << endl;
  } else {
    cout << "Wie viele Punkte wollen sie eingeben?" << endl; //TODO Maximale Zahl hinzufügen
    cin >> Punktematrix.at<int>(0,0);
    cout << Punktematrix.at<int>(0,0) << " Punkte werden aufgenommen..." << endl;

    for (int i = 0; i < Punktematrix.at<int>(0,0); i++) { //für die Eingabe der Kalibrierpunkte
      cout << "Punkt " << i + 1 << "; Koordinate X: " << endl;
      cin >> Punktematrix.at<int>(1,i);
      cout << "Punkt " << i + 1 << "; Koordinate Y: " << endl;
      cin >> Punktematrix.at<int>(2,i);
      cout << "Punkt " << i + 1 << "; Koordinate Z: " << endl;
      cin >> Punktematrix.at<int>(3,i);
    }

    for (int i = 0; i < Punktematrix.at<int>(0,0); i++) { //für die Ausgabe/Best�tigund der Eingabe
      cout << "Punkt " << i + 1 << "; Koordinate X = " << Punktematrix.at<int>(1,i) << endl;
      cout << "Punkt " << i + 1 << "; Koordinate Y = " << Punktematrix.at<int>(2,i) << endl;
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
    for (int i = 0; i < Punktematrix.at<int>(0,0); i++) { //für die Eingabe der Kalibrierpixel aus dem Bild per Klicken
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
      Punktematrix.at<int>(4,i) = PixelX;
      Punktematrix.at<int>(5,i) = PixelY;
    }
    speichern(KamNr);
	cout << "Kamera" << KamNr << "done" << endl;
	destroyWindow("Kallibild");
}

int speichern(int KamNr) {
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

	  fs.release();                                    // close Settings file

    cout << Punktematrix<<endl;

    return 1;
}

int lesen(Camera* cam) {
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

  fs.release();                                    // close Settings file
  return 1;
}

void KamerabildHolen(VideoCapture *cap, Mat *frame) {
  *cap >> *frame; // get a new frame from camera
  //cvtColor(*frame, *frame, CV_BGR2GRAY);
}

#endif /* SRC_CALIBRATE3D_H_ */
