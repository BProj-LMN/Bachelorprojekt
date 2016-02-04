*Bachelorprojekt WS 2015/16 - HAW Hamburg - Quadrocopter-Tracking und Positionsregelung*
# Dokumentation - TA7 - Regelung

## Schnittstelle und Abhängigkeiten
In dieser Teilaufgabe wird der Entwurf einer Positionsregelung für den Quadcopter beschrieben. Des Weiteren wird der Flightcontroller als Schnittstelle zum Tracking-System vorgestellt.

## Flight Controller
Im Flight Controller wurden diverse Funktionen des Systems so kombiniert, dass der Flug des Quadcopters anhand der ermittelten Positionswerte des Trackingsystems geregelt wird. Dabei läuft die Kommunikation zwischen Tracking und Flight Controller über Udp Packete.

Die Hauptfunktionen des Flight Controllers umfassen:
- Regeln
- Steuern
- Sollwerte einlesen
- Trajektorie bestimmen
- mit dem Tracking kommunizieren

Zum Verständis der Main und des Flight Controllers wurden diverse Activity Diagrams erstellt, welche die Hauptfunktionen des Flight Controllers beschreiben.

### Regeln
Zur Regelung des Quadcopters wurde ein PID Regler implementiert. Der Regler wurde so geschrieben, dass der I-Anteil und der Ausgegeben Regelwert begrenzt wird.

Konstruktor:
`PID_Regler(double UG, double OG)`
im Konstruktor kann die untere(UG) und obere(OG) Grenze des Reglers übergeben werden. Auf diese Werte wird der I-Anteil und Ausgabewert des Reglers begrenzt.

Methoden:
-`setfactors(double kp, double ki, double kd, double Scale)`
in dieser Methode können die Regelkoeffizienten festgelegt werden. Sowie ein Scalierungsfaktor der den Ausgabewert Skaliert.
-`setSoll(double Soll)`
in dieser Methode kann der Sollwert des Reglers festgelegt werden.
-`getControlValue(double IstValue)`
in dieser Methode ist der eigentliche Regler implementiert. Der Anhand der Istwerte und Sollwerte ein Regelwert zurückgibt.

### Steuern
Um den Quadcopter zu Steuern musste eine Serielle Schnittstelle implementiert werden, um mit der Fernsteuerung zu Kommunizieren. Dazu wurde eine Universelle Serielle Schnittstelle implementiert die über einen Wrapper auf unsere Funktion abgestimmt wurde.
Die Wrapper Methoden 
(Z)`HochRunter(double Regelung,int Akkukompensation)` 
(Y)`RechtLinks(double Regelung)`
(X)`VorZurueck(double Regelung)`
dienen zum Steuern der verschiedenen achsen, Vorne ist dabei die Seite des Quadcoters wo die beiden Weißen LEDS sind. Die Methoden schreiben dabei aber nur in einen Sende Rahmen. Um die Steuerwerte an die Fersteuerung zu senden muss die Methode `Steuern()` aufgerufen werden.

### Sollwerte einlesen
Um die Sollwerte einzulesen wurde ein UI erstellt. Im UI gibt es eine Methode `EnterGedrueckt()` die eine 1 zurück gibt wenn Enter betätigt wurde, sowie Error auf 1 setzt, wenn ESC gedrückt wurde.
Die Methode `sollEinlesen()` ist so aufgebaut, dass keine Warte schleifen oder ähnliches einegbaut sind dadurch kann nebenbei weiter gereglt werden. Dies wird durch mehrere Switches  und diverse if abfragen erreicht.In der `switch (status)` werden die eingegebenen Zahlen in case 4 eingelesen. case 0 bis 3 dienen für die verschiedenen Textausgaben. Case 5 fügt die eingebenen Zahlen zu einem Sollwert zusammen. Die `switch (pos)` dient zum begrenzen der einzelnen Sollwerte.
Mit den Methoden 
`getX()`;`getY()`;`getZ()`
kann man die einzelnen Sollwerte auslesen.

### Trajektorie bestimmen
Für die Trajektorie gibt es eine eigene dokumentation.

### mit dem Tracking kommunizieren
Um mit dem Tracking zu kommunizieren musste eine Wrapper für die Udp kommunikation implementiert werden. Die Wrapper wurde Wrapper-Socket genannt. Sie umfasst die Methoden `getX()`;`getY()`;`getZ()` um die Istwerte in anderen Klassen zu nutzen. Um die aktuellen werte zu haben muss vorher die Methode  `updateIstwerte()` aufgerufen werden. Die Methode liest die gesendeten Udp Packete aus und formatiert diese so, dass die Istwerte auslesbar sind.
Um zu kontrollieren ob eine Verbindung aufgebaut wurde dient die Methode `connect()``,wenn die Methode eine 0 zurück gibt ist eine verbindung aufgebaut.

## Regelung

### Bestimmung der dynamischen Parameter des Quadcopters
Zur Strecken-Identifikation werden zwei Sprungantworten des Quadcopters aufgenommen. Eine Höhensprungantwort (Z-Richtung) sowie eine Lagesprungantwort (XY-Richtung). 

Die Sprungantworten werden mit der Smartphone-Kamera aufgezeichnet und die entstandenen Videos später mit einer Videoschnittsoftware ausgewertet. Dafür werden sie in Zeitlupe abgespielt und jeweils mehrere Datenpunkte (Zeitpunkt, Ort) aufgenommen. Die Datenpunkte werden zunächst in eine Excel-Tabelle eingetragen und ein grober Verlauf der Strecke geplottet. Dabei stellen wir fest, das es sich um eine IT1-Stecke handelt.

Die Datenpunkte werden anschließend in Matlab/Simulink übernommen und die Sprungantworten für Höhe und Lage erneut geplottet. Der Verlauf ist deutlich genauer, da weitere Datenpunkte extrapoliert werden. Die Streckenparameter KI und T1 werden jeweils anhand der Plots bestimmt. KI entspricht der Steigung der Geraden und T1 wird graphisch bestimmt.

### Implementierung der Regelung
Für die Regelung der IT1-Strecke wird ein PID-Regler verwendet. Dafür wird der Regelkreis in Simulink modelliert. Zur Ermittlung der Reglerwerte P, I und D wird die "Tune"-Funktion innerhalb des PID-Blocks verwendet. 

Der Code für den PID-Regeler wird in C++ geschrieben. Er verwendet als Reglerparameter die aus dem Simulink-Modell ermittelten Werte. Eingangswerte für den Regler sind die vom User eingegeben Soll-Werte, von denen die Ist-Werte (Optisches Tracking) abgezogen werden.

## TODO:
- Reglerparameter nach weiteren Verfahren bestimmen und Stabilität überprüfen.
- Regelung testen