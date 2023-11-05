# Technische Hinweise

[Zur�ck](../../Readme.md)

---

## Compiler / Entwicklungsumgebung

Das Repository wurde mit der &ndash;C++ Visual Studio Entwicklungsumgebung 2022&ndash; erstellt.
Alle Beispiel m�ssten aber auch mit dem GCC Compiler �bersetzungsf�hig sein.

---

## Mehrere Dateien desselben Namens

In diesem Projekt befinden sich viele Dateien mit demselben Namen wie
zum Beispiel `Main.cpp`, `Time.h` etc., nat�rlich in unterschiedlichen Verzeichnissen.

Nichtsdestotrotz legt der Visual C++ Compiler bzw. die Entwicklungsumgebung
die bei der �bersetzung resultierenden `.obj`-Dateien in einem Verzeichnis ab,
was nat�rlich zu Konflikten f�hrt.

Eine L�sung w�re es, alle Dateien des Projekts unterschiedlich zu benennen.
Da es beispielsweise sehr viele Varianten eines Entwurfs einer Klasse `Time` gibt,
w�rde dies zu sehr unsch�nen Namen wie `Time01.h`, `Time02.h`, etc. f�hren,
worunter die �bersichtlichkeit des Projekts doch sehr leidet.

Es gibt eine andere M�glichkeit:
In den Projekt-Einstellungen lassen sich dateispezifische Ablageorte
f�r derartige Konfliktdateien festlegen:

Man verwende

in der Eigenschaft

```
�Objektdateiname� (deutsche Visual Studio Installation)
```

bzw.

```
�Object File Name� (englische Visual Studio Installation)
```

den Wert

```
$(IntDir)\%(RelativeDir)\%(Filename)
```

Diese Einstellung findet man unter dem Pfad

*(Konfigurationseigenschaften -> C/C++ -> Ausgabedateien -> Objektdateiname)*

bzw.

*(Properties -> C/C++ -> Output Files -> Objektdateiname)*


Siehe hierzu auch *Abbildung* 1:

<img src="PropertyPages.png" width="600">

*Abbildung* 1: Einstellungen eines Visual Studio Projekts.


---

[Zur�ck](../../Readme.md)

---
