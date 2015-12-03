*Bachelorprojekt WS 2015/16 - HAW Hamburg - Quadrocopter-Tracking und Positionsregelung*
# Dokumentation - TA5 - Tracking


## Schnittstelle und Abhängigkeiten
- Verbindung zum Reglersystem per UDP-Socket
- opencv v3.0.0


## Modi
Bei Start des Trackingssystem können diese Modi aungewählt werden:

- loadConfig
- calibrateCamera
- calibrate3D
- tracking
- exit

Eine dieser Optionen kann auch per Programmparameter beim Aufruf des Programms ausgewählt werden.  
Alle Modi bis auf "tracking" und "exit" kehren wieder auf die Auswahl zwischen diesen Optionen zurück.


### loadConfig
Lädt die Kamerakonfiguration aus den Dateien, die im Sourcecode angegeben sind.

### calibrateCamera
Mit dieser Option werden die Verzeichnungsparamerter der Kameras bestimmt, die sog. intrinsischen Parameter. Es wird erst die Kalibrierung der ersten Kamera gestartet, wenn diese abgeschlossen ist, wird die zweite Kamera kalibriert.

Für die Kalibrierung muss ein Schachbrettmuster vor die Kamera gehalten werden. Wenn diese korrekt erkannt wurde (bunte Linien), kann die Kalibrierung begonnen werden.  
Zum start der halb-automatischen Kalibrierung muss die Taste "g" gedrückt werden. Nun werden mehere Bilder aufgenommen.  
Zwischen dem korrigierten und unkorrigierten Bild kann mit "u" gewechselt werden.  
Zum Beenden der aktuelle Kalibrierung muss "esc" gedrückt werden.

Die Kalibierung speichert die intrinsischen Parameter in der Camera-Klasse. Damit alle Parameter der Camera-Klasse auch in der cam.xml Datei gespeichert werden, muss "tracking" oder "exit" aufgerufen werden.

### calibrate3D
"calibrate3D" wird verwendet, um die extrinsischen Parameter der Kameras zu bestimmen.  
TODO


### tracking
Mit "tracking" werden die Kameraparamteter in der cam.xml Datei gespeichert und das Programm geht in den Hauptmodus über, mit dem der Copter getrackt wird und die Position an das Reglersystem übertragen wird.

### exit
"exit" speichert die Kameraparameter und beendet das Programm.
