# Vergleich zwischen prozeduraler und objektorientierter Programmierung


[Zurück](Agenda.md)

---

## Erläuterungen

### Was bedeutet &ldquo;prozedurale&rdquo; Programmierung

Der Programmierer löst ein Problem mit Hilfe
von Prozeduren (Unterprogrammen). Er nutzt also Funktionen, die
er nach und nach aufruft, womit das Problem
am Ende gelöst wird.

### Was bedeutet &ldquo;objektorientierte&rdquo; Programmierung

Der Programmierer löst hier ein Problem, in dem er &ldquo;Objekte&rdquo; erstellt.

Objekte enthalten neben den Daten auch Funktionen (Methoden, letzten Endes Unterprogramme),
die auf den Daten operieren.
Ziel eines Objekts (genauer: einer Klasse, also die Beschreibung eines Objekts)
ist es, alles zu implementieren, was so in ein Objekt gehört.

Ist beispielweise ein Programm zu schreiben,
dass Umfang und Fläche von Kreisen und
Quadraten berechnen soll, 
dann erstellt der &ldquo;objektorientierte&rdquo; Entwickler zunächst
zwei Klassen `Circle` und `Square`,
die jeweils alle notwendigen Daten und Funktionen besitzen,
die für das Funktionieren eines Kreises (eines Quadrats) erforderlich sind.
Sowohl die Daten als auch die Funktionen sind in einer einzigen Datenstruktur
(`struct`, `class`) vorhanden.

### Vorteile der &ldquo;objektorientierten&rdquo; Programmierung

#### Kapselung vermeidet Namenskonflikte

Im folgenden Beispiel werden wir sehen,
dass es die Methoden `circumference()` (Umfang) und `area()` (Fläche)
sowohl in der Klasse `Circle` als auch in der Klasse `Square` gibt.

Dennoch kommt es nicht zu einer Mehrdeutigkeit;
Wird die Methode `circumference()` über ein Objekt
der Klasse (des Typs) `Square` aufgerufen, dann wird auch
die Funktion dieser Klasse benutzt. 

Genauso verhält es sich mit einem Objekt der Klasse
`Circle`: Rufe man über ein Objekt dieser Klasse
die Funktion `circumference()` auf, dann wird eben diese aus der
Klasse `Circle` aufgerufen.


#### Methoden können auf die Instanzvariablen zugreifen

Da die Instanzvariable `m_radius` und die beiden Methoden
`circumference()` und `area()` 
in einer
Klassendefinition zusammengefasst sind,
können die Methoden *direkt* auf das
Datenelement `m_radius` zugreifen.
Der Programmierer muss diese Werte also nicht mehr extra als
Parameter übergeben.


#### Kapselung ermöglich Schutz der Daten

Im folgenden Beispiel greifen wir auf die Instanzvariable `m_radius` und `m_length`
der beteiligten Objekte direkt zu. Es könnten bei falschen Eingabe damit
auch falsche Werte in das Objekt gelangen (zum Beispiel ein negativer Radius für einen Kreis).
Das muss aber so nicht sein.
Über das Sprachmittel der *Zugriffsklassen* gibt es neben `public`
eine weitere Zugriffsklasse `private`, die einen unkontrollierten Zugriff
auf Instanzvariablen untersagt. Mehr dazu im
Abschnitt &ldquo;[*Vertiefungen zu Klassen und Objekten*](../Markdown/ClassesObjectsImproved.md)&rdquo;.

## Beispiele

#### Datei [*Example_Procedural_Programming.cpp*](../ProceduralVsOOProgramming/Example_Procedural_Programming.cpp)*:


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

#### Datei [*Example_Procedural_Programming.cpp* - Testrahmen](../ProceduralVsOOProgramming/Example_Procedural_Programming.cpp)*:

Ein Testrahmen zur prozeduralen Programmierung:

```cpp
01: void testComparisonProcedural()
02: {
03:     double radius;
04:     double seite;
05: 
06:     std::cout << "Enter a Radius: ";
07:     std::cin >> radius;
08: 
09:     std::cout << "Circumference: " << circumferenceCircle(radius) << std::endl;
10:     std::cout << "Area: " << areaCircle(radius) << std::endl << std::endl;
11: 
12:     std::cout << "Enter Length: ";
13:     std::cin >> seite;
14: 
15:     std::cout << "Circumference: " << circumferenceSquare(seite) << std::endl;
16:     std::cout << "Area: " << areaSquare(seite) << std::endl;
17: }
```

#### Datei [*Example_OO_Programming.cpp*](../ProceduralVsOOProgramming/Example_OO_Programming.cpp)*:


```cpp
01: const double Pi = 3.14159265358979323846;
02: 
03: class Circle
04: {
05: private:
06:     double m_radius;
07: 
08: public:
09:     Circle()
10:     {
11:         m_radius = 0;
12:     }
13: 
14:     void setRadius(double radius)
15:     {
16:         if (radius > 0) {
17:             m_radius = radius;
18:         }
19:     }
20: 
21:     double circumference()
22:     {
23:         return 2 * m_radius * Pi;
24:     }
25: 
26:     double area()
27:     {
28:         return Pi * m_radius * m_radius;
29:     }
30: };
31: 
32: class Square
33: {
34: private:
35:     double m_length;
36: 
37: public:
38:     Square()
39:     {
40:         m_length = 0;
41:     }
42: 
43:     void setlength(double length)
44:     {
45:         if (length > 0) {
46:             m_length = length;
47:         }
48:     }
49: 
50:     double circumference()
51:     {
52:         return 4 * m_length;
53:     }
54: 
55:     double area()
56:     {
57:         return m_length * m_length;
58:     }
59: };
```

#### Datei [*Example_OO_Programming.cpp* - Testrahmen](../ProceduralVsOOProgramming/Example_OO_Programming.cpp)*:

Ein Testrahmen zur objektorientierten Programmierung:

```cpp
01: void testComparisonOO()
02: {
03:     Circle circle;
04:     Square square;
05: 
06:     std::cout << "Enter Radius of Circle: ";
07:     double radius;
08:     std::cin >> radius;
09:     circle.setRadius(radius);
10:     
11:     std::cout << "Circumference of Circle: " << circle.circumference() << std::endl;
12:     std::cout << "Area of Circle: " << circle.area() << std::endl;
13:     
14:     std::cout << std::endl << "Enter Side Length of Square: ";
15:     double length;
16:     std::cin >> length;
17:     square.setlength(length);
18:     
19:     std::cout << "Circumference of Square: " << square.circumference() << std::endl;
20:     std::cout << "Area of Square: " << square.area() << std::endl;
21: }
```

---

## Quellcode des Beispiels:

[*Example_Procedural_Programming.cpp*](../ProceduralVsOOProgramming/Example_Procedural_Programming.cpp)<br />
[*Example_OO_Programming.cpp*](../ProceduralVsOOProgramming/Example_OO_Programming.cpp)<br />
[*Main.cpp*](../ProceduralVsOOProgramming/Main.cpp)

---

[Zurück](Agenda.md)

---
