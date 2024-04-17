# Aufgabe zu dynamischen Daten: Klasse `DynamicIntArray`

[Zur�ck](./Exercises.md)

---

## �bersicht

Folgende C++&ndash;Sprachmittel sollen zum Einsatz kommen:
  * Umgang mit den Operatoren `new` und `delete`
  * Realisierung einer Klasse mit dynamischen Daten
  * Handhabung der Regel *Rule-of-Three*

## Beschreibung

Der Datentyp *Array* steht in C++ f�r Felder fester L�nge.
Es gibt keinerlei M�glichkeit, nach dem Erzeugen eines Felds seine L�nge zu �ndern.

```cpp
int numbers[10];
```

Der Wert 10 muss zur �bersetzungszeit bekannt sein.

An dieser Stelle kommt die dynamische Speicherverwaltung ins Spiel:
Mit Hilfe der beiden Operatoren `new` und `delete` kann man eine Klasse `DynamicIntArray` realisieren,
die im Prinzip dieselbe Funktionalit�t wie C++-Felder besitzt,
nur mit dem Unterschied, dass die L�ngenangabe sowohl zum Erzeugungszeitpunkt
als auch w�hrend der Lebenszeit eines `DynamicIntArray`-Objekts �nderbar ist.

Diese Flexibilit�t wird erreicht, indem die Daten des Felds in einem Speicherbereich auf der Halde (*Heap*) abgelegt werden.
Bei Bedarf, zum Beispiel, wenn der Datenbereich zu klein geworden ist, kann man auf der Halde ein gr��eres St�ck Speicher reservieren.

Implementieren Sie eine Klasse `DynamicIntArray`, die diese Eigenschaft besitzt.
Ein Objekt dieser Klasse sollte wie in *Abbildung* 1 gezeigt aussehen:

<img src="DynamicIntArray/Resources/cpp_dynamic_array_01.svg" width="550">

*Abbildung* 1. Instanzdatenbereich eines `DynamicIntArray`-Objekts mit dynamisch allokiertem Datenpuffer.

Wir erkennen in *Abbildung* 1 zwei Instanzvariablen in der Klasse `DynamicIntArray`: `m_data` und `m_length`.
`m_data` enth�lt die Adresse eines St�ck Speichers, das sich auf der Halde befindet und mit dem `new`-Operator angelegt wurde.
Die L�nge dieses Speicherbereichs wird in der zweiten Instanzvariablen `m_length` festgehalten.

Die Problematik, wenn der dynamisch allokierte Datenpuffer zu klein wird, haben wir bereits angesprochen.
*Abbildung* 2 soll veranschaulichen, wie wir mit einem gr��eren Datenpuffer gr��ere Anforderungen erf�llen k�nnen.
Neben einem gr��eren St�ck Speicher, das wieder mit dem `new`-Operator angelegt wird, ist zu beachten, dass der
vorhandene Inhalt des alten Speicherbereichs in den neuen umzukopieren ist.

<img src="DynamicIntArray/Resources/cpp_dynamic_array_02.svg" width="550">

*Abbildung* 2. Vergr��erung des Instanzdatenbereichs eines `DynamicIntArray`-Objekts.


In *Abbildung* 3 und *Abbildung* 4 sprechen wir ein letztes Problem in der Realisierung der `DynamicIntArray`-Klasse an:
Die Wertzuweisung zweier `DynamicIntArray`-Objekte. In einem ersten Ansatz k�nnte man geneigt sein zu denken,
dass diese einfach mit dem Kopieren der beteiligten Instanzvariablen umzusetzen ist.
*Abbildung* 3 versucht darzustellen, dass dies nicht zu einer Realisierung f�hrt, die man als korrekt ansehen kann:
Die beiden in *Abbildung* 3 dargestellten `DynamicIntArray`-Objekt haben einen gemeinsamen Datenbereich auf Grund des kopierten Zeigers.
Dies ist nicht das, was man sich unter einer echte Kopie vorstellt.

<img src="DynamicIntArray/Resources/cpp_dynamic_array_03.svg" width="550">

*Abbildung* 3. Falscher Ansatz beim Kopieren eines `DynamicIntArray`-Objekts.

*Abbildung* 4 veranschaulicht, wie hier korrekt vorzugehen ist: Eine Kopie eines `DynamicIntArray`-Objekts muss einen neuen, separaten
Datenbereich erhalten:

<img src="DynamicIntArray/Resources/cpp_dynamic_array_04.svg" width="550">

*Abbildung* 4. Korrekter Ansatz beim Kopieren eines `DynamicIntArray`-Objekts.


Eine m�gliche Schnittstelle der Klasse `DynamicIntArray` k�nnte so aussehen:

| Element        | Schnittstelle und Beschreibung |
|:-------------- |-----------------------------------------|
| Standard-Konstruktor | `DynamicIntArray();`<br/>Belegt die Instanzvariablen mit datentypspezifischen Null-Werten. |
| Benutzerdefinierter Konstruktor | `DynamicIntArray(size_t size);`<br/>Initialisiert ein `DynamicIntArray`-Objekt mit einem Datenpuffer der L�nge `size`. |
| Benutzerdefinierter Konstruktor | `DynamicIntArray(int* values, size_t count);`<br/>Initialisiert ein `DynamicIntArray`-Objekt mit den Werten eines Arrays `values` der L�nge `count`. |
| *getter* `size()`  | `size_t size() const;`<br/>Liefert die aktuelle L�nge des Datenpuffers zur�ck. |
| `at`     | `int& at (size_t i);`<br/> Zugriff auf ein Element an der Stelle *i*. Bei ung�ltigem Index wird eine Ausnahme geworfen. |
| Operator `[]` | `int& operator[] (size_t i);`<br/>Wie Methode `at`, nur ohne G�ltigkeits�berpr�fung des Index. |
| `fill` | `void fill(int value);`<br/>Belegt alle Elemente des Datenpuffers mit dem Wert `value`. |
| `resize` | `void resize(size_t newSize);`<br/>�ndert die L�nge des internen Datenpuffers. Die vorhandenen Daten im Puffer sollen dabei &ndash; soweit m�glich &ndash; erhalten bleiben, sprich: Ist die neue L�nge k�rzer im Vergleich zur aktuellen L�nge, spielen die Daten im oberen Teil des alten Puffers keine Rolle mehr. Ist die neue L�nge gr��er, ist der aktuelle Puffer komplett umzukopieren und die zus�tzlichen Elemente im oberen Bereich sind mit `0` vorzubelegen. |
| `shrinkToFit` | `void shrinkToFit();`<br/>Sollte auf Grund eines oder mehrerer `resize`-Aufrufe der Datenpuffer gr��er als erforderlich sein, wird ein neuer Datenpuffer mit exakt passender L�nge angelegt. Nat�rlich sind die vorhandenen Elemente des alten Puffers umzukopieren. |
| `minimum` | `int minimum() const;`<br/>Liefert das minimale Element im Datenpuffer zur�ck. |
| `maximum` | `int maximum() const;`<br/>Liefert das maximale Element im Datenpuffer zur�ck. |
| `indexOf` | `int indexOf(int value) const;`<br/>Liefert die Position des gesuchten Elements `value` im Datenpuffer zur�ck. Ist das Element nicht vorhanden, wird -1 zur�ckgegeben. |
| `contains` | `bool contains(int value) const;`<br/>Liefert `true` oder `false` zur�ck, je nach dem, ob das Element `value` vorhanden ist oder nicht. |
| `release` | `void release();`<br/>Gibt den dynamisch allokierten Speicher frei. |
| `print` | `void print();`<br/>Gibt alle Elemente des Datenpuffers in der Konsole aus. |
| `bool operator==` | `friend bool operator== (const DynamicIntArray& left, DynamicIntArray right);`<br/>Vergleicht zwei `DynamicIntArray`-Objekte auf Gleichheit. |
| `bool operator!=` | `friend bool operator!= (const DynamicIntArray& left, DynamicIntArray right);`<br/>Vergleicht zwei `DynamicIntArray`-Objekte auf Ungleichheit. |

*Tabelle* 1: Schnittstelle der Klasse `DynamicIntArray`.

Beachten Sie, dass neben den in *Tabelle* 1 aufgef�hrten Methoden
auch noch das Regelwerk der &ldquo;Rule of Three&rdquo; vorhanden ist.

---

## Quellcode der L�sungen:

[*DynamicIntArray.h*](./DynamicIntArray/DynamicIntArray.h)<br />
[*DynamicIntArray.cpp*](./DynamicIntArray/DynamicIntArray.cpp)<br />
[*DynamicIntArray_Main.cpp*](./DynamicIntArray/DynamicIntArray_Main.cpp)<br />

---

[Zur�ck](./Exercises.md)

---
