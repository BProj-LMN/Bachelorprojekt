*Bachelorprojekt WS 2015/16 - HAW Hamburg - Quadrocopter-Tracking und Positionsregelung*
# Dokumentation - TA3 - Kameras


## Schnittstelle und Abhängigkeiten
Industriekameras DMK21F04(640x480Pixel,DaisyChain fähig) und DMK41BF02(1280x960Pixel) via FireWire 400 an unseren Pc angeschlossen. Da die Kabellänge begrenzt ist wurde ein Repeater verwendet. Die Kamera DMKBF02 ist via DaisyChain an die Kamera DMK21F04 angeschlossen. Diese reicht die Signale an den Repeater weiter, der diese an den Rechner sendet.


## Konstruktion
Die erste Konstruktion musste aufgrund der Tatsache, dass keine Befestigungen an den Lochplatten vorgenommen werden dürfen, verworfen werden. Damit die komplette Konstruktion ohne Scherwirkung der Halterung halten kann, wurde sich drauf geeinigt die Kameras "über Kopf" anzubringen, für eine leichtere Montage und die Bilder später in der Software zu drehen. Die Konstruktion wurde in CATIA V5 angefertigt. Diese wurde mittels Fused Deposition Modelling(FDM) gedruckt. Folgende weitere Materialien wurden benötigt:

- 2x M6 Schrauben 40mm
- 4x M6 Muttern
- 4x M6 Schrauben 15mm 
- Gaffer-Tape

M6 Schrauben wurden verwendet, da diese eh für die Grundplatten der Kameras vorgesehen waren. Die Kabel über dem Schrank wurden mittels Gaffer-Tape fixiert, genauso wie der Repeater. Die Kabel zwischen Repeater und der Kamera DMK21F04 wurden mittels HakenMagneten fixiert, die Gleichzeitauch als Netzhalterung fungieren sollen.

