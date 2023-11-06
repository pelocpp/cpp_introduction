# Templates / Schablonen


[Zurück](Agenda.md)

---

## Erläuterungen

### Was sind Templates?

Häufig macht man als Entwickler die Beobachtung, dass bestimmte Methoden/Operationen
auf Werte unterschiedlichen Datentyps anwendbar sind.

So sind beispielsweise die Addition und Multiplikation für komplexe Zahlen (oder auch quadratische Matrizen)
genauso wie für reelle Zahlen oder ganze Zahlen definiert.

Die Vorgehensweise, die *add*-Funktion für einen Datentyp zu implementieren
und danach für alle anderen Datentypen zu kopieren und anzupassen, ist nicht nur umständlich,
sondern auch fehleranfällig.

Sind in einer Ausprägung der *add*-Funktion Änderungen notwendig,
so müssten diese in allen anderen Ausprägungen händisch nachgezogen werden.
Die Beseitigung von Fehlern ist ein weiterer Aspekt,
der sich negativ auf alle vorhandenen Funktionsausprägungen auswirkt.

Wir erkennen, dass sich Algorithmen oder auch Datenstrukturen, die auf gemeinsamen Eigenschaften
aufbauen, unabhängig vom speziellen Datentyp formulieren lassen sollten.

Damit sind wir bei der so genannten *Schablonentechnik* (engl. *Templates*) angekommen:

Mit dem C++-Sprachkonstrukt der *Templates*
ist es möglich, die Parameter einer Funktion, das Funktionsergebnis oder auch Instanzvariablen
einer Klasse ohne Festlegung eines konkreten Datentyps zu spezifizieren.

Erst bei der tatsächlichen Verwendung der Funktion (der Methode, der Klasse) 
muss dann der tatsächlich benötigte Datentyp festgelegt werden.

## Beispiele

Studieren Sie das folgende Beispiel in zwei Abschnitten.
Es werden zwei Taschenrechner betrachtet: Einer für `int`-Zahlen, ein zweiter für `double`-Zahlen.
Vergleichen Sie beide Realisierungen:

### Realisierung eines Taschenrechners für `int`- und `double`-Zahlen mit zwei Klassen

*Realisierung*:

```cpp
01: // implementation of two very similar calculator classes
02: class IntCalculator
03: {
04: public:
05:     static int add(int x, int y) { return x + y; }
06:     static int sub(int x, int y) { return x + y; }
07:     static int mul(int x, int y) { return x + y; }
08:     static int div(int x, int y) { return x + y; }
09: };
10: 
11: class DoubleCalculator
12: {
13: public:
14:     static double add(double x, double y) { return x + y; }
15:     static double sub(double x, double y) { return x + y; }
16:     static double mul(double x, double y) { return x + y; }
17:     static double div(double x, double y) { return x + y; }
18: };
```

*Anwendung*:

```cpp
01: void testCalculator()
02: {
03:     using namespace Templates;
04: 
05:     int result = IntCalculator::add(123, 456);
06:     std::cout << "IntCalculator: " << result << std::endl;
07: 
08:     double x = 123.456;
09:     double y = 654.321;
10:     double dresult = DoubleCalculator::add(x, y);
11:     std::cout << "DoubleCalculator: " << dresult << std::endl;
12: }
```

*Ausgabe*:


```
IntCalculator: 579
DoubleCalculator: 777.777
```


### Realisierung eines Taschenrechners für `int`- und `double`-Zahlen in einer Klasse


*Realisierung*:

```cpp
01: // implementation of a SINGLE calculator class - using templates technique
02: template <typename T>
03: class Calculator
04: {
05: public:
06:     static T add(T x, T y) { return x + y; }
07:     static T sub(T x, T y) { return x + y; }
08:     static T mul(T x, T y) { return x + y; }
09:     static T div(T x, T y) { return x + y; }
10: };
```

*Anwendung*:

```cpp
01: void testCalculator()
02: {
03:     using namespace Templates;
04: 
05:     int result = Calculator<int>::add(123, 456);
06:     std::cout << "Calculator<int>: " << result << std::endl;
07: 
08:     double x = 123.456;
09:     double y = 654.321;
10:     double dresult = Calculator<double>::add(x, y);
11:     std::cout << "Calculator<double>: " << dresult << std::endl;
12: }
```

*Ausgabe*:


```
Calculator<int>: 579
Calculator<double>: 777.777
```

---

## Quellcode des Beispiels:

[Main.cpp](../Templates/Main.cpp)

---


## Übungen

TBD: TBD  // Klasse Array


---


[Zurück](Agenda.md)

---
