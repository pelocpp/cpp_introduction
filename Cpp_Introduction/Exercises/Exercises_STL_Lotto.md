# Aufgabe zur STL: Ziehung der Lottozahlen &ndash; Klasse `Lottery` (inklusive Iteratoren-Konzept)

[Zur�ck](./Exercises.md)

---

## �bersicht

Folgende C++&ndash;Sprachmittel sollen zum Einsatz kommen:
  * Entwicklung einer Anwendung &ndash; Ziehung der Lottozahlen &ndash; mit der STL (*Standard Template Library*)
  * Einsatz eines sequentiellen STL-Containers in einer Klasse `Lottery` (hier: Klasse `std::vector`)
  * Realisierung des STL Iteratoren-Konzepts am Beispiel der Klasse  `Lottery`
  * Anwendung elementarer STL Algorithmen (`std::find_if` und `std::for_each`)


## Beschreibung

In dieser Aufgabe simulieren wir eine Ziehung der Lottozahlen.
Zur Ablage der bereits gezogenen Lottozahlen setzt die Klasse `Lottery` einen STL-Container `std::vector` ein.

Zur Strukturierung der Klasse `Lottery` realisieren Sie die folgenden, in *Tabelle* 1 beschriebenen
�ffentlichen und privaten Methoden.


| Methode        | Schnittstelle und Beschreibung |
|:-------------- |:-----------------------------------------|
| `getDrawnNumbers` | `size_t getDrawnNumbers() const;`<br/>Liefert die Anzahl der bereits gezogenen Kugeln zur�ck. |
| `nextRandomNumber` | `int nextRandomNumber();`<br/> Ermittelt eine Zufallszahl zwischen 1 und 49. In dieser Methode werden Details zur Generierung einer Zufallszahl verborgen. Sollte eine Zahl mehrfach erzeugt werden, spielt das in dieser Methode keine Rolle. |
| `drawNextNumber` | `int drawNextNumber();`<br/>Ziehung der n�chsten Kugel. Mit Hilfe der Instanzvariablen der umgebenden Klasse `Lottery` achtet diese Methode darauf, dass keine Kugel doppelt gezogen wird. |
| `numberAlreadyDrawn` | `bool numberAlreadyDrawn(int number);`<br/>Hilfsmethode, die zu einer zuf�llig erzeugten Zahl `number` bestimmt, ob diese Zahl (Kugel) schon einmal gezogen worden ist oder nicht. |
| `print` | `void setNextNumber(int number);`<br/>Hilfsmethode, die Kugel `number` in den Instanzvariablen der umgebenden `Lottery`-Klasse als gezogene Kugel ablegt. |
| `play` | `void play();`<br/>Simuliert eine Ziehung der Lottozahlen. Die zuvor beschriebenen Methoden sind geeignet aufzurufen. |
| `print` | `void print();`<br/>Gibt das Ergebnis einer Ziehung der Lottozahlen in der Konsole aus. |

*Tabelle* 1: Beschreibung der �ffentlichen und privaten Methoden der Klasse `Lottery`.


## Iteratoren-Konzept

Man kann &ndash; mit einer gewissen Phantasie &ndash; eine Instanz der Klasse `Lottery` als C++-Container auffassen.
Unabh�ngig davon, wieviele Kugeln in einer Ziehung der Lottozahlen bereits gezogen worden sind,
k�nnte man diese bereits gezogenen Kugeln &bdquo;iterieren&rdquo;.

Verwenden Sie eine Iteration, um die komplette Ziehung der Zahlen auf diese Weise zu durchlaufen:

```cpp
01: Lottery lottery;
02: for (int number : lottery) {
03:     std::cout << "> " << number << std::endl;
04: }
```

In diesem Beispiel kommt eine *Range-based* `for`-Wiederholungsschleife zum Einsatz.
Alternativ k�nnte man auch den STL-Algorithmus `std::for_each` verwenden.


---

## Quellcode der L�sungen:

[*Lottery.h*](./STL_Lotto/Lottery.h)<br />
[*Lottery.cpp*](./STL_Lotto/Lottery.cpp)<br />
[*Lottery_Main_.cpp*](./STL_Lotto/Lottery_Main_.cpp)<br />

---

[Zur�ck](./Exercises.md)

---
