# Aufgabe zu dynamischen Daten

[Zur�ck](./Exercises.md)

---

## �bersicht

Folgende C++&ndash;Sprachmittel sollen zum Einsatz kommen:
  * Umgang mit den Operatoren `new` und `delete`
  * Realisierung einer Klasse mit dynamischen Daten
  * Handhabung der Regel *Rule-of-Three*

## Beschreibung

Der Datentyp *Array* steht in C++ f�r Felder fester L�nge.
Es gibt keinerlei M�glichkeit, nach dem Erzeugen eines Felds dessen L�nge zu �ndern.

```cpp
int numbers[10];
```

Der Wert 10 muss zur �bersetzungszeit bekannt sein.

An dieser Stelle kommt die dynamische Speicherverwaltung ins Spiel:
Mit Hilfe der beiden Operatoren `new` und `delete` kann man eine Klasse `DynamicArray`,
die im Prinzip dieselbe Funktionalit�t wie C++-Felder besitzt,
nur mit dem Unterschied, dass die L�ngenangabe sowohl zum Erzeugungszeitpunkt
als auch w�hrend der Lebenszeit eines `DynamicArray`-Objekts �nderbar ist.

Eine m�gliche Schnittstelle einer Klasse `DynamicArray` k�nnte so aussehen:

| Element        | Schnittstelle und Beschreibung |
|:-------------- |-----------------------------------------|
| Standard-Konstruktor | `DynamicArray();`<br/>Belegt die Instanzvariablen mit datentypspezifischen Null-Werten. |
| Benutzerdefinierter Konstruktor | `DynamicArray(size_t size);`<br/>Legt ein Feld der L�nge `size` an. |
| *getter* `size()`  | `size_t size() const;`<br/>Liefert die aktuelle L�nge zur�ck. |
| `at`     | `int& at (size_t index);`<br/> Zugriff auf ein Element an der `index` Stelle. Bei ung�ltigem Index wird eine Ausnahme geworfen. |
| Operator `[]` | `int& operator[] (size_t index);`<br/>Wie Methode `at`, nur ohne G�ltigkeits�berpr�fung des Index. |
| `fill` | `void fill(int value);`<br/>Belegt alle Elemente des Arrays mit dem Wert `value`. |
| `resize` | `void resize(size_t newSize);`<br/>.�ndert die L�nge das Speicherbereichs. Die vorhandenen Daten im Feld sollen dabei &ndash; soweit m�glich &ndash; erhalten bleiben, sprich: Ist die neue L�nge k�rzer im Vergleich zur aktuellen L�nge, spielen die Daten im oberen Teil des Felds keine Rolle mehr. Ist die neue L�nge gr��er, ist das aktuelle Feld komplett umzukopieren und die zus�tzlichen Elemente im oberen Bereich sind mit `0` vorzubelegen. |
| `release` | `void release();`<br/>Gibt den dynamisch allokierten Speicher frei. |
| `print` | `void print();`<br/>.Gibt alle Elemente des Arrays in der Konsole aus. |
| `bool operator==` | `friend bool operator== (const DynamicArray& left, DynamicArray right);`<br/>Vergleicht zwei `DynamicArray`-Objekte auf Gleichheit. |
| `bool operator!=` | `friend bool operator!= (const DynamicArray& left, DynamicArray right);`<br/>Vergleicht zwei `DynamicArray`-Objekte auf Ungleichheit. |

*Tabelle* 1.

Beachten Sie, dass neben den in *Tabelle* 1 aufgef�hrten Methoden
auch noch das Reglwerk der &ldquo;Rule of Three&rdquo; vorhanden ist.

---

## Quellcode der L�sungen:

[*DynamicArray.h*](./DynamicArray/DynamicArray.h)<br />
[*DynamicArray.cpp*](./DynamicArray/DynamicArray.cpp)<br />
[*DynamicArray_Main.cpp*](./DynamicArray/DynamicArray_Main.cpp)<br />

---

[Zur�ck](./Exercises.md)

---
