# Vertiefungen zu Klassen und Objekten


[Zur�ck](../../Readme.md)

---

## Erl�uterungen

Wir gehen auf ein zentrales Prinzip der objektorientierten Programmierung ein:

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
  wir kommen auf seine Bedeutung im Abschnitt der Vererbung (PeLo // Link) zu sprechen.

Weitere Details siehe im nachfolgenden Beispiel weiter unten.


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

Weitere Details siehe im nachfolgenden Beispiel weiter unten.

### `this`-Operator

(PeLo // TBD)

### �berladen von Methoden



### Klassen- vs. Instanzvariable / Klassen- vs. Instanzmethode / `static`

(PeLo // TBD)


## Beispiele

Wir betrachten als Beispiel eine Uhrzeit: Sie besteht aus Stunden, Minuten und Sekunden.
F�r den Einstieg betrachten wir nur die Methode `increment` (erh�he die Uhrzeit um eine Sekunden),
`print` (Ausgabe der Uhrzeit auf der Konsole) und `reset` (Uhrzeit auf den Wert `00:00:00` r�cksetzen).

*Hinweis*: Beachten Sie bei der Realisierung:
Typischerweise ist die Realisierung einer Klasse auf 2 Dateien aufgeteilt:

  * Header-Datei (Dateiendung *.cpp*):<br/>
  * Implementierungs-Datei (Dateiendung *.h*):<br/>Realisierung der Methoden der Klasse

Datei *Time.h*:

```cpp
```

*Bemerkung*:
Bei der Deklaration der Klasse `Time` ist noch ein weiteres Schl�sselw�rter
`public` zum Einsatz gekommen. Wir gehen im Abschnitt Zugriffsrechte (PELO: Link)
hierauf n�her ein.

Datei *Time.cpp*:

```cpp
```

*1. Bemerkung*:
Dieses Beispiel einer Klasse *Time* weist noch viele M�ngel auf,
um es als wirklich guten C++&ndash;Quellcode bezeichnen zu k�nnen.
Eine Reihe von Verbesserungen nehmen wir im n�chsten Abschnitt XXX (Pelo) vor.

*2. Bemerkung*:
Betrachen Sie die Beispiele im vorliegenden Quellcode, treffen Sie auf ein 
weiteres Schl�sselwort: `namespace`. Auch Namensr�ume stellen im Augenblick einen Vorgriff
auf das zu einem sp�teren Zeitpunkt zu betrachtende Sprachkonstrukt von *Namensr�umen* dar,
aber um es hier schon einmal kurz anzusprechen:
Sie helfen dabei, dass wir im Zuge unserer
Weiterentwicklung der Klasse `Time` keine Fehlermeldungen  

---

## Quellcode des Beispiels:

[Time.h](..\ClassesObjectsImproved\Time.h)<br />
[Time.cpp](..\ClassesObjectsImproved\Time.cpp)<br />
[Main.cpp](..\ClassesObjectsImproved\Main.cpp)

---


## �bungen

TBD: Rectangle


---


[Zur�ck](../../../Readme.md)

---
