*Bachelorprojekt WS 2015/16 - HAW Hamburg - Quadrocopter-Tracking und Positionsregelung*
# Dokumentation - TA4 - Fernsteuerung


## Schnittstelle und Abhängigkeiten
Die Vernsteuerung wird über eine micro-USB-Schnittstelle mit einem PC verbunden. Über diese Schnittstelle ist ein virtueller Serieller Port nutzbar.

### Verbindung mit dem Computer
- Serielle Datenübertragung 115.2 kbit/s
- über die mirco-USB-Schnittstelle
- Format:

```
0xFF
{8-Bit unsigned int}  // Höhe
{8-Bit unsigned int}  // vor/rück
{8-Bit unsigned int}  // links/rechts
{8-Bit unsigned int}  // drehen
```

- 8 Datenbits, 1 Stoppbit, kein Parity


### Elektrische Verbidungen mit der Fernsteuerung

```
thottle: gelbes Kabel
pitch:   braunes Kabel
roll:    blaues Kabel
yaw:     rotes Kabel
```

