# Aufgabe zur Klasse `Rectangle`

[Zur�ck](./Exercises.md)

---

## �bersicht

Folgende C++&ndash;Sprachmittel sollen zum Einsatz kommen:

  * Klasse und Objekt
  * Konstruktoren
  * Zugriffsrechte (`private`, `public`)
  * *getter*/*setter*-Methoden
  * Realisierung einfacher Methoden
  * Objekte als R�ckgabewert von Methoden

## Beschreibung

Definieren und implementieren Sie eine Klasse `Rectangle`,
die ein Rechteck im Sinne des kartesischen Koordinatensystems beschreibt.
Das Rechteck soll dabei durch einen Punkt (*x*,*y*) festgelegt werden,
der die linke obere Ecke beschreibt sowie zwei weiteren Angaben zur Breite und H�he des Rechtecks.

Folgende Anforderungen an die Klasse `Rectangle` sind mit geeigneten programmiersprachlichen Konstrukten umzusetzen:

* Bei der Erzeugung eines `Rectangle`-Objekts mit dem Standard-Konstruktor werden alle Instanzvariablen auf den Wert 0 gesetzt.

* Bei der Erzeugung eines `Rectangle`-Objekts mit einem benutzerdefinierten Konstruktor werden die Koordinaten, die Breite und die H�he des Rechtecks
  entsprechend der Parameter des Konstruktors gesetzt.

* Erg�nzen Sie die Klasse um *getter*- und *setter*-Methoden zum Lesen und Schreiben aller Instanzvariablen des Rechtecks.

* Schreiben Sie eine Methode `print` zur Ausgabe der Daten eines Rechtecks in der Konsole.

* Schreiben Sie eine Methode `moveTo`, die ein Rechteck in *x*- und/oder *y*-Richtung verschieben kann:

<pre>
  Rectangle rect(10, 10, 20, 30);
  rect.moveTo(3, 6);
</pre>

  Das Rechteck `rect` wird um 3 in *x*- und 6 in *y*-Richtung verschoben.

* Schreiben Sie eine Methode `circumference` zur Berechnung des Umfangs eines Rechtecks.

* Die Methode `diagonal` berechnet die L�nge der Diagonalen des Rechtecks.

* Schreiben Sie eine Methode `area` zur Berechnung der Rechteckfl�che.

* Die Methode `isSquare` �berpr�ft, ob das Rechteck ein Quadrat ist oder nicht.

*Beispiel*:

<pre>
Rectangle rect(5, 5, 10, 20);
std::cout << rect << std::endl;
std::cout << "Circumference: " << rect.circumference() << std::endl;
std::cout << "Diagonal:      " << rect.diagonal() << std::endl;
std::cout << "Area:          " << rect.area() << std::endl;
std::cout << "IsSquare:      " << rect.isSquare() << std::endl;
</pre>


* Schreiben Sie eine Methode `center`, die den Punkt im Zentrum des Rechtecks berechnet.
  Zur R�ckgabe des Ergebnisses k�nnen Sie eine Klasse `Point` definieren,
  die von der `center`-Methode als R�ckgabetyp verwendet wird.

* Schreiben Sie eine Methode `intersection`, die ein zweites `Rectangle`-Objekt als Parameter �bergeben bekommt
  und dasjenige Rechteck berechnet, das die beiden Rechtecke gemeinsam haben.
  Das Resultat-Rechteck ist als R�ckgabewert der `intersection`-Methode zur�ckzuliefern.

---

## Quellcode der L�sungen:

[*Point.h*](./Rectangle/Point.h)<br />
[*Point.cpp*](./Rectangle/Point.cpp)<br />
[*Rectangle.h*](./Rectangle/Rectangle.h)<br />
[*Rectangle.cpp*](./Rectangle/Rectangle.cpp)<br />
[*Rectangle_Main.cpp*](./Rectangle/Rectangle_Main.cpp)<br />

---

[Zur�ck](./Exercises.md)

---
