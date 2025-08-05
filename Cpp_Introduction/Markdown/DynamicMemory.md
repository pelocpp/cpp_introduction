# Dynamische Speicherverwaltung

[Zur�ck](Agenda.md)

---

## Erl�uterungen

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
Dieser Speicherbereich l�sst sich bis zum Ende des Programms
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

### *Beispiel* 5: Klasse `LotteryTickets` mit variabler Anzahl von Gl�ckslosen


```cpp
01: class LotteryTickets
02: {
03: private:
04:     int  m_count;
05:     int* m_tickets;
06: 
07: public:
08:     LotteryTickets() : m_count (0), m_tickets (NULL)
09:     {
10:         std::srand(  static_cast<unsigned int>(std::time(0))); // use current time as seed for random generator
11:     }
12: 
13:     ~LotteryTickets() {
14:         delete[] m_tickets; 
15:     }
16: 
17:     void buyTickets(int count)
18:     {
19:         m_count = count;
20:         m_tickets = new int[m_count];   // buying 'count' tickets at once
21: 
22:         for (int i = 0; i < m_count; i++) {
23:             m_tickets[i] = 1 + rand() % 49;
24:         }
25:     }
26: 
27:     void printTickets()
28:     {
29:         for (int i = 0; i < m_count; i++) {
30:             std::cout << "Ticket " << (i + 1) << ": " << m_tickets[i] << std::endl;
31:         }
32:     }
33: };
34: 
35: static void test_lottery()
36: {
37:     std::cout << "How many lottery tickets do you want to buy? ";
38: 
39:     int numTickets;
40:     std::cin >> numTickets;
41: 
42:     LotteryTickets lottery;
43:     lottery.buyTickets(numTickets);
44:     lottery.printTickets();
45: }
```

*Ausgabe*:

```
How many lottery tickets do you want to buy? 5
Ticket 1: 30
Ticket 2: 13
Ticket 3: 45
Ticket 4: 21
Ticket 5: 13
```

---

## Quellcode des Beispiels:

[*Main.cpp*](../DynamicMemory/Main.cpp)

---

## Aufgaben

[Aufgabe zur Klasse `DynamicIntArray`](../Exercises/Exercises_DynamicIntArray.md)

[Aufgabe zur Klasse `String`](../Exercises/Exercises_String.md)

---

[Zur�ck](Agenda.md)

---
