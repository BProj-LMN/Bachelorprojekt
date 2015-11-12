*Bachelorprojekt WS 2015/16 - HAW Hamburg - Quadrocopter-Tracking und Positionsregelung*
# Dokumentation - TA4 - Fernsteuerung


## Schnittstelle und Abhängigkeiten
Die Vernsteuerung wird über eine micro-USB-Schnittstelle mit einem PC verbunden. Über diese Schnittstelle ist ein virtueller Serieller Port nutzbar.

### Einleitung
Die verwendete Fernsteuerung hat normalerweise 2 Joysticks mit je 2 Achsen. Angesteuert werden:

- mit dem linken Stick:
	- hoch/runter:  Schubregelung (throttle) 
	- links/rechts: Drehung um Hochachse (yaw)
- mit dem rechten Stick:
	- hoch/runter:  vor/ zurück fliegen (pitch) 
	- links/rechts: links/ rechts fliegen (roll)

Die Joysticks sind einfache Potentiometer, die den Winkel des Sticks proportional auf eine Spannung zwischen 0V und 3,3V abbilden.  
Um die Fernsteuerung vom Computer aus steuern zu können, wird ein kleiner Mikrocontroller verwendet, der das Spannungssignal der Potentiometer emuliert. Aufgrund der CMOS-Pegel, der Baugröße und der integrierten USB-Schnittstelle wurde der Infineon XMC2Go ausgewählt.

### Verbindung mit dem Computer
- Serielle Datenübertragung
	- 115.2 kbit/s
	- 8 Datenbits, 1 Stoppbit, kein Parity
- mirco-USB-Schnittstelle mit (virtueller) serieller Schnittstelle
- Datenformat:

```
0xFF                  // start byte
{8-Bit unsigned int}  // throttle: 0x00 - 0xFE -> aus   - voll
{8-Bit unsigned int}  // pitch:    0x00 - 0xFE -> rück  - vor
{8-Bit unsigned int}  // roll:     0x00 - 0xFE -> links - rechts
{8-Bit unsigned int}  // yaw:      0x00 - 0xFE -> links - rechts

Kommentare: - Schwebeflug bei throttle von ca. 150 (dezimal)
```

- der gültige Bereich für die Ansteuerungswerte ist: `0x00 bis 0xFE`
- die Mittelstellung liegt nominell bei 127 (dezimal), der Copter ist jedoch nicht sehr gut getrimmt, weshalb dieser nicht auf der Stelle schweben wird
- es ergeben sich 5x 8 Bit (keine Leerzeichen, etc.)
- die Werte werden so lange gehalten, bis neue gesendet wurden
- die Steuerung initialisiert mit Werten, die der Mittelstellung der Joysticks und keinem Schub entsprechen
- jedes Startbyte wird mit einem Byte `0xFF` beantwortet
- ACHTUNG: Das Verhalten des Mikrocontrollers ohne Stromversorgung ist undefiniert!

### Not-Aus-Taster
Um eine zusätzliche Sicherheitsebene zu schaffen, sollte es einen Not-Aus-Schalter an der Fernbedienung geben, der sofort alle Motoren abschaltet.  
Für die Anfangsphase wird noch einen Schritt weiter gegangen, indem der Not-Aus-Taster gedrückt gehalten werden muss, damit der Copter fliegen kann.



## Analyse der Hardware und Umsetzung
Der Mikrocontroller und die Fernsteuerung wurden über die im folgenden beschriebenen "Schnittstellen" verbunden.

### Elektrische Verbindungen mit der Fernsteuerung
Die Steuerelemente der Fernsteuerung sind wie folgt charakterisiert: 

```
throttle: Stick unten: 3,3V - oben: 0V
          P0.6 @XMC2Go, rotes Kabel
pitch:    Stick unten: 3,3V - oben: 0V
          P0.7 @XMC2Go, blaues Kabel
roll:     Stick links: 3,3V - rechts: 0V
          P0.8 @XMC2Go, braunes Kabel
yaw:      Stick links: 3,3V - rechts: 0V
          P0.9 @XMC2Go, gelbes Kabel

Not-Aus:  wenn gedrückt: Schließer zwischen Masse und dem µC
          P2.7 @XMC2Go, gelbes Aderpaar
```

Dadurch folgt diese Umsetzung der Flugbewegungen in Ansteuersignale der PWM-Pins!

Achse    | low/zurück/links | neutral | high/vor/rechts
-------- | ---------------- | ------- | ---------------
throttle | 3.3V - 0xFE      |   -/-   | 0V - 0x00
pitch    | 3.3V - 0xFE      |   -/-   | 0V - 0x00
roll     | 3.3V - 0xFE      |   -/-   | 0V - 0x00
yaw      | 3.3V - 0xFE      |   -/-   | 0V - 0x00

Da diese Zuordnung etwas unintuitiv ist, wurden alle Steuerbefehle für die Schnittstelle invertiert:

Achse    | low/zurück/links | neutral | high/vor/rechts
-------- | ---------------- | ------- | ---------------
throttle | 0x00             |   ---   | 0xFE
pitch    | 0x00             |   0x84  | 0xFE
roll     | 0x00             |   0x84  | 0xFE
yaw      | 0x00             |   0x84  | 0xFE

### Not-Aus-Taster
Der Not-Aus-Taster soll (wie oben beschrieben) den Schub sofort abstellen, wenn dieser nicht gedrückt ist. Für die "absolute" Sicherheit war die erste Idee, den Not-Aus-Taster vollkommen unabhängig vom Mikrocontroller zu bauen. Da nun aber das Signal "kein Schub" erfordert, dass 3,3V auf den Controller der Fernsteuerung gegeben werden, ist dies mit einem Unterbrecher nicht ganz so einfach zu realisieren.  

Daher wurde der Not-Aus-Taster nun doch an den Mikrocontroller angeschlossen und über diesen ausgewertet. Der Taster liegt zwischen dem Mikrocontroller und Masse, sodass der interne Pull-Up-Widerstand aktiviert wurde. Wenn der Taster losgelassen wird (HIGH-Pegel), wird der Schub ausgeschaltet (3.3V) und alle anderen Signal auf die Mittelstellung gebracht.



## Bauanleitung
In diesem Abschnitt werden weitere Hinweise für die hardwareseitige Realisierung der Computer-Fernsteuerungs-Schnittstelle behandelt.

### Modifikationen Fernsteuerung
- Zunächst müssen beide Joysticks (mit je 2 Potentiometern) von der Platine der Fernsteuerung entfernt werden
- Danach müssen die Leiterbahnen, die durch das Gehäuse der Joystick verbunden wurden, erneut mit Kabeln verbunden werden.
- Außerdem müssen natürlich noch Leitungen zum Mikrocontroller gelegt werden. Dafür wird jeweils mit dem mittleren der Joystick-Anschlüsse (auf der Platine) ein Kabel verbunden.
- Zusätzlich muss auch die Masse der Fernsteuerung mit einem Kabel verbunden werden, sodass dieses später mit dem Mikrocontroller verbunden werden kann.
- Außerdem kann noch der Not-Aus-Taser in eine freie Öffnung der Fernsteuerung eingebaut und mit Anschlussleitungen versehen werden.

### Platine Mirkocontroller
Der Mikrocontroller wurde auf ein kleines Stück Lochrasterplatine gesetzt. Auf dieser müssen folgende Verbindungen hergestellt werden.

- je ein Kondensator 470µF, 16V zwischen einem Ausgang und der Masse (zum Glätten des PWM-Signals zu einer Gleichspannung)
- Anschlussmöglichkeit für die 4 Ausgänge, die die Joysticks ersetzen
- Anschluss des Not-Aus-Tasters zwischen dem Eingangspin und Masse
- Verbindung der Masse der Fernsteuerung mit der Masse des Mikrocontrollers

Im Idealfall sollten diese 7 Ein- und Ausgangsleitungen über ein oder zwei verpolungssichere Stecker angeschlossen werden.



## TODO:
- Mikrocontroller fest einbauen
- Stromversorgung Mikrocontroller auch ohne USB sicherstellen
