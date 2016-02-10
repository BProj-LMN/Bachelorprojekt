*Bachelorprojekt WS 2015/16 - HAW Hamburg - Quadrocopter-Tracking und Positionsregelung*
# Recherche - Sockets
**Verbindung Tracking <-> Regler**

## Fragestellung
Wie können zwei Programme auf verschiedenen Rechnern miteinander Daten austauschen?

## Ergebnisse
- Stream- und Datagram-Sockets.
	- Stream: Zeichen-Datenstrom. Meist TCP (Reihenfolge und Zustellung garantiert)
	- Datagram: einzelne Nachrichten. Meist UDP (Zustellung nicht garantiert, dafür evtl. schneller)
	- für uns sind die daragram sockets passend, da unabhängig vom Empfänger die Daten gesendet werden können.
- Technologie: Immer erst den Server starten. Dieser hörcht dann auch einen bestimmten Port nach einer Anfrage. Der Client öffnet eine Verbindung zum Server und sendet Daten. Der Server kann dann antworten.
- Eine Socket-Verbindung ist durch das Paar aus Server- und Client-Port, sowie IP-Adresse bestimmt.
- Bei Datagram ist die Länge der Nachricht bekannt, bei Stream muss sich der Client um die korrekte Segmentierung kümmern.
- In C ist die Arbeit mit Sockets recht hardwarenah und brauch viele komische Structs und so. Das sollte aber nicht das Problem sein.  
Es gibt viele Beispiele im Internet.
- Die Verbindung mehrerer Programme über Sockets sieht nach einer ganz guten Idee aus.

