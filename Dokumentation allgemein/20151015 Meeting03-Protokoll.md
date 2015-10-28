*Bachelorprojekt WS 2015/16 - HAW Hamburg - Quadrocopter-Tracking und Positionsregelung*
# Sitzungsprotokoll - Auftraggebertreffen Nr. 3

- Standup-Meeting jedes Mal zu Beginn mit folgenden Fragen:
	- Was war die Aufgabe?
	- Wie sieht das Ergebnis aus?
	- Wo gibt es Probleme, wie geht es weiter?

- laufende Dokumentation (in Foto und Video) immer ergänzen, auch um Zwischenberichte:
	- wenn der Quadrocopter schon  erkannt wird auch mal Filmschnipsel exportieren
	- generell auch mal zwischendurch Fotos & Videos machen für handfeste Zwischenergebnisse (können immer noch durch aktuellere, bessere Versionen ersetzt werden)


### Organisatorisches von Lehmann und Ideen und Anregungen

- Für die Recherchearbeit: Sichpunktartig den Inhalt der Quelle (BA-Arbeit) aufschreiben, sodass die Relevanz der Quelle für andere ersichtlich ist. Gelesene Bachelorarbeiten für sich selbst und andere Zusammenfassen und andere Gruppenmitglieder über den Informationswert der Arbeit in Kenntnis setzen
- Bei der Recherche am besten immer einer konkreten (und dokumentierten) Fragestellung nachgehen. Dann kann man auch dazu die Ergebnisse aufschreiben.
- Dokumentation: auch mal negative Ergebnisse dokumentieren, sodass der (komplette) Weg zum Ziel, incl. der Fehlschläge, auch anderen Personen bekannt ist.
- Recherche: Abschlussarbeit über einen Simulink Ethernet Anschluss vorhanden, beim nächsten Mal CD-Laufwerk mitnehmen
- Status: Kameras sind vorhanden, Mail mit Typenschild und Informationen kommt Zeitnah.
- Status: Rechner sind bald da
- Tracking: Industriekamera vs. Webcam
	- Bei den Industriekameras kann man den Auslösezeitpunkt festlegen, sodass alle Kameras gemeinsam auslösen
	- Bei einer Webcam bekommt man einfach einen Stream an Daten und muss in der Berechnung berücksichtigen, dass die Bilder nicht gleichzeitig aufgenommen wurden.
		- Das aktuelle CaroloCup-Auto kann auch ohne genaue Timing-Informationen fahren
	- Diskussion: eventuell liefert eine Webcam bessere Bilder und ist einfacher anzuschließen.
- Kameras: Überlegungen anstellen ob evtl eine 3. Kamera für Tote Winkel benötigt wird
- Regelung: Ist es für die Regelung ausreichend, wenn nur die Position des Copters bekannt ist, oder muss auch der Lage- und Rollwinkel erfasst werden
- Tracking: Die Kameras müssen für das Tracking und die Positionsberechnung genau ausgerichtet werden, bzw. die Position und der Blickwinkel der Kameras müssen bekannt sein.  
Möglichkeit für die Kalibrierung:
	- Ein Target in den Raum halten, dessen Position bekannt ist. Für diesen Punkt können dann auch die Bildkoordinaten auf jeder Kamera bestimmt werden. Aus diesen Informationen kann die Position der Kamera errechnet werden.
	- Das Verfahren muss dann mit merheren Positionen durchgeführt werden.
	- So muss nicht die Position und Ausrichtung jeder Kamera bekannt sein.
- Literaturempfehlung: Grundlagen der Bildverarbeitung
- Torge Hinrichs - Möglicher Ansprechpartner für OpenCV


### Verbesserungswünsche von Lehmann

- Im Gantt Chart steht als Notiz `Copter lässt sich über Potis ansteuern` (Integration FB-Software) -> Verbessern, generell Gantt im Hinblick auf Arbeitspakete überarbeiten
- Arbeitspakete zeitlich abschätzen und auch die Abweichung vom Erwartungswert überprüfen-> Hierfür evtl die App `Hours` nutzen
