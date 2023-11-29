# Aufgabe zur Klasse `std::string`

[Zurück](./Exercises.md)

---

## Übersicht

Folgende C++&ndash;Sprachmittel sollen zum Einsatz kommen:

  * Umgang mit der Klasse `std::string`
  * Methoden `substr` und `append`
  * *getter*-Methode `length`
  * Index-Operator `operator []`, Konkatenationsoperator `+`
  * Weitere Bibliotheksfunktionen `std::isdigit` und `std::stoi`

## Beschreibung

Schreiben Sie eine Funktion `verifyDateFormat`, der ein `std::string`-Objekt übergeben wird.
Diese Zeichenkette enthält ein Datum in der Form *dd.mm.jjjj*.
Die Funktion überprüft den korrekten Aufbau dieser Zeichenkette.

*Beispiel*:

```cpp
bool isValid = verifyDateFormat("10.08.2000");
```

Schreiben Sie eine weitere Funktion `dateToWord`, die ebenfalls ein `std::string`-Objekt als Argument hat:

```cpp
std::string dateToWord(std::string date);
```

Diese Funktion wandelt dieses Datum so um, dass der Monat im Ergebnis der Funktion als Wort ausgeschrieben wird.
Führende Nullen der Tagesangabe werden dabei gelöscht.

Wenn der Funktion zum Beispiel *01.11.2023* übergeben wird,
dann ändert sie diese Zeichenkette in *1. November 2023* um.
Für den Fall, dass eine Zeichenkette mit einem falschen Format übergeben wird,
wird eine leere Zeichenkette zurückgegeben.


*Hinweis*:

In einer sehr guten Realisierung überprüfen Sie nicht nur das Format der Zeichenketten,
sondern auch die Gültigkeit der Werte. Die beiden Zeichenketten `32.12.2023` und `01.13.2023`
hätten somit ein korrektes Format, dennoch sind sie falsch.


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
