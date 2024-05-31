# Speicherbereiche eines C++&ndash;Programms

[Zurück](Agenda.md)

---

## Erläuterungen

### Überblick über die Speicherbereiche eines C++&ndash;Programms

In einem C++&ndash;Programm sind mehrere Speicherbereiche vorhanden,
die vor dem Start des Programms vom Betriebssystem dem Programm (genauer: *Prozess*)
zugewiesen werden:

  * Globales Datensegment (*Data*)
  * Codebereich (*Code*)
  * Stapel (*Stack*)
  * Halde (*Heap*)
  
Neben diesen Segmenten (Speicherbereiche) kennt eine CPU auch noch *Register*.

Das bekannteste Register heißt *Akkumulator* (*Accumulator*),
in ihm werden in der Regel die Ergebnisse der Recheneinheit (*ALU*, *Arithmetic Logic Unit*) gespeichert.

Bei Intel-CPUs gibt es eine direkte Zuordnung dieser Speicherbereiche
zur Speichersegmentierung in der Intel x86-Computerbefehlssatzarchitektur:

| Segmentregister  | Beschreibung |
| :--- | :---|
| **DS** | Data Segment |
| **SS** | Stack Segment |
| **CS** | Code Segment |
| **ES** | Extra Segment (Heap) |

Lokale Variablen befinden sich zusammen mit den Funktionsparametern auf dem Stack.

Der Code steht natürlich im Codebereich, und globale Variablen im globalen Datensegment.

Die Register dienen internen Verwaltungsaufgaben. Dazu gehören beispielsweise Stack-Operationen
(Register **SP** (*Stack Pointer*) und **BP** (*Base Pointer*))
oder der *Akkumulator* (**AX** bzw. **EAX**).

Speicher, der *dynamisch* allokiert wird, residiert in der so genannten *Halde*.

### Lebensdauer von Variablen in einem C++&ndash;Programm

Man kann die Lebensdauer von Variablen in einem C++&ndash;Programm in drei Gruppen einteilen:

  * Globale Variablen:<br />
  Derartige Variablen werden außerhalb von Funktionen oder Klassen, also auf der obersten
  Ebene eines Programms definiert. Dabei sollten sie stets mit einem Vorbelegungswert initialisiert werden.<br /><br />
  Globale Variablen existieren so lange wie das Programm ausgeführt wird.
  So gesehen sollte man sie behutsam einsetzen, da sie bereits vor dem Start
  des Programms Speicher in Anspruch nehmen &ndash;
  und diesen bis zum Ende des Programms auch nicht vorzeitig freigeben können.<br /><br />
  Man kann auf globale Variablen von überall aus im gesamten Programm zugreifen.

  * Lokale Variablen:<br />
  Lokale Variablen werden in Funktionen oder Methoden (oder in inneren Blöcken von Funktionen oder Methoden)
  definiert.<br /><br />
  Sie werden wie gewohnt durch eine Deklaration erstellt
  und durch das Schließen des Blocks zerstört.
  Danach gibt es keine Möglichkeit mehr auf diese Variablen zuzugreifen.<br /><br />
  Lokale Variablen werden nicht automatisch initialisiert,
  es ist eine manuelle Initialisierung durch den Programmierer im Quellcode erforderlich.


  * Dynamische Variablen:<br />
  Unter dynamischen Variablen versteht man Variablen, die nach Bedarf angelegt werden
  und dann wieder zu löschen sind, wann man sie nicht mehr benötigt.
  So gesehen stehen dynamische Variablen für eine optimale Inanspruchnahme (Auslastung) des Speichers,
  da globale Variablen möglicherweise zu großzügig mit dem Speicher umgehen
  und lokale Variablen andererseits nicht über Funktionsgrenzen hinweg verfügbar sind.<br /><br />
  Man kann beliebig viele Variablen dynamisch anlegen (solange Hauptspeicher verfügbar ist).<br /><br />
  Ihr großer Vorteil besteht darin, dass man mit ihrer Hilfe genau so viel Speicher anfordern kann,
  wie man für einen Programmablauf benötigt.<br /><br />
  Zum Reservieren dynamischen Speichers gibt es die beiden Operatoren `new` und `delete`.

---

## Quellcode des Beispiels:

[*Main.cpp*](../MemoryManagement/Main.cpp)

---

[Zurück](Agenda.md)

---
