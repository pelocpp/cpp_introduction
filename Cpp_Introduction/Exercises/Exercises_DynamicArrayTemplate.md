# Klassentemplate zur Klasse `DynamicArray`

[Zurück](./Exercises.md)

---

## Übersicht

Folgende C++&ndash;Sprachmittel sollen zum Einsatz kommen:
  * Templates

## Beschreibung

In der Aufgabe zu [Dynamische Daten](./Exercises_DynamicArray.md) betrachteten wir eine Klasse für ein 
flexibel langes Array. Konkret ließen sich mit der Klasse `DynamicArray`
aber nur beliebig lange `int`-Felder anlegen.

Erstellen Sie in dieser Aufgabe nun ein Klassentemplate `DynamicArrayTemplate`,
das diesselbe Funktionalität wie Klasse  `DynamicArray` besitzt,
aber für unterschiedliche Datentypen instanziiert werden kann.

*Beispiel*:

```cpp
DynamicArrayTemplate<std::string> array(3);
array[0] = "one";
array[1] = "two";
array[2] = "three";
array.print();
```

---

## Quellcode der Lösungen:

[*DynamicArrayTemplate.h*](./DynamicArrayTemplate/DynamicArrayTemplate.h)<br />
[*DynamicArrayTemplate_Main.cpp*](./DynamicArrayTemplate/DynamicArrayTemplate_Main.cpp)<br />

---

[Zurück](./Exercises.md)

---
