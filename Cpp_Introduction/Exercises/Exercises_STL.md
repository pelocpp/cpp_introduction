# STL - Zwei einführende Aufgaben

[Zurück](./Exercises.md)

---

## Übersicht

Es werden zwei einfache Beispiele zu den Basiskonstrukten der STL betrachtet.

## Beschreibung

### Teuflische Zahlenfolge

Die Teuflische Zahlenfolge, auch als &ldquo;3*n* + 1&rdquo;-Vermutung oder *Collatz*-Problem bezeichnet, ist ein ungelöstes mathematisches
Problem und wird dem Mathematiker *Lothar Collatz* zugeschrieben. Bei dem Problem geht es um
Zahlenfolgen, die nach einem einfachen Bildungsgesetz konstruiert werden. Gegeben ist eine
beliebige natürliche Startzahl *n*, aus der sich eine Folge von Zahlen nach den folgenden zwei Regeln bildet:

  * Ist die Zahl *n* gerade, so ist die nächste Zahl gleich der Hälfte der Zahl.
  * Ist die Zahl ungerade, so wird die Zahl mal Drei multipliziert und um 1 erhöht.

Merkwürdigerweise erreicht diese Folge nach endlich vielen Schritten immer die Zahl 1. Man kann
die Vermutung auch so betrachten: Jede Folge mündet in den Zyklus 4, 2, 1 &ndash; egal, mit welcher
Startzahl man die Folge gestartet hat. Wählen wir zum Beispiel den Startwert 7, so lautet die Folge

7, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1.

Bis heute konnte das Collatz-Problem mathematisch nicht bewiesen werden.
Auch konnte man mit Hilfe von Computerprogrammen die Vermutung bis heute nur unterstützen,
aber nicht widerlegen. Alle Startzahlen bis ca. 5,76 * 1018 untermauern die Vermutung (Stand Januar 2009).

Erstellen Sie ein Programm, das beginnend mit einem festen Startwert die einzelnen Elemente
berechnet und auf der Konsole ausgibt. Setzen Sie einen geeigneten STL-Container Ihrer Wahl ein.


### Fibonacci Zahlen

In der Mathematik bilden die *Fibonacci*-Zahlen eine Folge,
so dass jede Zahl die Summe der beiden vorhergehenden Zahlen ist, beginnend mit 0 und 1. 
Für die *n*.-te Fibonacci F<sub>*n*</sub> bedeutet das F<sub>*n*</sub> = F<sub>*n*-1</sub> + F<sub>*n*-2</sub>,
wobei F<sub>0</sub> = 0 und F<sub>1</sub> = 1 gelten.
Die durch Fibonacci-Zahlen gebildete Sequenz wird als *Fibonacci*-*Sequenz* bezeichnet.

Verwenden Sie in dieser Aufgabe den Algorithmus `std::generate` mit
einem geeigneten Funktionsobjekt,
um die *Fibonacci*-Zahlen zu berechnen. Die Größe des Containers, der an `std::generate` 
in den ersten beiden Parametern übergeben wird (Start- und Ende-Iterator), entscheidet, 
wieviele *Fibonacci*-Zahlen zu berechnen sind.

Die ersten zwei Werte 0 und 1 der Zahlenfolge sind im beteiligten Funktionsobjekt geeignet ablegen.
Von Aufruf zu Aufruf des Funktionsobjekts können Sie die beiden Werte geeignet modifizieren:

  * Das erste Element des neuen Paares ist das zweite Element des alten Paares.
  * Das zweite Element des neuen Paares ist die Summe der beiden Elemente des alten Paares.


*Kleine Hilfestellung*:<br />
Die ersten 20 *Fibonacci*-Zahlen lauten

```
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181
```

---

## Quellcode der Lösungen:

[*STL_Main.cpp*](./STL/STL_Main.cpp)

---

[Zurück](./Exercises.md)

---
