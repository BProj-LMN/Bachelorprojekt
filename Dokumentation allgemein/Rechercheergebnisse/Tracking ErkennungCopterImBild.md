*Bachelorprojekt WS 2015/16 - HAW Hamburg - Quadrocopter-Tracking und Positionsregelung*
# Recherche - Erkennung des Copters im Bild
**AP5.1 bzw AP5.2**

## Fragestellung
Wie kann der Copter am besten im Raum / im Bild erkannt werden?


## Ergebnisse

#### Hintergrund-Differenz
Die erste Idee war, dass vom aktuellen Kamerabild jeweils der Hintergrund (Raum ohne Copter beim starten des Systems) subtrahiert wird, sodass die Veränderung (helle Werte) den Copter darstellen muss.  
Dieses System funktioniert nur, da der Raum ausschließlich künstliche Beleuchtung hat und diese sich daher nicht (nur geringfügig) ändert.

Der entscheidende Nachteil dieser Methode ist jedoch der recht hohe Rechenaufwand!


#### Reflektoren
Herr Prof. Meisel wies darauf hin, dass Reflektorfolien (z.B. von 3M) sehr hell zurückstrahlen und der Copter zu eine helles Objekt bildet. So kann die Belichtungszeit der Kameras so eingestellt werden, dass der Raum dunkel ist und nur der Copter zu "sehen" ist, wenn die Lichtquelle nah an der Kamera montiert wird.  
Außerdem können statt sichtbarem Licht auch IR-Scheinwerfer verwendet werden, da die Industriekameras auch auf IR-Licht reagieren.
