*Bachelorprojekt WS 2015/16 - HAW Hamburg - Quadrocopter-Tracking und Positionsregelung*
# Recherche - Regelung in Matlab und Code-Export
**AP7.1 - Recherche Regelung und Plattform auswählen**

## Fragestellung
1. Wie könnte ein Regler für unseren Qudrocopter aussehen? 
2. Wie kann man ein Simulink-Modell oder MatlabCode in C-Code Exportieren?

## Ergebnisse
### zu 1.
#### Quelle: Indoornavigation eines Quadrocopters (ab Seite 48) 
- PID Regler  
- Proportinalanteil:
Der Proportionalanteil ändert sich abhängig von der Größe der Regelabweichung.
```
output = (pid.p.nick_roll*y_rel); 
```
- Integralanteil:
Der Integralanteil nimmt stetig zu, so lange eine Regelabweichung vorliegt.
```
dt = 1/runningat; 
pid.sum.nick = pid.sum.nick + (y_rel*dt); 
if(pid.sum.nick>500) 
  pid.sum.nick = 500; 
else if(pid.sum.nick<-500) 
  pid.sum.nick = -500; 
end 
end 
output = (pid.i.nick_roll*pid.sum.nick); 
```
- Differentialanteil:
Der Differentialanteil reagiert auf die Änderungsgeschwindigkeit der Regelabweichung.
```
dt = 1/runningat; 
derivative_nick = (y_rel - pid.old_error.nick)/dt; 
output = (pid.d.nick_roll*derivative_nick); 
pid.old_error.nick = y_rel; 
```

#### Quelle: <http://rn-wissen.de/wiki/index.php/Regelungstechnik#PID-Regler>

```
esum = esum + e
y = Kp * e + Ki * Ta * esum + Kd * (e – ealt)/Ta
ealt = e
```
dabei ist e die Lageabweichung
### zu 2.
#### Quelle: Matlabdoku 'C/C++ Code Generation'
- Um C-Code aus einem Matlab-code zu erzeugen ist eine Funktion nötig Skripte macht der nicht. 
- Wenn man eine Matlabfunktion hat muss man über den Matlab Coder ein projekt anlegen.
- Dort fügt man als Entry-Point Files die Funktion ein und wählt die Datentypen für die Input daten ein.
- wenn man dann als Output type c/c++ wählt und auf Build klickt sollte der die Funktion in C-code compilieren.
- Dabei werden dann aber sehr viele Header und Source files erzeugt.

#### bei Simulink
- Modell auf Discrete Schritte einstellen
- Über Build Modell wird c code erzeugt dieser landet im Matlab ordner 
- in meinem test beispiel kommen keine korrekten werte raus da muss man nochmal sehen was da falsch gelaufen ist.