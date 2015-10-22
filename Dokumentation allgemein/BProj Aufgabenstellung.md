# Bachelorprojekt Quadrocopter-Tracking: Aufgabenstellung
**3D-Tracking und Positionsregelung eines Quadrocopters**


## Aufgabe

Die Projektgruppe soll einen kleinen Quadcopter mittels optischer Mustererkennung im Raum finden und die Position der Quadcopter geregelt verändern.  
Dazu ist mit Hilfe von Kamerasystemen der Quadcopter zu identifizieren. Die Position im Raum soll anschließend geregelt werden. Hierzu ist zu untersuchen, wie man die vorhandene Fernsteuerung an die Steuersoftware anbindet, um diese in die Regelschleife einzubinden.


## Requirements-Sammlung

- Der Copter wird so geregelt, dass dieser an einer (im User-Interface vorgegebenen) Soll-Koorinate verbeibt, bzw. sich zu eben dieser bewegt.
- Die Rotoren des Copters lassen sich über einen Hardware-Schalter an der Fernbedienung sofort abschalten.
- Für die Steuerung des Copters wird ein User-Interface entwickelt, in dem die Soll-Position vorgegeben werder kann, sowie der Copter gestartet und gelandet werden kann. Außerdem wird im User-Interface die akuelle Ist-Koordinate des Copters angezeigt.
- Das User-Interface enthält eine Option, den sog. Not-Halt, der den aktuellen Flug abbricht und den Copter sanft landet.
- In der Flugsteuerung muss eine Maximalgeschwindigkeit einstellbar sein und sichergestellt werden, dass diese nicht überschritten wird.

