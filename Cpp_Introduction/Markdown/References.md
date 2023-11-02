# Referenzen


[Zurück](../../Readme.md)

---

## Erläuterungen

Zeiger (Pointer) der Programmiersprache C sind eine Möglichkeit,
um auf Objekte (Variablen) indirekt zugreifen zu können.

Referenzen bieten nahezu die gleichen Möglichkeiten wie Zeiger, aber mit einer wesentlich *einfacheren*
Syntax.

Es ist wichtig zu verstehen, 

  * was Referenzen sind
  * wie sich Referenzen von Zeigern unterscheiden
  * wie man Referenzen erzeugt und verwendet
  * welche Beschränkungen für Referenzen gelten
  * wie man Werte und Objekte in und aus Funktionen (Methoden) als Referenz übergibt.


### Was ist eine Referenz?

Eine *Referenz* ist ein *Alias*-Name. 

Wenn man eine Referenz erzeugt, initialisiert man sie mit dem Namen eines
anderen Objekts, dem Ziel.

Von diesem Moment an ist die Referenz wie ein alternativer Name für das Ziel, und alles,
was man mit der Referenz anstellt, bezieht sich tatsächlich auf das Ziel.

Die Deklaration einer Referenz besteht aus dem Typ des Zielobjekts, gefolgt vom Referenzoperator (&) und dem
Namen der Referenz.
Die Regeln für die Benennung von Referenzen sind die gleichen wie für Variablennamen.

Viele Programmierer stellen ihren Referenzen ein vorangestelltes `r`.
Zum Beispiel erzeugt man für eine
Integer-Variable einInt eine Referenz mit der folgenden Anweisung:

int &rEineRef = einInt;


## Beispiele

Wir betrachten als Beispiel eine Uhrzeit: Sie besteht aus Stunden, Minuten und Sekunden.
Für den Einstieg betrachten wir nur die Methode `increment` (erhöhe die Uhrzeit um eine Sekunden),
`print` (Ausgabe der Uhrzeit auf der Konsole) und `reset` (Uhrzeit auf den Wert `00:00:00` rücksetzen).

*Hinweis*: Beachten Sie bei der Realisierung:
Typischerweise ist die Realisierung einer Klasse auf 2 Dateien aufgeteilt:

  * Header-Datei (Dateiendung *.cpp*):<br/>
  * Implementierungs-Datei (Dateiendung *.h*):<br/>Realisierung der Methoden der Klasse

#### Datei *Time.h*:

```cpp
01: #include <iostream>
02: #include <iomanip>
03: #include <cstdio>
04: 
05: class Time
06: {
07: public:
08:     // member data / instance variables
09:     int m_seconds;
10:     int m_minutes;
11:     int m_hours;
12: 
13:     // public interface / methods
14:     void reset();
15:     void increment();
16:     void print();
17: };
```

*Bemerkung*:
Bei der Deklaration der Klasse `Time` ist noch ein weiteres Schlüsselwörter
`public` zum Einsatz gekommen. Wir gehen im Abschnitt Zugriffsrechte (PELO: Link)
hierauf näher ein.

#### Datei *Time.cpp*:

```cpp
01: #include "Time.h"
02: 
03: // implementation
04: void Time::reset()
05: {
06:     m_seconds = 0;
07:     m_minutes = 0;
08:     m_hours = 0;
09: }
10: 
11: void Time::increment()
12: {
13:     m_seconds++;
14:     if (m_seconds >= 60)
15:     {
16:         m_seconds = 0;
17:         m_minutes++;
18:         if (m_minutes >= 60)
19:         {
20:             m_minutes = 0;
21:             m_hours++;
22:             if (m_hours >= 24)
23:             {
24:                 m_hours = 0;
25:             }
26:         }
27:     }
28: }
29: 
30: void Time::print()
31: {
32:     //std::cout << std::setw(2) << std::setfill('0') << m_hours << ":";
33:     //std::cout << std::setw(2) << std::setfill('0') << m_minutes << ":";
34:     //std::cout << std::setw(2) << std::setfill('0') << m_seconds;
35:     //std::cout << std::endl;
36: 
37:     // or - with the help of C-printf:
38:     std::printf("%02d:%02d:%02d\n", m_hours, m_minutes, m_seconds);
39: }
```

*1. Bemerkung*:
Dieses Beispiel einer Klasse *Time* weist noch viele Mängel auf,
um es als wirklich guten C++&ndash;Quellcode bezeichnen zu können.
Eine Reihe von Verbesserungen nehmen wir im nächsten Abschnitt XXX (Pelo) vor.

*2. Bemerkung*:
Betrachen Sie die Beispiele im vorliegenden Quellcode, treffen Sie auf ein 
weiteres Schlüsselwort: `namespace`. Auch Namensräume stellen im Augenblick einen Vorgriff
auf das zu einem späteren Zeitpunkt zu betrachtende Sprachkonstrukt von *Namensräumen* dar,
aber um es hier schon einmal kurz anzusprechen:
Sie helfen dabei, dass wir im Zuge unserer
Weiterentwicklung der Klasse `Time` keine Fehlermeldungen der Gestalt
&ldquo;*Error class 'Time': 'class' type redefinition*&rdquo;
erhalten. Bis auf Weiteres dürfen Sie die `namespace`-Anweisungen getrost ignorieren.

#### Datei *Main.cpp* - Testrahmen:

Ein Testrahmen mit 2 Objekten `now` und `later`:

```cpp
01: void testTime()
02: {
03:     Time now;
04:     now.m_hours = 10;
05:     now.m_minutes = 20;
06:     now.m_seconds = 30;
07:     now.print();
08: 
09:     Time later;
10:     later.m_hours = 17;
11:     later.m_minutes = 0;
12:     later.m_seconds = 0;
13:     later.print();
14: 
15:     now.increment();
16:     now.print();
17: 
18:     now.reset();
19:     now.print();
20: }
```

*Ausgabe*:


```
10:20:30
17:00:00
10:20:31
00:00:00
```

---

## Quellcode des Beispiels:

[Time.h](..\Classes_Objects\Time.h)<br />
[Time.cpp](..\Classes_Objects\Time.cpp)<br />
[Main.cpp](..\Classes_Objects\Main.cpp)

---


## Übungen

TBD: Rectangle


---


[Zurück](../../../Readme.md)

---
