# Aufgabe zu dynamischen Daten

[Zurück](./Exercises.md)

---

## Übersicht

Folgende C++&ndash;Sprachmittel sollen zum Einsatz kommen:
  * Umgang mit den Operatoren `new` und `delete`
  * Realisierung einer Klasse mit dynamischen Daten
  * Handhabung der Regel *Rule-of-Three*

## Beschreibung

Der Datentyp *Array* steht in C++ für Felder fester Länge.
Es gibt keinerlei Möglichkeit, nach dem Erzeugen eines Felds dessen Länge zu ändern.

```cpp
int numbers[10];
```

Der Wert 10 muss zur Übersetzungszeit bekannt sein.

An dieser Stelle kommt die dynamische Speicherverwaltung ins Spiel:
Mit Hilfe der beiden Operatoren `new` und `delete` kann man eine Klasse `DynamicArray`,
die im Prinzip dieselbe Funktionalität wie C++-Felder besitzt,
nur mit dem Unterschied, dass die Längenangabe sowohl zum Erzeugungszeitpunkt
als auch während der Lebenszeit eines `DynamicArray`-Objekts änderbar ist.

Eine mögliche Schnittstelle einer Klasse `DynamicArray` könnte so aussehen:

| Element        | Schnittstelle und Beschreibung |
|:-------------- |-----------------------------------------|
| Standard-Konstruktor | `DynamicArray();`<br/>Belegt die Instanzvariablen mit datentypspezifischen Null-Werten. |
| Benutzerdefinierter Konstruktor | `DynamicArray(size_t size);`<br/>Legt ein Feld der Länge `size` an. |
| *getter* `size()`  | `size_t size() const;`<br/>Liefert die aktuelle Länge zurück. |
| `at`     | `int& at (size_t index);`<br/> Zugriff auf ein Element an der `index` Stelle. Bei ungültigem Index wird eine Ausnahme geworfen. |
| Operator `[]`  | `int& operator[] (size_t index);`<br/>Wie Methode `at`, nur ohne Gültigkeitsüberprüfung des Index. |
| `clear` | `void clear();`<br/>Gibt den dynamisch allokierten Speicher frei. |
| `resize` | `void resize(size_t newSize);`<br/>Ändert die Länge das Speicherbereichs. Dabei sind die vorhandenen Daten des aktuellen Felds in das neue Feld zuzukopieren. Ist die neue Länge kürzer als die vorhandene, gehen die Daten im oberen Teil des Felds verloren. Ist das neue Feld hingegen länger, kann das aktuelle Feld komplett umkopiert werden und die verbleibenden Elemente im oberen Bereich sind mit `0` vorzubelegen. |

*Tabelle* 1. Elemente der Klasse `DynamicArray`.

---

## Quellcode der Lösungen:

[*DynamicArray.h*](./DynamicArray/DynamicArray.h)<br />
[*DynamicArray.cpp*](./DynamicArray/DynamicArray.cpp)<br />
[*DynamicArray_Main.cpp*](./DynamicArray/DynamicArray_Main.cpp)<br />

---

[Zurück](./Exercises.md)

---
