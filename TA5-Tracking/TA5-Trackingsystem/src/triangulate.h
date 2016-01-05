/*
 * triangulate.h
 *
 * function: Lotfusspunktverfahren zur Bestimmung des Schnittpunktes
 * zweier windschiefer Geraden innerhalb eines globalen Koordinatensystems
 *
 * author: Martin Kroh
 */

#ifndef TRIANGULATE_H_
#define TRIANGULATE_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cstdlib>

#include <opencv2/core.hpp>
using namespace cv;

#define MYEPS 1.0E-19
#define KOORDS 2

void triangulate(Point3f& cam1_p, Point3f& cam1_u, Point3f& cam2_p, Point3f& cam2_u, Point3f& position) {

  /*** Interne Variablen zur Ermittlung des Verbindungsvektors und
   der Elemente des linearen Gleichungssystems ***/
  float K1_vec[3];
  float u_vec[3];
  float K2_vec[3];
  float v_vec[3];

  K1_vec[0] = cam1_p.x;
  K1_vec[1] = cam1_p.y;
  K1_vec[2] = cam1_p.z;
  u_vec[0] = cam1_u.x;
  u_vec[1] = cam1_u.y;
  u_vec[2] = cam1_u.z;
  K2_vec[0] = cam2_p.x;
  K2_vec[1] = cam2_p.y;
  K2_vec[2] = cam2_p.z;
  v_vec[0] = cam2_u.x;
  v_vec[1] = cam2_u.y;
  v_vec[2] = cam2_u.z;

  int i = 0;
  float a[KOORDS + 1][KOORDS + 1];
  float b[KOORDS + 1][KOORDS + 1];
  float x[KOORDS][KOORDS];
  float y[KOORDS];
  float Skalar[KOORDS];
  float Verbindungsvektor[KOORDS + 1];
  float Verbindungsvektor_halbiert[KOORDS + 1];
  float Schnittpunkt[KOORDS + 1];

  /*** Interne Variablen zur Lösung des LGS ***/
  int S0 = 0;
  int S2 = 0;
  int S3 = 0;
  float q;
  float Pivotelement = 0.0;
  int S4 = 0;
  int S5 = 0;
  float Summe;

  /*** Ermittlung des LGS aus Orthogonalitätsbedingungen ***/
  for (i = 0; i <= KOORDS; i++) {
    a[i][0] = (K2_vec[i] - K1_vec[i]) * u_vec[i];
    a[i][1] = v_vec[i] * u_vec[i];
    a[i][2] = (-1) * u_vec[i] * u_vec[i];
    b[i][0] = (K2_vec[i] - K1_vec[i]) * v_vec[i];
    b[i][1] = v_vec[i] * v_vec[i];
    b[i][2] = (-1) * u_vec[i] * v_vec[i];
  }

  /*** 2x2-Matrix und 2x1-Vektor für LGS ***/
  x[0][0] = a[0][1] + a[1][1] + a[2][1];
  x[0][1] = a[0][2] + a[1][2] + a[2][2];
  x[1][0] = b[0][1] + b[1][1] + b[2][1];
  x[1][1] = b[0][2] + b[1][2] + b[2][2];
  y[0] = -(a[0][0] + a[1][0] + a[2][0]);
  y[1] = -(b[0][0] + b[1][0] + b[2][0]);

  /*** Vorwärts eliminieren ***/
  for (S0 = 0; S0 < (KOORDS - 1); S0++) {
    Pivotelement = x[S0][S0];
    for (S2 = 1; S2 < (KOORDS - S0); S2++) {
      q = ((x[(S2 + S0)][S0] / Pivotelement) * (-1));
      for (S3 = 0; S3 < (KOORDS - S0); S3++) {
        x[(S0 + S2)][(S0 + S3)] = ((x[S0][(S0 + S3)] * q) + x[S0 + S2][(S0 + S3)]);
      };
      y[S0 + S2] = ((y[S0] * q) + y[S0 + S2]);
    }
  }

  /*** Rückwärts einsetzten ***/
  for (S4 = (KOORDS - 1); S4 >= 0; S4--) {
    Summe = 0;
    for (S5 = (S4 + 1); S5 <= (KOORDS - 1); S5++) {
      Summe = Summe + (x[S4][S5]) * Skalar[S5];
    }
    Skalar[S4] = ((y[S4]) - Summe) / x[S4][S4];
  }

  /*** Berechnung des Verbindungsvektors ***/
  for (i = 0; i <= KOORDS; i++) {
    Verbindungsvektor[i] = (K2_vec[i] - K1_vec[i]) + v_vec[i] * Skalar[0] - u_vec[i] * Skalar[1];
  }

  /*** Halbierung des Verbindungsvektors ***/
  for (i = 0; i <= KOORDS; i++) {
    Verbindungsvektor_halbiert[i] = 0.5 * Verbindungsvektor[i];
  }

  /*** Berechnung des Schnittpunktes im globalen Koordinatensystem ***/
  for (i = 0; i <= KOORDS; i++) {
    Schnittpunkt[i] = K1_vec[i] + Skalar[1] * u_vec[i] + Verbindungsvektor_halbiert[i];
  }

  position.x = Schnittpunkt[0];
  position.y = Schnittpunkt[1];
  position.z = Schnittpunkt[2];
}

#endif /* TRIANGULATE_H_ */
