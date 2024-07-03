# Aufgabe zu einem Geldbeutel: Klasse `Wallet`

[Zurück](./Exercises.md)

---

## Übersicht

Folgende C++&ndash;Sprachmittel sollen zum Einsatz kommen:

  * Klasse und Objekt
  * Konstruktoren
  * Zugriffsrechte (`private`, `public`)
  * *getter*-Methoden
  * Realisierung einfacher Methoden
  * Klasse `std::string`
  * Überladen von Operatoren
  * Exception-Handling mit `try`, `catch` und `throw`


## Beschreibung

Schreiben Sie eine Klasse `Wallet`, die einen *Geldbeutel* (*Portemonnaie*, ein aus dem Französischen stammender Begriff)
repräsentiert.
Im Geldbeutel sind Euros und Cent enthalten.
Dabei sollten nicht mehr als 99 Cent in dem Geldbeutel sein,
bei größeren Cent-Beträgen ist der Euro-Betrag entsprechend aufzurunden.

Logischerweise kann ein Geldbeutel keine negativen Geldbeträge enthalten.
Es ist bei allen Methoden und Operatoren in der Realisierung der Klasse `Wallet` darauf zu achten, dass niemals mehr Geld entnommen wird
als sich in dem Geldbeutel befindet.

Folgende Aktivitäten sollten mit einem Geldbeutel möglich sein:

  * Geld hinzufügen.
  * Geld entnehmen, allerdings nicht mehr, als im Geldbeutel ist.
  * Den Inhalt zweier Geldbeutel vergleichen.
  * Nur Euros hinzufügen.
  * Nur Cent hinzufügen.
  * Nur Euros entnehmen.
  * Nur Cent entnehmen.
  * Einen Geldbeutel als `std::string`-Objekt darstellen.
  * Einen Geldbeutel mit dem Operator `operator<<` auf der Konsole ausgeben.
  * Einen Euro hinzufügen.
  * Einen Euro entnehmen.

---

## Hinweis

Beachten Sie folgenden Hinweis zur Realisierung der Konstruktoren: Mit

```cpp
Wallet wallet(5, 55);
```

erzeugt man einen Geldbeutel, der 5€ und 55 Cent enthält. Ist es möglich, Aufrufe der Gestalt

```cpp
Wallet wallet(-5, 55);
```

oder

```cpp
Wallet wallet(5, -55);
```

zu verhindern? Welchen Weg muss man hierzu in der Realisierung der Konstruktoren einschlagen?

---

## Beispiele

Die folgenden Beispiele demonstrieren den Umgang mit der Klasse `Wallet`:

```cpp
01: void test()
02: {
03:     Wallet wallet(2, 50);
04:     std::cout << wallet << std::endl;
05: 
06:     std::cout << "Wallet contains " << wallet.getEuros() << " euros." << std::endl;
07:     std::cout << "Wallet contains " << wallet.getCent() << " cent." << std::endl;
08: }
```

*Ausgabe*:

```
2.50
Wallet contains 2 euros.
Wallet contains 50 cent.
```

Es folgt ein Beispiel zum Hinzufügen und Entnehmen von Geldbeträgen:

```cpp
01: void test()
02: {
03:     Wallet wallet(2, 50);
04:     std::cout << wallet << std::endl;
05: 
06:     wallet.add(5);
07:     std::cout << wallet << std::endl;
08: 
09:     wallet.sub(7);
10:     std::cout << wallet << std::endl;
11: }
```

*Ausgabe*:

```
2.50
7.50
0.50
```

Ein drittes Beispiel demonstriert die Behandlung von Ausnahmen.
Es sollte dann eine Ausnahme geworfen werden, wenn versucht wird,
mehr Geld aus einem Geldbeutel zu entnehmen als dieser enthält:


```cpp
01: void test()
02: {
03:     Wallet wallet(2, 50);
04:     std::cout << wallet << std::endl;
05: 
06:     try
07:     {
08:         wallet.sub(3);
09:     }
10:     catch (const std::invalid_argument& ex)
11:     {
12:         std::cout << ex.what() << std::endl;
13:     }
14: 
15:     std::cout << wallet << std::endl;
16: }
```

*Ausgabe*:

```
2.50
Not enough money available in wallet!
2.50
```

Mit Hilfe der arithmetischen Wertzuweisungsoperatoren
kann man das Hinzufügen von Euros sehr anschaulich formulieren:

```cpp
01: void test()
02: {
03:     Wallet wallet(2, 50);
04:     std::cout << wallet << std::endl;
05: 
06:     wallet += 3;
07:     std::cout << wallet << std::endl;
08: }
```

*Ausgabe*:

```
2.50
5.50
```

Mit den Vergleichsoperatoren kann man die Inhalte zweier Geldbeutel vergleichen:

```cpp
01: void test()
02: {
03:     Wallet wallet1(2, 50);
04:     std::cout << wallet1 << std::endl;
05: 
06:     Wallet wallet2(3, 75);
07:     std::cout << wallet2 << std::endl;
08: 
09:     if (wallet1 < wallet2) {
10:         std::cout << "Wallet 1 contains less money than Wallet 2" << std::endl;
11:     }
12: 
13:     wallet1 = wallet2;
14:     std::cout << wallet1 << std::endl;
15:     std::cout << wallet1 << std::endl;
16: 
17:     if (wallet1 == wallet2) {
18:         std::cout << "Wallet 1 contains the same amount of money as Wallet 2." << std::endl;
19:     }
20: }
```

*Ausgabe*:

```
2.50
3.75
Wallet 1 contains less money than Wallet 2
3.75
3.75
Wallet 1 contains the same amount of money as Wallet 2.
```

---

## Quellcode der Lösungen:

[*Wallet.h*](./Wallet/Wallet.h)<br />
[*Wallet.cpp*](./Wallet/Wallet.cpp)<br />
[*Wallet_Main.cpp*](./Wallet/Wallet_Main.cpp)<br />

---

[Zurück](./Exercises.md)

---
