*Bachelorprojekt WS 2015/16 - HAW Hamburg - Quadrocopter-Tracking und Positionsregelung*
# Dokumentation - TA6 - Sollwerte


## Schnittstelle und Abhängigkeiten
In dieser Teilaufgabe soll eine Start- und Landeprozedur programmiert , sowie ein User-Interface implementiert werden. Nach einer definierten Startprozedur des Quadrocopters wird der User nach Sollwerten gefragt. Anhand eines Ist- und Sollwertsvergleich soll die Flugbahn in der Trajektorie berechnet und angeflogen werden. Nach Beenden des Fluges erfolgt eine definierte Landeprozedur.


## Startprozedur
Als Startprozedur wird nur der Steigwert geändert, Rechts/Links und Vor/Zurück werden auf ungefähr Mittelstellung gestellt. Die Höhensteuerung wird fest auf **0xA0** gesetzt, bis das Tracking eine Höhe von **25cm** erreicht wird. Ab hier ist die Startprozedur beendet und die Regelung greift ein. Die Startprozedur ist erforderlich, damit keine Einflüsse durch Bodeneffekte vorhanden sind.

##Landeprozedur
Als Landeprozedur wird die Höhensteuerung auf 0x90 gesetzt. Dieser Wert bedeutet, dass der Quadrocopter ungefähr auf einer Stelle schwebt. Dieser Wert wird langsam runter gezählt solange bis er auf Null gesunken ist. Die Dauer der Zählungsschritte wurde empirisch bestimmt, sodass der Quadrocopter sanft absinkt.

##Trajektorie

Die Trajektorien-Klasse hat zwei Methoden zur Berechnung der Checkpoints der Flugroute. Methode A und Methode B. Beiden werden alle momentanen Ist-Werte und die vom User gewünschten Sollwerte übergeben. Dadurch haben wir die Koordinaten von zwei definierten Punkten im Raum. Aus diesen werden Orts- und Richtungsvektor berechnet.
Methode A berechnet eine über defines definierte Anzahl von Checkpoints. Diese werden Auf der Geraden so verteilt, dass die Gerade immer wieder halbiert wird. Somit sind um die beiden Punkte die meisten Checkpoints vorhanden während in der Mitte größere Abstände vorhanden sind.

 Als Visualisierung folgende Skizze, die beiden übergebenen Punkte sind P und Q.

    P--x--x----x--------x----------------x----------------x--------x----x--x--Q

Das Problem bei dieser Berechnung ist die definierte Festlegung auf eine bestimmte Anzahl an Checkpoints. Während es bei kleinen Strecken zu so kleinen Änderungen kommt, die gar nicht so genau angeflogen werden können, kommt es bei großen Strecken zu derat riesigen Distanzen zwischen den Checkpoints in der Mitte, das eventuell die Höchtsgeschwindigkeit des Quadrocopters überschritten wird.

Methode B berechnet die Checkpoints je nach Länge der Gerade. Hier wird der Richtungsvektor auf eine über defines definierte Toleranz verkleinert. So können mittels Geradengleichung vom Ortsvektor aus Checkpoints mit definierter Entfernung zueinander berechnet werden. Diese Werte sind jedoch noch etwas ungenau, da z.b. der Endpunkt nicht mehr exakt mit dem Sollwert übereinstimmt, sondern sich in der Toleranz befindet. Dies ist aber das geringere Übel. Eine Trajektorien berechnung über SPlines oder ähnliches ist bisher noch nicht vorgesehen kann aber als weitere Berechnungsmethode einfach ergänzt werden. 

    P---x---x---x---x---x---x---x---x---x---x---x---x---x---x---x---x---x---x---x---Q

Die jeweils nächste anzufliegende Checkpoint wird an die Regler weitergegeben. Der Regler holt sich den momentanen Checkpoint über die Methoden "getNextCheckpoint_" . Ob der Punkt erreicht ist, kann  über die Methode "checkpointReached" überprüft werden. Auch hierfür gibt es ein Toleranzdefine, ab wann der Checkpoint als erreicht gilt. Nach Erreichen wird der nächste Checkpoint mittels "nextCheckpoint"aufgerufen. Es gibt eine weitere Funktion "ArrayEndReached" die das Ende des beschriebenen Arrays ermittelt. Diese Funktions gibt solange 1 aus, bis das Ende des beschriebenen Arrays erreicht ist. Das komplette Array wurde länger gelassen als Puffer.

##User-Interface

Das User Interface besteht momentan noch aus einer Abfrage über das Konsolenfenster. Dieses könnte noch über ein grafisches User-Interface oder ähnliches erweitert werden.