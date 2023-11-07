# Aufgabe zur Klasse `std::string`

[Zurück](./Exercises.md)

---

## Zielsetzung

Folgende C++&ndash;-Sprachmittel sollen zum Einsatz kommen:

  * Umgang mit der Klasse `std::string`


## Beschreibung

Schreiben Sie eine Funktion `verifyDateFormat`, der ein `std::string`-Objekt übergeben wird.
Diese Zeichenkette enthält ein Datum in der Form *dd.mm.jjjj*.
Die Funktion überprüft den korrekten Aufbau der Zeichenkette.

Schreiben Sie eine weitere Funktion `dateToWord`, die ebenfalls ein `std::string`-Objekt als Argument hat:

```cpp
std::string dateToWord(std::string date);
```

Diese Funktion wandelt dieses Datum so um, das der Monat als Wort ausgeschrieben ist.
Führende Nullen der Tagesangabe werden dabei gelöscht.

Wenn der Funktion zum Beispiel *01.11.2023* übergeben wird,
dann ändert sie diese Zeichenkette in *1. November 2023* um.
Für den Fall, dass eine Zeichenkette mit einem falschen Format übergeben wird,
wird eine leere Zeichenkette zurückgegeben.


*Beispiel*:

```cpp
01: void testDateToWord()
02: {
03:     // test 'dateToWord'
04:     std::string s = dateToWord("01.11.2023");
05:     std::cout << s << std::endl;
06: }
```

*Ausgabe*:


```
1. November 2023
```

---

## Quellcode der Lösungen:

[*Strings_Main.cpp*](./Strings/Strings_Main.cpp)<br />

---

[Zurück](./Exercises.md)

---
