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
  * Nur Euros entnehmen.
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

Die folgenden zwei Beispiele demonstrieren den Umgang mit der Klasse `Wallet`:

```cpp
01: void test()
02: {
03:     Wallet wallet(15, 55);
04:     std::cout << wallet << std::endl;
05: 
06:     wallet.add(5);
07:     std::cout << wallet << std::endl;
08: 
09:     Wallet secondwallet(9, 45);
10:     wallet.add(secondwallet);
11:     std::cout << wallet << std::endl;
12: 
13:     wallet.sub(30);
14:     std::cout << wallet << std::endl;
15: 
16:     wallet.sub(1);
17:     std::cout << wallet << std::endl;
18: }
```

*Ausgabe*:


```
15.55
20.55
30.00
0.00
Exception: Not enough money available in wallet!
```

Und noch ein zweites Beispiel:


```cpp
01: void test()
02: {
03:     Wallet wallet1(10, 20);
04:     Wallet wallet2(20, 10);
05: 
06:     std::cout << std::boolalpha << (wallet1 == wallet1) << std::endl;
07:     std::cout << std::boolalpha << (wallet1 == wallet2) << std::endl;
08:     std::cout << std::boolalpha << (wallet1 != wallet2) << std::endl;
09: 
10:     std::cout << std::boolalpha << (wallet1  < wallet2) << std::endl;
11:     std::cout << std::boolalpha << (wallet1 <= wallet2) << std::endl;
12:     std::cout << std::boolalpha << (wallet1  > wallet2) << std::endl;
13:     std::cout << std::boolalpha << (wallet1 >= wallet2) << std::endl;
14: }
```

*Ausgabe*:


```
true
false
true
true
true
false
false
```

---

## Quellcode der Lösungen:

[*Wallet.h*](./Wallet/Wallet.h)<br />
[*Wallet.cpp*](./Wallet/Wallet.cpp)<br />
[*Wallet_Main.cpp*](./Wallet/Wallet_Main.cpp)<br />

---

[Zurück](./Exercises.md)

---
