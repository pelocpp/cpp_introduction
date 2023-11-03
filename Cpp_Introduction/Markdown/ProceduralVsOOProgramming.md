# Vergleich zwischen prozeduraler und objektorientierter Programmierung


[Zur�ck](Agenda.md)

---

## Erl�uterungen

### Was bedeutet &ldquo;prozedurale&rdquo; Programmierung

Der Programmierer l�st ein Problem mit Hilfe
von Prozeduren (Unterprogrammen). Er nutzt also Funktionen, die
er nach und nach aufruft, womit das Problem
am Ende gel�st wird

### Was bedeutet &ldquo;objektorientierte&rdquo; Programmierung

Der Programmierer l�st hier ein Problem, in dem er &ldquo;Objekte&rdquo; erstellt.

Objekte enthalten neben den Daten auch Funktionen (Methoden, letzten Endes Unterprogramme),
die auf den Daten operieren.
Ziel eines Objekts (genauer: einer Klasse, also die Beschreibung eines Objekts)
ist es, alles zu implementieren, was so in ein Objekt geh�rt.

Ist beispielweise ein Programm zu schreiben,
dass Umfang und Fl�che von Kreisen und
Quadraten berechnen soll, 
dann erstellt der &ldquo;objektorientierte&rdquo; Entwickler zun�chst
zwei Klassen `Circle` und `Square`,
die jeweils alle notwendigen Daten und Funktionen besitzen,
die f�r das Funktionieren eines Kreises (eines Quadrats) erforderlich sind.
Sowohl die Daten als auch die Funktionen sind in einer einzigen Datenstruktur
(`struct`, `class`) vorhanden.

### Vorteile der &ldquo;objektorientierten&rdquo; Programmierung

#### Kapselung vermeidet Namenskonflikte

Im folgenden Beispiel werden wir sehen,
dass es die Methoden `circumference()` (Umfang) und `area()` (Fl�che)
sowohl in der Klasse `Circle` als auch in der Klasse `Square` gibt.

Dennoch kommt es nicht zu einer Mehrdeutigkeit;
Wird die Methode `circumference()` �ber ein Objekt
der Klasse (des Typs) `Square` aufgerufen, dann wird auch
die Funktion dieser Klasse benutzt. 

Genauso verh�lt es sich mit einem Objekt der Klasse
`Circle`: Rufe man �ber ein Objekt dieser Klasse
die Funktion `circumference()` auf, dann wird eben diese aus der
Klasse `Circle` aufgerufen.


#### Methoden k�nnen auf die Instanzvariablen zugreifen

Da die Instanzvariable `m_radius` und die beiden Methoden
`circumference()` und `area()` 
in einer
Klassendefinition zusammengefasst sind,
k�nnen die Methoden *direkt* auf das
Datenelement `m_radius` zugreifen.
Der Programmierer muss diese Werte also nicht mehr extra als
Parameter �bergeben.


#### Kapselung erm�glich Schutz der Daten

Im folgenden Beispiel greifen wir auf die Instanzvariable `m_radius` und `m_lenght`
der beteiligten Objekte direkt zu. Es k�nnten bei falschen Eingabe damit
auch falsche Werte in das Objekt gelangen (zum Beispiel ein negativer Radius f�r einen Kreis).
Das muss aber so nicht sein.
�ber das Sprachmittel der Zugriffsklassen (PELO) gibt es neben `public`
eine weitere Zugriffsklasse `private`, die einen unkontrollierten Zugriff
auf Instanzvariable untersagt. Mehr dazu im folgenden Abschnitt (PELO).


## Beispiele


#### Datei *Example_Procedural_Programming.cpp*:

```cpp
01: const double Pi = 3.14159265358979323846;
02: 
03: // several functions (also called procedures)
04: double circumferenceCircle(double radius)
05: {
06:     return 2 * Pi * radius;
07: }
08: 
09: double areaCircle(double radius)
10: {
11:     return Pi * radius * radius;
12: }
13: 
14: double circumferenceSquare(double length)
15: {
16:     return 4 * length;
17: }
18: 
19: double areaSquare(double length)
20: {
21:     return length * length;
22: }
```

#### Datei *Example_OO_Programming.cpp*:

```cpp
01: const double Pi = 3.14159265358979323846;
02: 
03: class Circle
04: {
05: public:
06:     double m_radius;
07: 
08:     double circumference()
09:     {
10:         return 2 * m_radius * Pi;
11:     }
12: 
13:     double area()
14:     {
15:         return Pi * m_radius * m_radius;
16:     }
17: };
18: 
19: class Square
20: {
21: public:
22:     double m_length;
23: 
24:     double circumference()
25:     {
26:         return 4 * m_length;
27:     }
28: 
29:     double area()
30:     {
31:         return m_length * m_length;
32:     }
33: };
```

---

## Quellcode des Beispiels:

[Example_Procedural_Programming.cpp](..\ProceduralVsOOProgramming\Example_Procedural_Programming.cpp)<br />
[Example_OO_Programming.cpp](..\ProceduralVsOOProgramming\Example_OO_Programming.cpp)<br />
[Main.cpp](..\ProceduralVsOOProgramming\Main.cpp)

---


[Zur�ck](Agenda.md)

---
