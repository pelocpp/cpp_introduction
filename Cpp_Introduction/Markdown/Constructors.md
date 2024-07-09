# Initialisierung von Objekten: Konstruktoren


[Zurück](Agenda.md)

---

## Erläuterungen

Um die Integrität eines Objekts für seine gesamte Lebensdauer zu gewährleisten,
sind Instanzvariablen eines Objekts bereits bei seiner *Erzeugung* sinnvoll zu initialisieren.

Darunter versteht man *nicht* die Vorgehensweise wie in diesem Code-Fragment gezeigt:

```cpp
Time now;
now.setHours(10);
now.setMinutes(20);
now.setSeconds(30);
```

Es kann vom Übersetzer nicht sicher gestellt werden, dass auf diese Weise
*alle* Instanzvariablen des Objekts erreicht werden.
Man hat ein sprachliches Mittel geschaffen, um die Anweisung

```cpp
Time now;
```

so zu erweitern, dass für das Objekt auch Vorbelegungswerte mit übergeben werden können:

### Was sind Konstruktoren?

Unter einem *Konstruktor* versteht man eine spezielle Art von Methode, die

  * den gleichen Namen wie die Klasse hat, zu der sie gehört und
  * die *keinen* Rückgabetyp hat.

Ein Konstruktor besitzt die Aufgabe, die Instanzvariablen eines Objekts vollständig mit sinnvollen Werten vorzubelegen.
Umgangssprachlich kann man auch sagen, dass ein Konstruktor eine Instanz &bdquo;konstruiert&rdquo;.

Die Anweisung zum Aufruf eines Konstruktors wird durch den Compiler im Zuge der Objekterzeugung *automatisch* abgesetzt.
Auf diese Weise wird erreicht, dass Objekterzeugung und Konstruktorausführung zu einer Einheit *verschmelzen*.

### Überladen von Konstruktoren

Eine Klasse kann durchaus mehrere Konstruktoren besitzen.
Wir stoßen auf das Feature des *Überladens von Methoden*
häufig im Umfeld von Konstruktoren.

Im nachfolgenden Beispiel finden wir also gleich fünf Konstruktoren vor:

#### Datei [*Time.h*](../Constructors/Time.h):

```cpp
01: class Time
02: {
03: private:
04:     int m_hours;
05:     int m_minutes;
06:     int m_seconds;
07: 
08: public:
09:     // c'tors
10:     Time();
11:     Time(int hours, int minutes, int seconds);
12:     Time(int hours, int minutes);
13:     Time(int seconds);  // conversion c'tor
14:     Time(const char*);  // conversion c'tor
15: 
16:     // public interface
17:     void print();
18: 
19: private:
20:     // helper method(s)
21:     void secondsToTime(int seconds);
22: };
```

*Bemerkung*:
In diesem Abschnitt stehen nur Konstruktoren im Vordergrund. Aus diesem Grund
wurden die anderen Methoden der Klasse bis auf wenige Ausnahmen weggelassen.


#### Datei [*Time.cpp*](../Constructors/Time.cpp):

```cpp
01: // default c'tor
02: Time::Time() : m_hours(0), m_minutes(0), m_seconds(0) {}
03: 
04: // user-defined c'tor
05: Time::Time(int hours, int minutes, int seconds)
06: {
07:     m_hours = (0 <= hours && hours < 24) ? hours : 0;
08:     m_minutes = (0 <= minutes && minutes < 60) ? minutes : 0;
09:     m_seconds = (0 <= seconds && seconds < 60) ? seconds : 0;
10: }
11: 
12: // user-defined c'tor
13: Time::Time(int hours, int minutes)
14:     : Time(hours, minutes, 0) 
15: {}
16: 
17: // conversion c'tor
18: Time::Time(const char* s)
19: {
20:     // expecting format "hh:mm:ss" - don't expect wrong input (!)
21:     int hours = 10 * (s[0] - '0') + (s[1] - '0');
22:     m_hours = (0 <= hours && hours < 24) ? hours : 0;
23:     s += 3;  // skip hours and colon
24:     int minutes = 10 * (s[0] - '0') + (s[1] - '0');
25:     m_minutes = (0 <= minutes && minutes < 60) ? minutes : 0;
26:     s += 3;  // skip minutes and colon
27:     int seconds = 10 * (s[0] - '0') + (s[1] - '0');
28:     m_seconds = (0 <= seconds && seconds < 60) ? seconds : 0;
29: }
30: 
31: // conversion c'tor
32: Time::Time(int seconds)     
33: {
34:     if (0 <= seconds && seconds <= 24 * 60 * 60)
35:     {
36:         secondsToTime(seconds);
37:     }
38:     else
39:     {
40:         m_seconds = m_minutes = m_hours = 0;
41:     }
42: }
43: 
44: // public interface
45: void Time::print()
46: {
47:     std::printf("%02d:%02d:%02d\n", m_hours, m_minutes, m_seconds);
48: }
49: 
50: // private interface
51: void Time::secondsToTime(int seconds)
52: {
53:     m_hours = seconds / 3600;
54:     seconds = seconds % 3600;
55:     m_minutes = seconds / 60;
56:     m_seconds = seconds % 60;
57: }
```


#### Datei [*Main.cpp*](../Constructors/Main.cpp):


```cpp
01: void testConstructors()
02: {
03:     Time t1;
04:     t1.print();
05: 
06:     Time t2(12, 30, 0);
07:     t2.print();
08: 
09:     Time t3("09:30:00");
10:     t3.print();
11: 
12:     Time t4(24 * 60 * 60 - 1);
13:     t4.print();
14: }
```

*Ausgabe*:


```
00:00:00
12:30:00
09:30:00
23:59:59
```


### Element-Initialisierungsliste (*Member Initializer List*)

Ein Konstruktor kann optional über eine so genannte *Element-Initialisierungsliste* verfügen,
die die Instanzvariablen initialisiert,
bevor der Rumpf des Konstruks ausgeführt wird.

Im letzten Code-Fragment kommt diese Syntax bei zwei Konstruktoren 
zum Einsatz:

```cpp
01: Time::Time() : m_hours(0), m_minutes(0), m_seconds(0) {}
02: 
03: Time::Time(int hours, int minutes)
04:     : Time(hours, minutes, 0) 
05: {}
```

---

### Konvertierungskonstruktoren

Zwei der Konstruktoren der Klasse `Time` rangieren unter der Bezeichnung *Konvertierungskonstruktor*:

```cpp
Time(int seconds);
```

und

```cpp
Time(const char*);
```


Beide Konstruktoren besitzen genau ein Argument, dessen Datentyp
gewissermaßen dem *Quelldatentyp*  entspricht.
Der *Zieldatentyp* wiederum ist gleich dem Typ der Klasse,
es findet in beiden Beispielen folglich eine Konvertierung
von `int` nach `Time` bzw. von `const char*` nach `Time` statt:

```cpp
01: Time t1("09:30:00");          // conversion 'const char*' -> 'Time'
02: t1.print();
03: 
04: Time t2(24 * 60 * 60 - 1);    // conversion 'int' -> 'Time'
05: t2.print();
```

---

## Quellcode des Beispiels:

[*Time.h*](../Constructors/Time.h)<br />
[*Time.cpp*](../Constructors/Time.cpp)<br />
[*Main.cpp*](../Constructors/Main.cpp)

---

## Aufgaben

[Aufgabe zur Klasse `BankAccount`](../Exercises/Exercises_BankAccount.md)

---

[Zurück](Agenda.md)

---
