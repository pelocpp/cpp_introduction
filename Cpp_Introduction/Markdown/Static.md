# Statische Datenelemente (`static`)


[Zurück](Agenda.md)

---

## Erläuterungen

### Statische Datenelemente (`static`)

Bis jetzt haben wir die Daten von Klassen als exklusive Daten der einzelnen Objekten gesehen und nicht als gemeinsam
genutzte Daten zwischen mehreren Objekten.

Wenn wir zum Beispiel fünf `Time`-Objekte erzeugt haben,
verfügt jedes Objekt über eigene Variablen für Stunden, Minuten und Sekunden.

Die Stundenanzahl des einen Objekts beeinflußt nicht die Stundenanzahl eines anderen Objekts.

Für den Entwurf der Klasse `Time` haben wir die Konzeption auch richtig gemacht,
aber wie sieht es aus, wenn wir &ndash; beispielsweise in einem mathematisch angehauchten Umfeld &ndash; die Kreiszahl *Pi*
ins Spiel bringen wollen?

Etwa auf diese Weise?


```cpp
01: class Math
02: {
03: private:
04:     double m_pi;
05: 
06: public:
07:     Math()
08:     {
09:         m_pi = 3.14159265358979323846;
10:     }
11: 
12:     double Pi() { return m_pi; }
13: };
14: 
15: void testViolatingStatic()
16: {
17:     Math math;
18: 
19:     double radius = math.Pi() * 2.0 * 2.0;
20: }
```

Welche Nachteile besitzt diese Lösung?


Manchmal möchte man aber Daten verwalten, die alle Objekte einer Klasse gemeinsam nutzen.

Für einen Wert wie die Zahl *Pi* ergibt es keinen Sinn,
in beiebig vielen Objekten einer Klasse `Math` denselben Wert (und damit eine Kopie) bereitzustellen.

Im Gegensatz zu normalen Elementvariablen werden statische Elementvariablen von allen Instanzen einer Klasse
gemeinsam genutzt.

Sie bilden einen Kompromiß zwischen globalen Daten, die allen Teilen eines Programms zur Verfügung
stehen, und Datenelementen, die normalerweise nur in einem einzelnen Objekt verfügbar sind.


### Statische Datenelemente (`static`)


Statische Elementfunktionen sind vergleichbar mit statischen Elementvariablen: Sie existieren nicht in einem Objekt,
sondern im Gültigkeitsbereich der Klasse.

Demzufolge kann man sie aufrufen, ohne ein Objekt der Klasse verfügbar haben zu müssen.


## Beispiele


```cpp
01: class Math
02: {
03: public:
04:     static const double Pi;
05: };
06: 
07: double const Math::Pi = 3.14159265358979323846;
08: 
09: void testMotivatingStatic()
10: {
11:     double radius = Math::Pi * 2.0 * 2.0;
12: }
```


```cpp
01: class Calculator
02: {
03: public:
04:     static int add(int x, int y) { return x + y; }
05:     static int sub(int x, int y) { return x + y; }
06:     static int mul(int x, int y) { return x + y; }
07:     static int div(int x, int y) { return x + y; }
08: };
09: 
10: void testMotivatingStatic()
11: {
12:     int sum = Calculator::add(123, 456);
13: }
```


---

## Quellcode des Beispiels:

[Main.cpp](../Static/Main.cpp)

---


## Übungen

TBD: Rectangle


---


[Zurück](Agenda.md)

---
