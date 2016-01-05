*Bachelorprojekt WS 2015/16 - HAW Hamburg - Quadrocopter-Tracking und Positionsregelung*
# Dokumentation - TA7 - Regelung

## Schnittstelle und Abhängigkeiten
In dieser Teilaufgabe wird der Entwurf einer Positionsregelung für den Quadcopter beschrieben. Des Weiteren wird der Flightcontroller als Schnittstelle zum Tracking-System vorgestellt.

## Flight Controller
???

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