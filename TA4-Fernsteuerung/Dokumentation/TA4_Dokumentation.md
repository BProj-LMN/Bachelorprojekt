# Bachelorprojekt Quadrocopter-Tracking: Dokumentation
**AP4.2 - Fernsteuerung**


## Protokoll zum/vom Computer
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


## Elektrische Verbidungen mit der Fernsteuerung

```
thottle: gelbes Kabel
pitch:   braunes Kabel
roll:    blaues Kabel
yaw:     rotes Kabel
```


## XMC2Go

```


```