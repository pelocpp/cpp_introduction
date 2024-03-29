# Vertiefungen zu Klassen und Objekten


[Zur�ck](Agenda.md)

---

## Erl�uterungen

Wir gehen in diesem Abschnitt auf mehrere zentrale Prinzipien der objektorientierten Programmierung ein:

  * Zugriffsschutz und Kapselung
  * *getter*- und *setter*-Methoden
  * Der `this`-Operator

### Zugriffsschutz und Kapselung

Das erste Beispiel in der Entwicklung einer Klasse `Time`
verstie� gegen ein fundamentales Paradigma der objektorientierten Programmierung:

> Ein Objekt besitzt zu **jedem** Zeitpunkt g�ltige Werte (in seinen Instanzvariablen).

Mit zwei einfachen Anweisungen der Gestalt

```cpp
Time t;
t.m_hours = 99999;
```

k�nnten wir dieses Paradigma einfach au�er Kraft setzen.

Ein zentrales Prinzip der objektorientierten Programmierung ist die so genannte *Kapselung*.
Der Benutzer einer Klasse soll nur auf die Elemente einer *�ffentlichen Schnittstelle* zugreifen k�nnen,
die typischerweise durch die Methoden (und Konstruktoren) zum Ausdruck kommt.

Die Daten sind im Gegensatz dazu vor dem Zugriff von au�en zu sch�tzen.
W�rde es keine M�glichkeit geben, den Zugriff auf die Daten (als auch Teile der Instanzmethoden) einzuschr�nken
oder gar zu unterbinden, k�nnte man Anweisungen wie die des zuletzt gezeigten
Codefragments nicht unterbinden.

Die Kapselung der Daten eines Objekts, sprich der Zugriffsschutz, wird mit den Schl�sselw�rtern
`private`, `public` und `protected` erreicht.
Steht innerhalb einer Klassendeklaration eines der zuvor erw�hnten Schl�sselw�rter (gefolgt von einem Doppelpunkt),
so wird der Zugriff aller nachfolgend deklarierten Daten und Methoden wie folgt gesch�tzt:

* Zugriffsklasse `private`:<br />
  Alle nachfolgenden Deklarationen nehmen einen *privaten* Status innerhalb der Klasse ein.
  Dies bedeutet, dass auf die so markierten Elemente der Klasse nur von Instanzmethoden *derselben* Klasse
  zugegriffen werden kann.
  Methoden, die nicht in dieser Klasse deklariert sind, haben folglich keinerlei M�glichkeit, auf die privat deklarierten Elemente dieser Klasse
  zuzugreifen!

* Zugriffsklasse `public`:<br />
  Alle Deklarationen, die auf dieses Schl�sselwort folgen,
  nehmen einen *�ffentlichen* Status ein, d.h. auf sie kann von *�berall* aus im Programm zugegriffen werden.
  Kurzum: Alle so deklarierten Elemente unterliegen in einem C++-Programm keinerlei Zugriffsbeschr�nkungen.
  
* Zugriffsklasse `protected`:<br />
  Die Anwendung des Zugriffsspezifizierers `protected` ist nur in einer Vererbungshierarchie sinnvoll,
  wir kommen auf seine Bedeutung im Abschnitt der [Vererbung](Inheritance.md) zu sprechen.

#### Datei [*Time.h*](../ClassesObjectsImproved/Time.h):

```cpp
01: class Time
02: {
03: private:
04:     int m_hours;
05:     int m_minutes;
06:     int m_seconds;
07: 
08: public:
09:     // public interface
10:     void reset();
11:     void increment();
12:     void decrement();
13:     void print();
14: };
```

### *getter*/*setter*-Methoden

Mit der Einf�hrung der Zugriffsklassen haben wir den direkten Zugriff auf Instanzvariablen verloren,
die mit dem Zugriffsspezifizierer `private` definiert sind.
Unterbinden wir eine Anweisung der Gestalt

```cpp
Time t;
t.m_hours = 99999;
```

dann stehen wir aber vor dem Problem, dass m�glicherweise korrekte Anweisungen wie zum Beispiel

```cpp
Time t;
t.m_hours = 12;
```

auch nicht mehr gehen. 

Nat�rlich muss es dennoch m�glich sein, den Zustand eines Objekts ver�ndern zu k�nnen.
Da der Ausgangspunkt f�r die Einf�hrung der Zugriffsklassen in der Wahrung der Integrit�t eines Objekts liegt,
sind Klassen nun um eine oder mehrere
spezielle &ndash; mit der Zugriffsklassen `public` versehene &ndash; Zugriffsmethoden zu definieren.

Diese als *getter*- bzw. *setter* bezeichnete Methoden erm�glichen nun
einerseits den Zugriff auf die &ndash; privat deklarierten &ndash; Instanzvariablen,
behalten aber andererseits die Integrit�t des Objekts im Hinterkopf.

Der Umweg �ber diese Zugriffsmethoden bewirkt somit einen ausschlie�lich *kontrollierten* Zugriff auf das Objekt:

#### Datei [*Time.h*](../ClassesObjectsImproved/Time.h):

```cpp
01: class Time
02: {
03: private:
04:     int m_hours;
05:     int m_minutes;
06:     int m_seconds;
07: 
08: public:
09:     // getter // setter
10:     int getHours() { return m_hours; }
11:     int getMinutes() { return m_minutes; }
12:     int getSeconds() { return m_seconds; }
13:     void setHours(int hours);
14:     void setMinutes(int minutes);
15:     void setSeconds(int seconds);
16: 
17:     // public interface
18:     ...
19: };
```

#### Datei [*Time.cpp*](../ClassesObjectsImproved/Time.cpp):

```cpp
01: // setter
02: void Time::setHours(int hours)
03: {
04:     if (0 <= hours && hours < 24) {
05:         m_hours = hours;
06:     }
07:     else {
08:         // we don't modify the current value of 'm_hours'
09:         std::cout << "Wrong value for hours: " << hours << std::endl;
10:     }
11: }
12: 
13: void Time::setMinutes(int minutes)
14: {
15:     if (0 <= minutes && minutes < 60) {
16:         m_minutes = minutes;
17:     }
18:     else {
19:         // we don't modify the current value of 'm_minutes'
20:         std::cout << "Wrong value for minutes: " << minutes << std::endl;
21:     }
22: }
23: 
24: void Time::setSeconds(int seconds)
25: {
26:     if (0 <= seconds && seconds < 60) {
27:         m_seconds = seconds;
28:     }
29:     else {
30:         // we don't modify the current value of 'm_seconds'
31:         std::cout << "Wrong value for seconds: " << seconds << std::endl;
32:     }
33: }
```

#### Datei [*Main.cpp*](../ClassesObjectsImproved/Main.cpp) - Testrahmen:

```cpp
01: void testClassTimeImproved()
02: {
03:     Time now;
04:     now.setHours(10);
05:     now.setMinutes(20);
06:     now.setSeconds(30);
07:     now.print();
08: 
09:     // now.m_hours = 9999;   // doesn't compile
10: 
11:     now.increment();
12:     now.print();
13: 
14:     now.decrement();
15:     now.print();
16: 
17:     Time what;
18:     what.setHours(9999);
19:     what.print();            // watch output carefully
20: }
```


### Der `this`-Operator

Wir betrachten f�r einen Moment eine geringf�gig modifizierte
Realisierung unserer Klasse `Time`:

```cpp
01: class Time
02: {
03: private:
04:     int hours;
05:     int minutes;
06:     int seconds;
07: 
08: public:
09:     // setter
10:     void setHours(int hours);
11: };
```

Im Prinzip geht es nur um die Betrachtung von Bezeichnern,
die f�r Instanzvariablen und Parameter von Methoden verwendet werden k�nnen.

M�glichweise erkennen Sie schon ein kleines Problem beim Betrachten des Code-Fragments?
Lassen Sie mich versuchen, den *setter* f�r den Stundenanteil zu realisieren:

```cpp
01: void Time::setHours(int hours)
02: {
03:     if (0 <= hours && hours < 24) {
04:         hours = hours;
05:     }
06:     else {
07:         // some error handling ...
08:     }
09: }
```

Erkennen Sie in Zeile 4 das Problem? Richtig, der Bezeichner `hours` wird zweimal verwendet:

  * Als Instanzvariable der Klasse `Time`
  * Als Parameter der *setter*-Methode `setHours`

Interessanterweise ist das letzte Code-Fragment �bersetzungsf�hig, aber l�uft es auch korrekt?

Nein, es wird in dieser Situation die Instanzvariable durch den Parameter verdeckt!

M�gliche Abhilfen:

  * Unterschiedliche Bezeichner f�r Instanzvariablen und Parameter von Methoden.
  * Gebrauch des `this`-Operators.

Mit dem `this`-Operator k�nnte man die *setter*-Methode korrekt realisieren:

<pre>
01: void Time::setHours(int hours)
02: {
03:     if (0 <= hours && hours < 24) {
04:         <b>this->hours</b> = hours;
05:     }
06:     else {
07:         // some error handling ...
08:     }
09: }
</pre>

---

## Quellcode des Beispiels:

[*Time.h*](../ClassesObjectsImproved/Time.h)<br />
[*Time.cpp*](../ClassesObjectsImproved/Time.cpp)<br />
[*Main.cpp*](../ClassesObjectsImproved/Main.cpp)

---

## Aufgaben

[Aufgabe zur Klasse `Rectangle`](../Exercises/Exercises_Rectangle.md)

[Aufgabe zur Klasse `BankAccount`](../Exercises/Exercises_BankAccount.md)

---

[Zur�ck](Agenda.md)

---
