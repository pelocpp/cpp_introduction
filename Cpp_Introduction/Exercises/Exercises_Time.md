# Aufgabe zur Klasse `Time`

[Zurück](./Exercises.md)

---

## Übersicht

In dieser Aufgabe entwerfen wir für Objekte, die eine Uhrzeit mit Stunden-, Minuten- und Sekundenanteil repräsentieren,
eine geeignete Klasse `Time`. Die Stunde kann Werte zwischen 0 und 23 einnehmen,
die Minuten und Sekunden Werte zwischen 0 und 59.


### Beschreibung

Weitere Hinweise zur Spezifikation einer Klasse `Time` finden Sie in den nachfolgenden Hinweisen vor:

####  Konstruktoren

```cpp
Time ();
Time (int seconds, int minutes, int hours);
Time (int seconds);
Time (const char*);
```

*Hinweise*:
Neben dem Standardkonstruktur besitzt die Klasse mehrere benutzerdefinierte Konstruktoren.
Mit ihnen kann man ein `Time`-Objekt mit drei Werten `seconds`, `minutes` und `hours` vorbelegen
oder man gibt nur einen Sekundenwert &ndash; im Bereich von 0 bis 86400 &ndash; vor.
Alternativ lässt sich eine Uhrzeit auch durch eine Zeichenkette des Formats `"hh:mm:ss"` spezifizieren.

####  Methoden

```cpp
void reset ();
void add (const Time&);
void sub (const Time&);
Time diff (const Time&) const;
void increment ();
void decrement ();
```

*Hinweise*:

Mit `add` und `sub` lassen sich zwei Uhrzeiten addieren bzw. subtrahieren.
Ein eventueller Über- bzw. Unterlauf ist zu berücksichtigen.
Die `diff`-Methode berechnet die Differenz zweier Uhrzeiten und stellt das Ergebnis
wieder in einem `Time`-Objekt bereit. Mit der `reset`-Methode werden alle drei Werte einer Uhrzeit auf 0 gestellt,
zum Addieren oder Subtrahieren einer einzelnen Sekunde gibt es die zwei Methoden `increment` bzw. `decrement`.


####  Arithmetische Operatoren

```cpp
// arithmetic operators
Time operator+ (const Time&) const;
Time operator- (const Time&) const;

// arithmetic-assignment operators
Time operator+= (const Time&);
Time operator-= (const Time&);
Time operator+= (int seconds);
Time operator-= (int seconds);

// increment / decrement operators
friend Time& operator++ (Time&);           // prefix increment
friend const Time operator++ (Time&, int); // postfix increment
friend Time& operator-- (Time&);           // prefix decrement
friend const Time operator-- (Time&, int); // postfix decrement
```

*Hinweise*:

Die Funktionsweise der Operatoren ist weitestgehend
selbsterklärend &ndash; die beiden Operatoren `++` und `--` arbeiten analog wie `increment` bzw. `decrement`.


####  Vergleichsoperatoren

```cpp
friend bool operator== (const Time&, const Time&);
friend bool operator!= (const Time&, const Time&);
friend bool operator<= (const Time&, const Time&);
friend bool operator<  (const Time&, const Time&);
friend bool operator>= (const Time&, const Time&);
friend bool operator>  (const Time&, const Time&);
```

*Hinweise*:

Vergleich zweier Uhrzeiten.

####  Konvertierungsoperator

```cpp
operator int();
```

*Hinweise*:

Vergleich zweier Uhrzeiten.

####  Ein- und Ausgabe

```cpp
friend ostream& operator<< (ostream&, const Time&);
friend istream& operator>> (istream&, Time&);
```

*Hinweise*:

Ein- und Ausgabe eines `Time`-Objekts in C++&ndash;Manier. Die Ausgabe sollte sich am Format `"hh:mm:ss"` orientieren,
bei einstelligen Werten ist eine führende Null voranzustellen.

Es folgen einige Beispiele, um die Umsetzung der einzelnen Klassenelemente besser zu veranschaulichen.
Wir beginnen mit den Konstruktoren:

*Beispiel*:

```cpp
// testing c'tors
Time t1;
std::cout << t1 << std::endl;
Time t2 (0, 30, 12);
std::cout << t2 << std::endl;
Time t3 ("09:30:00");
std::cout << t3 << std::endl;
Time t4 (24*60*60 - 1);
std::cout << t4 << std::endl;
```

*Ausgabe*:

```
00:00:00
12:30:00
09:30:00
23:59:59
```

*Beispiel*: Codefragment zum Testen der `add`-Methode:

```cpp
// testing 'add'
Time t1 (0, 0, 12);
Time t2 (33, 33, 3);
for (int i = 0; i < 5; i ++)
{
    t1.add (t2);
    std::cout << t1 << std::endl;
}
```

*Ausgabe*:

```
15:33:33
19:07:06
22:40:39
02:14:12
05:47:45
```

*Beispiel*: Codefragment zum Testen der `increment`-Methode:

```cpp
// testing 'increment'
Time t (55, 59, 23);
for (int i = 0; i < 8; i ++)
{
    t.increment ();
    std::cout << t << std::endl;
}
```

*Ausgabe*:

```
23:59:56
23:59:57
23:59:58
23:59:59
00:00:00
00:00:01
00:00:02
00:00:03
```

*Beispiel*: Codefragment zum Testen der `diff`-Methode:

```cpp
// testing 'diff'
Time t1;
Time t2("23:59:59");
Time t3 = t1.diff(t2);
std::cout << t3 << std::endl;
t3 =  t2.diff(t1);
std::cout << t3 << std::endl;
```

*Ausgabe*:

```
23:59:59
23:59:59
```

*Beispiel*: Codefragment zum Testen der arithmetischen Operatoren:

```cpp
// testing operators
Time t1 (15, 30, 6);
Time t2 = t1 + t1;
std::cout << t2 << std::endl;
t2 += t1;
std::cout << t2 << std::endl;
t2 -= 120;
std::cout << t2 << std::endl;
t2 -= t1;
std::cout << t2 << std::endl;
```

*Ausgabe*:

```
13:00:30
19:30:45
19:28:45
12:58:30
```

*Beispiel*: Codefragment zum Testen des Inkrement- und Dekrement-Operators:

```cpp
// testing increment/decrement operator
Time t1 (0, 0, 12);
Time t2 = t1++;
std::cout << t2 << std::endl;
t2 = ++t1;
std::cout << t2 << std::endl;
t2 = t1--;
std::cout << t2 << std::endl;
t2 = --t1;
std::cout << t2 << std::endl;
```

*Ausgabe*:

```
12:00:00
12:00:02
12:00:02
12:00:00
```

*Beispiel*: Codefragment zum Testen des `int`-Konvertierungsoperators:

```cpp
// testing conversion operator
Time t;
t = 60*60 + 60 + 1;
std::cout << "Time:    " << t << std::endl;
std::cout << "Seconds: " << (int) t << std::endl;
```

*Ausgabe*:

```
Time:    01:01:01
Seconds: 3661
```

*Beispiel*: Codefragment zum Testen der Ein- und Ausgabe (Konsoleneingaben fett gedruckt):

```cpp
Time t;
cin >> t;
std::cout << t << std::endl;
```

*Ausgabe*:

<pre>
Hours [hh]: <b>12</b>
Minutes [mm]: <b>34</b>
Seconds [ss]: <b>56</b>
12:34:56
</pre>


---

## Quellcode der Lösungen:

[*Time.h*](./Time/Time.h)<br />
[*Time.cpp*](./Time/Time.cpp)<br />
[*Time_Main.cpp*](./Time/Time_Main.cpp)<br />

---

[Zurück](./Exercises.md)

---
