# Speicherbereiche eines C++&ndash;Programms

[Zur�ck](Agenda.md)

---

## Erl�uterungen

### �berblick �ber die Speicherbereiche eines C++&ndash;Programms

In einem C++&ndash;Programm sind mehrere Speicherbereiche vorhanden,
die vor dem Start des Programms vom Betriebssystem dem Programm (genauer: *Prozess*)
zugewiesen werden:

  * Globales Datensegment (*Data*)
  * Codebereich (*Code*)
  * Stapel (*Stack*)
  * Halde (*Heap*)
  
Neben diesen Segmenten (Speicherbereiche) kennt eine CPU auch noch *Register*.

Das bekannteste Register hei�t *Akkumulator* (*Accumulator*),
in ihm werden in der Regel die Ergebnisse der Recheneinheit (*ALU*, *Arithmetic Logic Unit*) gespeichert.

Bei Intel-CPUs gibt es eine direkte Zuordnung dieser Speicherbereiche
zur Speichersegmentierung in der Intel x86-Computerbefehlssatzarchitektur:

| Segmentregister  | Beschreibung |
| :--- | :---|
| **DS** | Data Segment |
| **SS** | Stack Segment |
| **CS** | Code Segment |
| **ES** | Extra Segment (Heap) |

*Tabelle*: Segmentregister einer Intel-CPU.

  * Lokale Variablen befinden sich zusammen mit den Funktionsparametern auf dem Stack.

  * Der Code steht nat�rlich im Codebereich, und globale Variablen im globalen Datensegment.

  * Die Register dienen internen Verwaltungsaufgaben. Dazu geh�ren beispielsweise Stack-Operationen
  (Register **SP** (*Stack Pointer*) und **BP** (*Base Pointer*))
  oder der *Akkumulator* (**AX** bzw. **EAX**).

  * Speicher, der *dynamisch* allokiert wird, residiert in der so genannten *Halde*.

### Lebensdauer von Variablen in einem C++&ndash;Programm

Man kann die Lebensdauer von Variablen in einem C++&ndash;Programm in drei Gruppen einteilen:

  * Globale Variablen:<br />
  Derartige Variablen werden au�erhalb von Funktionen oder Klassen, also auf der obersten
  Ebene eines Programms definiert. Dabei sollten sie stets mit einem Vorbelegungswert initialisiert werden.<br /><br />
  Globale Variablen existieren so lange wie das Programm ausgef�hrt wird.
  So gesehen sollte man sie behutsam einsetzen, da sie bereits vor dem Start
  des Programms Speicher in Anspruch nehmen &ndash;
  und diesen bis zum Ende des Programms auch nicht vorzeitig freigeben k�nnen.<br /><br />
  Man kann auf globale Variablen von �berall aus im gesamten Programm zugreifen.

  * Lokale Variablen:<br />
  Lokale Variablen werden in Funktionen oder Methoden (oder in inneren Bl�cken von Funktionen oder Methoden)
  definiert.<br /><br />
  Sie werden wie gewohnt durch eine Deklaration erstellt
  und durch das Schlie�en des Blocks zerst�rt.
  Danach gibt es keine M�glichkeit mehr auf diese Variablen zuzugreifen.<br /><br />
  Lokale Variablen werden nicht automatisch initialisiert,
  es ist eine manuelle Initialisierung durch den Programmierer im Quellcode erforderlich.


  * Dynamische Variablen:<br />
  Unter dynamischen Variablen versteht man Variablen, die nach Bedarf angelegt werden
  und dann wieder zu l�schen sind, wann man sie nicht mehr ben�tigt.
  So gesehen stehen dynamische Variablen f�r eine optimale Inanspruchnahme (Auslastung) des Speichers,
  da globale Variablen m�glicherweise zu gro�z�gig mit dem Speicher umgehen
  und lokale Variablen andererseits nicht �ber Funktionsgrenzen hinweg verf�gbar sind.<br /><br />
  Man kann beliebig viele Variablen dynamisch anlegen (solange Hauptspeicher verf�gbar ist).<br /><br />
  Ihr gro�er Vorteil besteht darin, dass man mit ihrer Hilfe genau so viel Speicher anfordern kann,
  wie man f�r einen Programmablauf ben�tigt.<br /><br />
  Zum Reservieren dynamischen Speichers gibt es die beiden Operatoren `new` und `delete`.

---

## Quellcode des Beispiels:

[*Main.cpp*](../MemoryManagement/Main.cpp)

---

[Zur�ck](Agenda.md)

---
