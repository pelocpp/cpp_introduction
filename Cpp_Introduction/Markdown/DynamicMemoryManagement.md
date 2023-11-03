# Dynamische Speicherverwaltung

[Zur�ck](Agenda.md)

---

## Erl�uterungen

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


Bei Intel-CPUs gibt es eine direkte Zuordnung dieser Speicherbereich
zur Speichersegmentierung in der Intel x86-Computerbefehlssatzarchitektur:

| Segmentregister  | Beschreibung |
| :--- | :---|
| **DS** | Data Segment |
| **SS** | Stack Segment |
| **CS** | Code Segment |
| **ES** | Extra Segment (Heap) |

Lokale Variablen befinden sich zusammen mit den Funktionsparametern auf dem Stack.

Der Code steht nat�rlich im Codebereich, und globale Variablen im Bereich des globalen Datensegments.

Die Register dienen internen Verwaltungsaufgaben. Dazu geh�ren beispielsweise Stack-Operationen
und die Steuerung des Programmablaufs.

Speicher, der *dynamisch* allokiert wird, residiert in der so genannten Halde.

### Stack und Heap (Stapel und Halde)

Lokale Variablen haben die Eigenschaft, dass sie nicht dauerhaft verf�gbar sind.
Kehrt eine Funktion zur�ck, werden ihre lokalen Variablen verworfen.
So gesehen eignen sich lokale Variablen zum Beispiel zur Ablage von Zwischenergebnissen.

Der Vorteil von Variablen, die sich auf dem Heap befinden, liegt darin,
da� der reservierte Speicher solange verf�gbar bleibt, bis man ihn explizit wieder freigibt.

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
02: int* pInt = new int(123);
03: std::cout << *pInt << std::endl;
04: 
05: // releasing memory
06: delete pInt;
```

*Ausgabe*:


```
123
```

### *Beispiel* 2: Reservieren und Freigeben eines Speicherbereichs f�r ein `int`-Array:

```cpp
01: // allocating an array of int values
02: int* pArray = new int[10];
03: 
04: // initialize array
05: for (int i = 0; i < 10; ++i) {
06:     pArray[i] = i;
07: }
08: 
09: // accessing dynamically allocated array
10: for (int i = 0; i < 10; ++i) {
11:     std::cout << pArray[i] << ' ';
12: }
13: std::cout << std::endl;
14: 
15: // releasing memory - note: array delete (!)
16: delete[] pArray;
```

*Ausgabe*:


```
0 1 2 3 4 5 6 7 8 9
```

*Achtung*:


Es gibt den `delete`-Oprator in zwei Auspr�gungen &ndash; also auch syntaktisch
in zwei Schreib`weisen:

  * `delete ptr` &ndash; ruft den skalaren L�schdestruktor auf.
  * `delete [] ptr`  &ndash; ruft den Destruktor zum L�schen von Vektoren auf.

  https://stackoverflow.com/questions/39283233/why-in-vc-both-delete-and-delete-uses-scalar-deleting-destructor

  WEIER !!!!!!!!!!!!!!!


### *Beispiel* 3: Reservieren und Freigeben eines Speicherbereichs f�r ein Objekt:

```cpp
01: class SimpleClass
02: {
03: public:
04:     SimpleClass() { std::cout << "Default constructor SimpleClass" << std::endl; }
05: 
06:     void print () { std::cout << "SimpleClass" << std::endl; }
07: };
08: 
09: void dynamicMemory_Object()
10: {
11:     // allocating a single variable
12:     SimpleClass* pSimpleClass = new SimpleClass;
13:     pSimpleClass->print();
14: 
15:     // releasing memory
16:     delete pSimpleClass;
17: }
18: 
```


*Ausgabe*:


```
Default constructor SimpleClass
SimpleClass
```

---

## Quellcode des Beispiels:

[Main.cpp](..\DynamicMemoryManagement\Main.cpp)

---


## �bungen

TBD: XXX


---

[Zur�ck](Agenda.md)

---
