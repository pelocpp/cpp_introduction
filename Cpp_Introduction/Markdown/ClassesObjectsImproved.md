# Vertiefungen zu Klassen und Objekten


[Zurück](../../Readme.md)

---

## Erläuterungen

Wir gehen auf ein zentrales Prinzip der objektorientierten Programmierung ein:

### Zugriffsschutz und Kapselung

Das erste Beispiel in der Entwicklung einer Klasse `Time`
verstieß gegen ein fundamentales Paradigma der objektorientierten Programmierung:

> Ein Objekt besitzt zu **jedem** Zeitpunkt gültige Werte (in seinen Instanzvariablen).

Mit zwei einfachen Anweisungen der Gestalt

```cpp
Time t;
t.m_hours = 99999;
```

könnten wir dieses Paradigma einfach außer Kraft setzen.

Ein zentrales Prinzip der objektorientierten Programmierung ist die so genannte *Kapselung*.
Der Benutzer einer Klasse soll nur auf die Elemente einer *öffentlichen Schnittstelle* zugreifen können,
die typischerweise durch die Methoden (und Konstruktoren) zum Ausdruck kommt.

Die Daten sind im Gegensatz dazu vor dem Zugriff von außen zu schützen.
Würde es keine Möglichkeit geben, den Zugriff auf die Daten (als auch Teile der Instanzmethoden) einzuschränken
oder gar zu unterbinden, könnte man Anweisungen wie die des zuletzt gezeigten
Codefragments nicht unterbinden.

Die Kapselung der Daten eines Objekts, sprich der Zugriffsschutz, wird mit den Schlüsselwörtern
`private`, `public` und `protected` erreicht.
Steht innerhalb einer Klassendeklaration eines der zuvor erwähnten Schlüsselwörter (gefolgt von einem Doppelpunkt),
so wird der Zugriff aller nachfolgend deklarierten Daten und Methoden wie folgt geschützt:

* Zugriffsklasse `private`:<br />
  Alle nachfolgenden Deklarationen nehmen einen *privaten* Status innerhalb der Klasse ein.
  Dies bedeutet, dass auf die so markierten Elemente der Klasse nur von Instanzmethoden *derselben* Klasse
  zugegriffen werden kann.
  Methoden, die nicht in dieser Klasse deklariert sind, haben folglich keinerlei Möglichkeit, auf die privat deklarierten Elemente dieser Klasse
  zuzugreifen!

* Zugriffsklasse `public`:<br />
  Alle Deklarationen, die auf dieses Schlüsselwort folgen,
  nehmen einen *öffentlichen* Status ein, d.h. auf sie kann von *überall* aus im Programm zugegriffen werden.
  Kurzum: Alle so deklarierten Elemente unterliegen in einem C++-Programm keinerlei Zugriffsbeschränkungen.
  
* Zugriffsklasse `protected`:<br />
  Die Anwendung des Zugriffsspezifizierers `protected` ist nur in einer Vererbungshierarchie sinnvoll,
  wir kommen auf seine Bedeutung im Abschnitt der Vererbung (PeLo // Link) zu sprechen.

Weitere Details siehe im nachfolgenden Beispiel weiter unten.


### *getter*/*setter*-Methoden

Mit der Einführung der Zugriffsklassen haben wir den direkten Zugriff auf Instanzvariablen verloren,
die mit dem Zugriffsspezifizierer `private` definiert sind.
Unterbinden wir eine Anweisung der Gestalt

```cpp
Time t;
t.m_hours = 99999;
```

dann stehen wir aber vor dem Problem, dass möglicherweise korrekte Anweisungen wie zum Beispiel

```cpp
Time t;
t.m_hours = 12;
```

auch nicht mehr gehen. 

Natürlich muss es dennoch möglich sein, den Zustand eines Objekts verändern zu können.
Da der Ausgangspunkt für die Einführung der Zugriffsklassen in der Wahrung der Integrität eines Objekts liegt,
sind Klassen nun um eine oder mehrere
spezielle &ndash; mit der Zugriffsklassen `public` versehene &ndash; Zugriffsmethoden zu definieren.

Diese als *getter*- bzw. *setter* bezeichnete Methoden ermöglichen nun
einerseits den Zugriff auf die &ndash; privat deklarierten &ndash; Instanzvariablen,
behalten aber andererseits die Integrität des Objekts im Hinterkopf.

Der Umweg über diese Zugriffsmethoden bewirkt somit einen ausschließlich *kontrollierten* Zugriff auf das Objekt:

Weitere Details siehe im nachfolgenden Beispiel weiter unten.

### `this`-Operator

(PeLo // TBD)

### Überladen von Methoden



### Klassen- vs. Instanzvariable / Klassen- vs. Instanzmethode / `static`

(PeLo // TBD)


## Beispiele

Wir betrachten als Beispiel eine Uhrzeit: Sie besteht aus Stunden, Minuten und Sekunden.
Für den Einstieg betrachten wir nur die Methode `increment` (erhöhe die Uhrzeit um eine Sekunden),
`print` (Ausgabe der Uhrzeit auf der Konsole) und `reset` (Uhrzeit auf den Wert `00:00:00` rücksetzen).

*Hinweis*: Beachten Sie bei der Realisierung:
Typischerweise ist die Realisierung einer Klasse auf 2 Dateien aufgeteilt:

  * Header-Datei (Dateiendung *.cpp*):<br/>
  * Implementierungs-Datei (Dateiendung *.h*):<br/>Realisierung der Methoden der Klasse

Datei *Time.h*:

```cpp
```

*Bemerkung*:
Bei der Deklaration der Klasse `Time` ist noch ein weiteres Schlüsselwörter
`public` zum Einsatz gekommen. Wir gehen im Abschnitt Zugriffsrechte (PELO: Link)
hierauf näher ein.

Datei *Time.cpp*:

```cpp
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
Weiterentwicklung der Klasse `Time` keine Fehlermeldungen  

---

## Quellcode des Beispiels:

[Time.h](..\ClassesObjectsImproved\Time.h)<br />
[Time.cpp](..\ClassesObjectsImproved\Time.cpp)<br />
[Main.cpp](..\ClassesObjectsImproved\Main.cpp)

---


## Übungen

TBD: Rectangle


---


[Zurück](../../../Readme.md)

---
