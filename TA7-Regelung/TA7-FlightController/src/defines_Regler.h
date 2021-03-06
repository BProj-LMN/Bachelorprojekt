/*
 * defines_Regler.h
 *
 * Funktion: globale Konstanten
 *
 * Autor:   Kai Robin Möller
 */

#ifndef DEFINES_REGLER_H
#define	DEFINES_REGLER_H

#define KPXY  0.04              // Regelparameter KP für X und Y Achse
#define KIXY  0.0005            // Regelparameter KI für X und Y Achse
#define KDXY  0.04   //0.173    // Regelparameter KD für X und Y Achse
#define KPZ   0.07              // Regelparameter KP für Z Achse
#define KIZ   0.0012 //0.2      // Regelparameter KI für Z Achse
#define KDZ   0.06   //0.029    // Regelparameter KD für ZAchse
#define REGELMAX        254     // Maximaler Regelwert
#define REGLEROFFSETRL  (-0x0B) // RegelOffset für gößer für Links kleiner für rechts
#define REGLEROFFSETVZ  0x07    // RegelOffset für Vor Zurück
#define REGLEROFFSETD   (-0x12) // RegelOffset für Drehen
#define REGLEROFFSETHR  140     // Regeloffste für Hoch Runter

#endif  /* DEFINES_REGLER_H */
