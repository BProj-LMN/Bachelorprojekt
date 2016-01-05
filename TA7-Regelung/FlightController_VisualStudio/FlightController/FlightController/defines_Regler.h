/* 
 * File:   defines_Regler.h
 * Author: Robin
 *
 * Created on 19. November 2015, 13:57
 */

#ifndef DEFINES_REGLER_H
#define	DEFINES_REGLER_H

#define KPXY 1.401       //Regelparameter KP für X und Y Achse
#define KIXY 0.067      //Regelparameter KI für X und Y Achse
#define KDXY 0.173    //Regelparameter KD für X und Y Achse
#define KPZ 1.5               //Regelparameter KP für Z Achse
#define KIZ 0.3               //Regelparameter KI für Z Achse
#define KDZ 0.107              //Regelparameter KD für ZAchse
#define REGELMAX 254     //Maximaler Regelwert 
#define REGLEROFFSETRL 0x08     //RegelOffset für Rechts Links
#define REGLEROFFSETVZ 0x0B     //RegelOffset für Vor Zurück
#define REGLEROFFSETD 0x02      //RegelOffset für Hoch Runter




#endif	/* DEFINES_REGLER_H */

