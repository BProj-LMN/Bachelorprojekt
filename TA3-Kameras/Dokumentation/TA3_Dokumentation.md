*Bachelorprojekt WS 2015/16 - HAW Hamburg - Quadrocopter-Tracking und Positionsregelung*
# Dokumentation - TA3 - Kameras


## Setup PC und Kameras

### Industriekameras

- DMK21F04
	- 640x480Pixel
	- DaisyChain fähig
- DMK41BF02 (1280x960Pixel) via FireWire 400

Die Industriekameras wurden an unseren PC angeschlossen. Da die Kabellänge von FireWire begrenzt ist wurde ein Repeater zwischen dem PC und der ersten Kamera verwendet. Die andere Kamera ist dementsprechend per DaisyChain über die erste Kamera verbunden.

### Software

- Matlab R2013b wurde installiert (Standardinstallation)
- GitHub Desktop (und damit auch Git) wurde installiert (Standardinstallation)
- Sourcetree wurde installiert (Standardinstallation)
- Mingw-w64 wurde installiert (Standardinstallation)
- VLC-Player wurde installiert (Standardinstallation)
- OpenCV 3.0 wurde installiert (siehe unten)

### Hinweise
Die Kameras sind unter Matlab zu sehen, wenn mann unter "Apps" die "Image Acquisition" anklickt und die Kameras zuvor via Firewire mit dem Rechner verbunden sind.

### OpenCV-Installation

1. CMake wurde installiert (Standardinstallation) - ohne Pfad hinzufügen!
2. Schritte 2-7 der OpenCV-Installationsanleitung (2.4) der Dokumentation ausführen (<http://docs.opencv.org/2.4/doc/tutorials/introduction/windows_install/windows_install.html>)
3. in CMake die Examples zusätzlich anwählen, 
4. zu den Umgebungsvariablen `C:\MinGW\bin;C:\Users\User\OpenCV\opencv\build\Selbergemacht\bin;C:\Users\User\OpenCV\opencv` hinzufügen
5. mit MinGW die Files kompilieren: `minGW32-make` in der Kommandozeile eingeben
6. Eclipse: in den Projektproperties unter `C/C++ Build / Settings`:
	1. GCC C++ Compiler / Includes /Includes Path (-I)  
	   `"C:\Users\User\OpenCV\opencv\build\include"` und `"C:\Users\User\TIS-library\include"`  hinzufügen
	2. GCC C++ Compiler / Miscellaneous Other flags:  
	   `-c -fmessage-length=0 -march=i486 -std=c++11` hinzufügen
	3. MinGW C++ Linker / Library search path (-L)  
	   `C:\Users\User\OpenCV\opencv\build\Selbergemacht\lib` und `C:\Users\User\TIS-library\bin\win32` hinzufügen 
	4. MinGW C++ Linker / Libraries (-I) alle unter  
	   `C:\Users\User\OpenCV\opencv\build\Selbergemacht\lib` zu findenenden `*.dll.a` Dateien hinzufügen  
	   (die Endung und das lib aber weglassen - z.B. `opencv_core300` statt `libopencv_core300.dll.a`)
7. in den Properties außerdem unter `C/C++ build / Settings / Binary Parsers` den PE Windows Parser wählen


## Konstruktion Kamerahalterungen
Die erste Konstruktion musste aufgrund der Tatsache, dass keine Befestigungen an den Lochplatten vorgenommen werden dürfen, verworfen werden. Damit die komplette Konstruktion ohne Scherwirkung der Halterung halten kann, wurde sich drauf geeinigt die Kameras "über Kopf" anzubringen, für eine leichtere Montage und die Bilder später in der Software zu drehen. Die Konstruktion wurde in CATIA V5 angefertigt. Diese wurde mittels Fused Deposition Modelling(FDM) gedruckt. Folgende weitere Materialien wurden benötigt:

- 2x M6 Schrauben 40mm
- 4x M6 Muttern
- 4x M6 Schrauben 15mm 
- Gaffer-Tape

M6 Schrauben wurden verwendet, da diese eh für die Grundplatten der Kameras vorgesehen waren. Die Kabel über dem Schrank wurden mittels Gaffer-Tape fixiert, genauso wie der Repeater. Die Kabel zwischen Repeater und der Kamera DMK21F04 wurden mittels HakenMagneten fixiert, die Gleichzeitauch als Netzhalterung fungieren sollen.

