# Klassentemplate zur Klasse `DynamicArray`

[Zur�ck](./Exercises.md)

---

## �bersicht

Folgende C++&ndash;Sprachmittel sollen zum Einsatz kommen:
  * Templates

## Beschreibung

In der Aufgabe zu [Dynamische Daten](./Exercises_DynamicArray.md) betrachteten wir eine Klasse f�r ein 
flexibel langes Array. Konkret lie�en sich mit der Klasse `DynamicArray`
aber nur beliebig lange `int`-Felder anlegen.

Erstellen Sie in dieser Aufgabe nun ein Klassentemplate `DynamicArrayTemplate`,
das diesselbe Funktionalit�t wie Klasse  `DynamicArray` besitzt,
aber f�r unterschiedliche Datentypen instanziiert werden kann.

*Beispiel*:

```cpp
DynamicArrayTemplate<std::string> array(3);
array[0] = "one";
array[1] = "two";
array[2] = "three";
array.print();
```

---

## Quellcode der L�sungen:

[*DynamicArrayTemplate.h*](./DynamicArrayTemplate/DynamicArrayTemplate.h)<br />
[*DynamicArrayTemplate_Main.cpp*](./DynamicArrayTemplate/DynamicArrayTemplate_Main.cpp)<br />

---

[Zur�ck](./Exercises.md)

---
