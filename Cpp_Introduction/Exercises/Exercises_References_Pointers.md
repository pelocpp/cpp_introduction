# Betrachtungen zur Parameter�bergabe

[Zur�ck](./Exercises.md)

---

## �bersicht

Folgende C++&ndash;Sprachmittel sollen zum Einsatz kommen:

  * Parameter�bergabe *Call-by_Value*
  * Parameter�bergabe mit Zeigern
  * Parameter�bergabe mit Referenzen

## Beschreibung

Wir betrachten die folgende Funktion `swap`:

```cpp
01: void swap(int n, int m)
02: {
03:     int tmp = n;
04:     n = m;
05:     m = tmp;
06: }
```

Im folgenden Beispiel finden Sie einen Aufruf der `swap`-Funktion vor:

```cpp
01: void passingParameters ()
02: {
03:     int a = 1;
04:     int b = 2;
05: 
06:     std::cout << "a: " << a << " - b: " << b << std::endl;
07:     swap(a, b);
08:     std::cout << "a: " << a << " - b: " << b << std::endl;
09: }
```

  * Welche Ausgaben w�rden Sie in der Konsole erwarten?
  * Welche Ausgaben finden Sie in der Konsole vor?

Wie kann man eine Funktion `swap` so schreiben, dass sie ihrem Namen auch gerecht
wird und die Werte der beiden Variablen `a` und `b` vertauscht.

Erstellen Sie zwei Realisierungen einer modifizierten `swap`-Funktion.
Greifen Sie dabei einmal auf das Sprachmittel der Zeiger zur�ck und 
in einer weiteren Version auf Referenzen.

---

## Quellcode der L�sungen:

[*References_Pointers_Main.cpp*](./References_Pointers/References_Pointers_Main.cpp)<br />

---

[Zur�ck](./Exercises.md)

---
