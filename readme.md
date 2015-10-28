*Bachelorprojekt WS 2015/16 - HAW Hamburg - Quadrocopter-Tracking und Positionsregelung*
# Readme und allgemeine Vereinbarungen

## Git-Struktur

### Ordnerstruktur
```
+-- Dokumentation allgemein
+-- Recherche allgemein ??
+-- TA{TA-Nr.}-{TA-Kurzname}
|   +-- Dokumentation
|   +-- {Code-Ordner und weitere spezielle Dokumente}
+-- readme.md
```

### Branches
```
master
development
TA{TA-Nr.}/development
TA{TA-Nr.}/{weitere Branches}
```
Es gibt keine `TA{TA-Nr.}/master` Branch, da diese mit der `development` branch gleichzusetzen ist.

### Commit-Messages
Commits sollten immer eine Sammlung von Code beinhalten, die eine Logische Einheit bildet. Die Commit-Meldung spiegelt dann wieder, was für Änderungen gemacht wurden.  
Damit auf den ersten Blick klar ist, welche Art von Inhalt ein Commit hat, gibt es folgende Präfixes:

- `[DOC]` für (reine) Arbeit an der Dokumentation
- `[CODE]` für Arbeiten am Code
- `[BUG]` für reine Bugfixes

Dabei kann und sollte ein `[CODE]` Commit auch die entsprechende Dokumentation enthalten.  
Wenn keine Kategorie passt, muss den Commit auch keine aufgezwungen werden.


## Infos und Ressourcen

#### Programme
- Git-Software: [Github](https://desktop.github.com) (einfach), [sourcetree](https://www.sourcetreeapp.com) (mehr Funktionen)
- Mindmaps: <http://www.xmind.net/de/>
- Gantt-Chart: <http://www.ganttproject.biz/download>

#### "Nachschlagewerke"
- [Github Markdown](https://help.github.com/articles/github-flavored-markdown/): um einfach strukturierte Texte zu schreiben.
- [Git-Flow](http://nvie.com/posts/a-successful-git-branching-model/): Git branches und co
- <https://media.ccc.de/browse/conferences/gpn/gpn15/gpn15-6916-commit-makrame_git-antipatterns.html#video> bei Interesse, die ersten 20 Min. "Was man mit Git nicht machen sollte"


## coding style guide
der lebt zur Zeit noch in seinem Gist <https://gist.github.com/jbeyerstedt/dc4dfe8859d3a274a19d>


## Dateiorganisation
Im Git:

- alle Dokumentation, die nicht ausschließlich für GPM ist
- alles an Code
- eigentlich alles, was zum Projekt gehört


In Dropbox:

- GPM-Statusberichte und GPM-only Dokumente (Teammanagementbarometer und co.)
- große Dateien, wie Filme
- Allgemeine Recherche
