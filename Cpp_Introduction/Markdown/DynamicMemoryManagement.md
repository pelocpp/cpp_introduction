# Dynamische Speicherverwaltung

[Zur�ck](Agenda.md)

---

## Erl�uterungen

### Speicherbereiche eines C++&ndash;Programms

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

Lokale Variablen befinden sich zusammen mit den Funktionsparametern auf dem Stack.

Der Code steht nat�rlich im Codebereich, und globale Variablen im globalen Datensegment.

Die Register dienen internen Verwaltungsaufgaben. Dazu geh�ren beispielsweise Stack-Operationen
(Register **SP** (*Stack Pointer*) und **BP** (*Base Pointer*))
oder der *Akkumulator* (**AX** bzw. **EAX**).

Speicher, der *dynamisch* allokiert wird, residiert in der so genannten *Halde*.

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

### Stack und Heap (Stapel und Halde)

Lokale Variablen haben die Eigenschaft, dass sie nicht dauerhaft verf�gbar sind.
Kehrt eine Funktion zur�ck, werden ihre lokalen Variablen verworfen.
So gesehen eignen sich lokale Variablen zum Beispiel zur Ablage von Zwischenergebnissen.

<p align="center">
<img src="cpp_stack_vs_heap_01.svg" width="300">
</p>

*Abbildung* 1: Der Stack und lokale Variablen.

Der Vorteil von Variablen, die sich auf dem Heap befinden, liegt darin,
da� der reservierte Speicher solange verf�gbar bleibt, bis man ihn explizit wieder freigibt.

<p align="center">
<img src="cpp_stack_vs_heap_02.svg" width="600">
</p>

*Abbildung* 2: Die Halde und dynamisch allokierte Variablen.

Wird ein bestimmter Speicherbereich (Variable, Array, Objekt) auf der Halde reserviert,
w�hrend das Programm eine Funktion (Methode) abarbeitet,
bleibt der Speicher nach R�ckkehr der Funktion weiterhin zug�nglich.

Allerdings liegt es in der Verantwortung des Entwicklers, reservierten Speicher freizugeben,
wenn er nicht mehr ben�tigt wird!

### Operatoren `new` und `delete`

Ein St�ck Speicher auf der Halde wird mit dem Operator `new` allokiert.
Auf `new` folgt der Typ des Objekts, f�r das man Speicher reservieren will, damit der
Compiler bzw. das C++ Laufzeitsystem die erforderliche Speichergr��e kennt.

Der R�ckgabewert von `new` ist eine Speicheradresse. Diese mu� man einer Zeigervariablen zuweisen.

Wenn man den Speicherbereich nicht mehr ben�tigt, ruft man den `delete`-Operator
mit dem Zeiger als Argument auf.

`delete` gibt den vormals reservierten Speicherbereich an die C++ Freispeicherverwaltung zur�ck.

*Beachte*:
Ein mit `new` reserviertes St�ck Speicher wird nicht automatisch freigegeben.
Vergisst man den Aufruf von `delete`, entsteht eine sogenannte Speicherl�cke.
Dieser Speicherbereich l��t sich bis zum Ende des Programms
nicht mehr anderweitig verwenden.

## Beispiele

### *Beispiel* 1: Reservieren und Freigeben eines Speicherbereichs f�r eine elementare Variable:

```cpp
01: // allocating a single int variable
02: int* pi = new int(123);
03: std::cout << *pi << std::endl;
04: 
05: // releasing memory
06: delete pi;
```

*Ausgabe*:


```
123
```

### *Beispiel* 2: Reservieren und Freigeben eines Speicherbereichs f�r ein `int`-Array:

```cpp
01: // allocating an array of int values
02: int* pArray = new int[5];
03: 
04: // initialize array
05: for (int i = 0; i < 5; ++i) {
06:     pArray[i] = i;
07: }
08: 
09: // accessing dynamically allocated array
10: for (int i = 0; i < 5; ++i) {
11:     std::cout << pArray[i] << ' ';
12: }
13: std::cout << std::endl;
14: 
15: // releasing memory - note: array delete (!)
16: delete[] pArray;
```

*Ausgabe*:


```
0 1 2 3 4
```

*Achtung*:


Es gibt den `new`- und `delete`-Operator in zwei Auspr�gungen &ndash; also auch syntaktisch
in zwei Schreibweisen:

  * `new` &ndash; Reserviert Speicher f�r eine einzelne Variable (Objekt).
  * `new []` &ndash; Reserviert Speicher f�r ein Feld von Variablen (Objekten).


  * `delete` &ndash; Gibt Speicher einer einzelnen Variablen frei.
  * `delete []` &ndash; Gibt Speicher eines Felds von Variablen (Objekten) frei.


### *Beispiel* 3: Reservieren und Freigeben eines Speicherbereichs f�r ein Objekt:

```cpp
01: class SimpleClass
02: {
03: public:
04:     SimpleClass() { std::cout << "c'tor" << std::endl; }
05: 
06:     void print () { std::cout << "print" << std::endl; }
07: 
08:     ~SimpleClass() { std::cout << "d'tor" << std::endl; }
09: };
10: 
11: void test()
12: {
13:     // allocating a single variable
14:     SimpleClass* pSimpleClass = new SimpleClass;
15: 
16:     pSimpleClass->print();
17: 
18:     // releasing memory
19:     delete pSimpleClass;
20: }
```

*Ausgabe*:

```
c'tor
print
d'tor
```


### *Beispiel* 4: Reservieren und Freigeben eines Speicherbereichs f�r ein Array von Objekten:

```cpp
01: // allocating and initializing an array of objects
02: SimpleClass* pArray = new SimpleClass[5];
03: 
04: // accessing dynamically allocated objects
05: for (int i = 0; i < 5; ++i) {
06:     pArray[i].print();
07: }
08: 
09: // releasing memory - note: array delete (!)
10: delete[] pArray;
```

*Ausgabe*:

```
c'tor
c'tor
c'tor
c'tor
c'tor
print
print
print
print
print
d'tor
d'tor
d'tor
d'tor
d'tor
```

---

## Quellcode des Beispiels:

[*Main.cpp*](../DynamicMemoryManagement/Main.cpp)

---

## Aufgaben

[Aufgabe zur Klasse `DynamicIntArray`](../Exercises/Exercises_DynamicIntArray.md)

[Aufgabe zur Klasse `String`](../Exercises/Exercises_String.md)

---

[Zur�ck](Agenda.md)

---
