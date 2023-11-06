# Erster Blick auf Klassen und Objekte

[Zurück](Agenda.md)

---

## Erläuterungen

Im Umfeld der objektorientierten Programmierung versteht man unter einer *Klasse* 
die Zusammenfassung von Daten und ihren korrespondierenden Funktionen
in einem gemeinsamen Sprachkonstrukt.

Eine Klasse steht für die Beschreibung (Bauplan) eines solchen Datentyps,
reale Variablen dieses Datentyps bezeichnet man in der objektorientierten Programmierung
als *Objekte*.

Das Sprachkonstrukt einer Klasse definiert einen so genannten *abstrakten Datentyp*,
die Menge der gekapselten Daten (so genannte *Instanzvariablen*) und Funktionen
(so genannte *Methoden*) leiten sich aus dem Problemkontext ab.

## Beispiele

Wir betrachten als Beispiel eine Uhrzeit: Sie besteht aus Stunden, Minuten und Sekunden.
Für den Einstieg betrachten wir nur die Methode `increment` (erhöhe die Uhrzeit um eine Sekunden),
`print` (Ausgabe der Uhrzeit auf der Konsole) und `reset` (Uhrzeit auf den Wert `00:00:00` rücksetzen).

*Hinweis*: Beachten Sie bei der Realisierung:
Typischerweise ist die Realisierung einer Klasse auf 2 Dateien aufgeteilt:

  * Header-Datei (Dateiendung *.cpp*):<br/>
  * Implementierungs-Datei (Dateiendung *.h*):<br/>Realisierung der Methoden der Klasse

#### Datei [*Time.h*](../ClassesObjects/Time.h):

```cpp
01: class Time
02: {
03: public:
04:     // member data / instance variables
05:     int m_seconds;
06:     int m_minutes;
07:     int m_hours;
08: 
09:     // public interface / methods
10:     void reset();
11:     void increment();
12:     void print();
13: };
```

*Bemerkung*:
Bei der Deklaration der Klasse `Time` ist noch ein weiteres Schlüsselwörter
`public` zum Einsatz gekommen. Wir gehen im Abschnitt Zugriffsrechte
([Vertiefungen zu Klassen und Objekten](ClassesObjectsImproved.md))
hierauf näher ein.

#### Datei [*Time.cpp*](../ClassesObjects/Time.cpp):

```cpp
01: void Time::reset()
02: {
03:     m_seconds = 0;
04:     m_minutes = 0;
05:     m_hours = 0;
06: }
07: 
08: void Time::increment()
09: {
10:     m_seconds++;
11:     if (m_seconds >= 60)
12:     {
13:         m_seconds = 0;
14:         m_minutes++;
15:         if (m_minutes >= 60)
16:         {
17:             m_minutes = 0;
18:             m_hours++;
19:             if (m_hours >= 24)
20:             {
21:                 m_hours = 0;
22:             }
23:         }
24:     }
25: }
26: 
27: void Time::print()
28: {
29:     std::printf("%02d:%02d:%02d\n", m_hours, m_minutes, m_seconds);
30: }
```

*1. Bemerkung*:
Dieses Beispiel einer Klasse *Time* weist noch viele Mängel auf,
um es als wirklich guten C++&ndash;Quellcode bezeichnen zu können.
Eine Reihe von Verbesserungen nehmen wir im Abschnitt
[Vertiefungen zu Klassen und Objekten](ClassesObjectsImproved.md)
vor.


*2. Bemerkung*:
Betrachen Sie die Beispiele im vorliegenden Quellcode, treffen Sie auf ein 
weiteres Schlüsselwort: `namespace`. Auch Namensräume stellen im Augenblick einen Vorgriff
auf das zu einem späteren Zeitpunkt zu betrachtende Sprachkonstrukt von *Namensräumen* dar,
aber um es hier schon einmal kurz anzusprechen:
Sie helfen dabei, dass wir im Zuge unserer
Weiterentwicklung der Klasse `Time` keine Fehlermeldungen der Gestalt
&ldquo;*Error class 'Time': 'class' type redefinition*&rdquo;
erhalten. Bis auf Weiteres dürfen Sie die `namespace`-Anweisungen getrost ignorieren.

#### Datei [*Main.cpp*](../ClassesObjects/Main.cpp) - Testrahmen:

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

[*Time.h*](../ClassesObjects/Time.h)<br />
[*Time.cpp*](../ClassesObjects/Time.cpp)<br />
[*Main.cpp*](../ClassesObjects/Main.cpp)

---


## Übungen

TBD: Rectangle

Methode equal ....

---

[Zurück](Agenda.md)

---
