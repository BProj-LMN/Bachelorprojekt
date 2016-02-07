*Bachelorprojekt WS 2015/16 - HAW Hamburg - Quadrocopter-Tracking und Positionsregelung*
# Benutzerhandbuch Flight Controller

## Inbetriebnahme
### Installationen
Zur Inbetriebnahme des Programms ist die Installation von **Microsoft Visual Studio** und eines **J-Link** Treiber notwendig.

**Microsoft Visual Studio** ist notwendig, da Eclipse und NetBeans eine wichtige Funktion der Socket verbindung nicht unterstützt. 
Programmpfad:TA7-Regelung/TA7-FlightController.

Der **J-Link** Treiber ist notwendig um die Kommunikation mit der Fernsteuerung aufzubauen. Dieser Treiber ist in "Dave"(Infineon), der Programmiersoftware für den Microcontroller in der Fernsteuerung, enthalten.

### Hardwareaufbau und Konfiguration
**Netzwerkverbindung einrichten**: Verbindung zwischen HAW-Netzwerk und Rechener über Ethernet Kabel aufbauen. Gegebenenfalls einen USB to Ethernet-Adapter nutzen falls kein Ethernetanschluss vorhanden. IP-Einstellungen prüfen: Kontrollieren ob im *Wrapper_Socket.cpp* Konstruktor die IP des Trackingrechners eingetragen ist.
`Socket = new SocketClient("141.22.27.193", 1362);`
Im Moment ist die IP: **141.22.27.193**

**Fernsteuerungverbindung einrichten**: Verbindung zwischen Fernsteuerung(**ausgeschaltet**) und Rechner über Micro-USB-Kabel aufbauen. Port-Einstellungen prüfen: Kontrollieren ob im *SerielleUebertragung.cpp* Konstruktor der Port der J-Link verbindung eingetragen ist.
`Port = L"COM7";`
Im Moment ist der Port: **COM7**
**Achtung!! Es wird nur Port COM1 bis COM9 unterstützt.**

### Quadcopter Flug vorbereiten
1. Akku mit dem Quadcopter verbinden.
2. Quadcopter so ausrichten, dass die beiden Weißen LEDS(Vorne) in Richtung Kameras zeigen.
3. Fernsteuerung einschalten.
4. Kontrolieren ob das Tracking läuft.
5. Programm starten. 

## Bedienung des Programms
Über **ESC** kann das Programm jederzeit beendet werden.
Über **ENTER** kann das Programm in den nächsten Status gebracht werden.
Damit der Quadcopter angesteuert werden kann, muss der Taster an der Fernbedienung betätigt sein.

**1. Status: Verbindung aufbauen**: Am Anfang muss eine Verbindung zwischen Fernsteuerung und Quadcopter aufgebaut werden. Wenn Verbindung schon aufgebaut ist **Enter** betätigen. Wenn noch keine Verbindung aufgebaut ist, muss der Taster an der Fernsteuerung betätigt sein. Nachdem die Fernsteuerung einmal gepiept hat, **Enter** betätigen, um die Verbindung komplett aufzubauen. Es wurde eine Verbindung aufgebaut, wenn die Fernsteuerung 2 mal gepiept hat. Wenn das Programm nach dem betätigen von **Enter** direkt ans Programmende springt Verbindung mit Trackingsystem prüfen.

**Achtung!! Wenn Verbindung bereits aufgebaut ist nicht den Taster auf der Fernsteuerung betätigen.**

**2. Status: Sollwerte einlesen**: Nun läuft die Regelung und der Quadcopter soll eine Höhe von 1 Meter und die Horizontale Position des Startpunktes halten. Nun können neue Sollwerte für X, Y und Z eingegeben werden. Um die einzelnen Sollwerte einzugeben **ENTER** betätigen. Nachdem alle Sollwerte eingegeben wurden, wird die Position gehalten bis mit **ENTER** der Zielanflug gestartet wird. Wenn **ESC** gedrückt wird, wird der **Status Landen** ausgeführt und das Programm beendet. 

**Achtung!!Ab nun Taster an der Fernsteuerung betätigt lassen, damit der Regler zuverlässig arbeitet.**

**3. Status: Ziel anfliegen**: Nun wird anhand der errechneten Trajektorie das Ziel angeflogen. Per **ENTER** kann wieder in **Status Sollwerte einlesen** gewechselt werden und der Quadcopter hält die aktuelle Position.Wenn **ESC** gedrückt wird, wird der **Status Landen** ausgeführt und das Programm beendet. 

**Achtung!! Ziel Anfliegen konnte biser noch nicht getestet werden.**

**4. Status: Landen**: Im Lande Modus wird der Höhen Schub langsam auf Null gesenkt. Dieser Status wird auch ausgeführt, wenn sich der Quadcopter durch loslassen des Tasters an der Fernsteuerung schon auf dem Boden befindet.

## Einstellungsmöglichkeiten
Es gibt diverse Reglereinstellungsparameter die Bearbeitet werden können.
Unter *defines_Regler.h* können folgende Parameter geändert werden:

- **KPXY, KIXY, KDXY**: Reglerparameter für die Horizontalen Achsen. **KPXY** ist der Proportinalanteil. **KIXY** ist der Integraleanteil. **KDXY** ist der Differentielleanteil.

- **KPZ, KIZ, KDZ**: Reglerparameter für die Vertikale Achsen. **KPZ** ist der Proportinalanteil. **KIZ** ist der Integraleanteil. **KDZ** ist der Differentielleanteil.

- **REGLEROFFSETRL**: Steuerungsparameter zum Trimmen der `Rechts und Links Richtung = Y Achse` (Festlegung des Arbeitspunktes)

- **REGLEROFFSETVZ**: Steuerungsparameter zum Trimmen der `Vor und Zurück Richtung = X Achse`(Festlegung des Arbeitspunktes)

- **REGLEROFFSETD**: Steuerungsparameter zum Trimmen der `Drehung`(Dies wird nicht geregelt)

- **REGLEROFFSETHR**: Steuerungsparameter zum Trimmen der `Hoch und Runter Richtung = Z Achse`(Festlegung des Arbeitspunktes)

Änderbare Reglerparameter im *FlightContoller.cpp* 
**Achtung!! Nicht unüberlegt ändern**

In `FlightControllerClass()`: 
`regler.. = new PID_Regler(UG, OG);`
UG = Untere Regelbegrenzung
OG = Oberer Regelbegrenzung
Diese Parameter sollten nicht zu groß sein, weil der Quadcopter sonst zu schnell für das Trackingsystem werden kann.

In `Initialisieren()`:
`regler..->setfactors(KP.., KI.., KD.., Skalierung);`
Skalierung = Skalierungsfaktor der den Regelbereich streckt oder staucht.
Wenn dieser Parameter geändert wird, müssen die Reglerparameter womöglich auch leicht verändert werden. 