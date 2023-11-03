# Initialisierung von Objekten: Konstruktoren


[Zurück](Agenda.md)

---

## Erläuterungen

Um die Integrität eines Objekts für seine gesamte Lebensdauer zu gewährleisten,
sind Instanzvariablen eines Objekts bereits bei seiner *Erzeugung* sinnvoll zu initialisieren.

Darunter versteht man *nicht* die Vorgehensweise wie in diesem Code-Fragment:

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


### Konstruktoren

Unter einem *Konstruktor* versteht man eine spezielle Art von Methode,
die den gleichen Namen wie die Klasse hat, zu der sie gehört.
Ein Konstruktor besitzt die Aufgabe, die Instanzvariablen eines Objekts vollständig mit sinnvollen Werten zu initialisieren.
Umgangssprachlich kann man auch sagen, dass ein Konstruktor eine Instanz &ldquo;konstruiert&rdquo;.

Die Anweisung zum Aufruf eines Konstruktors wird durch den Compiler im Zuge der Objekterzeugung *automatisch* abgesetzt.
Auf diese Weise wird erreicht, dass Objekterzeugung und Konstruktorausführung zu einer Einheit *verschmelzen*.

### Überladen von Methoden

Eine Klasse kann durchaus mehrere Konstruktoren besitzen.
Wir stoßen auf den Feature des *Überladens von Methoden*,
dieses Mal speziell im Umfeld von Konstruktoren.

Wir finden im nachfolgenden Beispiel also gleich fünf Konstruktoren vor.

## Beispiele

Wir ergänzen die Klasse `Time` um mehrere Konstruktoren:

Datei *Time.h*:

```cpp
01: class Time
02: {
03: private:
04:     int m_seconds;
05:     int m_minutes;
06:     int m_hours;
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

Datei *Time.cpp*:

```cpp
01: // c'tors
02: Time::Time() : m_seconds(0), m_minutes(0), m_hours(0) {}  // default c'tor
03: 
04: Time::Time(int hours, int minutes, int seconds)   // user-defined c'tor
05: {
06:     m_hours = (0 <= hours && hours < 24) ? hours : 0;
07:     m_minutes = (0 <= minutes && minutes < 60) ? minutes : 0;
08:     m_seconds = (0 <= seconds && seconds < 60) ? seconds : 0;
09: }
10: 
11: Time::Time(int hours, int minutes)   // user-defined c'tor
12: {
13:     m_hours = (0 <= hours && hours < 24) ? hours : 0;
14:     m_minutes = (0 <= minutes && minutes < 60) ? minutes : 0;
15:     m_seconds = 0;
16: }
17: 
18: Time::Time(const char* s)  // user-defined c'tor
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
31: Time::Time(int seconds)     // conversion c'tor
32: {
33:     if (0 <= seconds && seconds <= 24 * 60 * 60)
34:     {
35:         secondsToTime(seconds);
36:     }
37:     else
38:     {
39:         m_seconds = m_minutes = m_hours = 0;
40:     }
41: }
42: 
43: // public interface
44: void Time::print()
45: {
46:     std::printf("%02d:%02d:%02d\n", m_hours, m_minutes, m_seconds);
47: }
48: 
49: // private interface
50: void Time::secondsToTime(int seconds)
51: {
52:     m_hours = seconds / 3600;
53:     seconds = seconds % 3600;
54:     m_minutes = seconds / 60;
55:     m_seconds = seconds % 60;
56: }
```

*1. Bemerkung*:
XXX

*2. Bemerkung*:
XXXX

---

#### Datei *Main.cpp* - Testrahmen:


```cpp
01: void testTimeConstructors()
02: {
03:     using namespace Classes_Objects_Constructors;
04: 
05:     Time t1;
06:     t1.print();
07: 
08:     Time t2(12, 30, 0);
09:     t2.print();
10: 
11:     Time t3("09:30:00");
12:     t3.print();
13: 
14:     Time t4(24 * 60 * 60 - 1);
15:     t4.print();
16: }
```

*Ausgabe*:


```
00:00:00
12:30:00
09:30:00
23:59:59
```

---

## Quellcode des Beispiels:

[Time.h](..\Constructors\Time.h)<br />
[Time.cpp](..\Constructors\Time.cpp)<br />
[Main.cpp](..\Constructors\Main.cpp)

---


## Übungen

TBD: Rectangle


---


[Zurück](Agenda.md)

---
