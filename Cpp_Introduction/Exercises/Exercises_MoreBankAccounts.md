# Aufgabe zu Bankkonten und Vererbung

[Zurück](./Exercises.md)

---

## Übersicht

Folgende C++&ndash;-Sprachmittel sollen zum Einsatz kommen:

  * Überschreiben von Methoden
  * Schlüsselwörter `virtual`, `override` und `final`
  * Schnittstellenkonzept (*Interface*)
  * Abstrakte Basisklasse


## Beschreibung

Erstellen Sie eine Klasse `Account`, die das Guthaben eines Kontos verwaltet.
Die Kontonummer wird von der Klasse `Account` mit Hilfe einer Klassenvariablen bestimmt.

Die Klasse soll Methoden `deposit` zum Einzahlen und `withdrawal` zum Abheben besitzen.

Auskünfte über das Bankkonto können mit Hilfe der Eigenschaften `getNumber` (Kontonummer)
und `getBalance` (Kontostand) eingeholt werden.

---

Da das Bankinstitut mehrere Arten von Konten seinen Kunden anbietet,
ist der Klassenentwurf in mehreren Ebenen zu gestalten:

  * Schnittstelle `IAccount` &ndash; Beschreibung der Methoden der Klasse `Account`.<br />
    Oder anders formuliert: Was sollten alle Realisierungen einer Konto-Klasse für Methoden haben?
  * Klasse `Account` &ndash; Teilweise Realisierung der Methoden der Klasse `Account` &ndash; Beschreibung siehe weiter unten.
  * Klassen `CurrentAccount` (Girokonto), `StudentsAccount` (Schülerkonto) und `DepositAccount` (Sparbuch).

---

## Girokonten, Schülerkonten und Sparbücher

Schreiben Sie drei weitere Klassen `CurrentAccount` (Girokonto), `StudentsAccount` (Konto ohne Überziehungsrahmen) und `DepositAccount` (Sparbuch), die Sie geeignet mit der Klasse `Account` in Beziehung setzen.
Die drei Klassen sollen folgende Eigenschaften aufweisen:

  * Klasse `CurrentAccount`</br>Ein Girokonto darf um ein Dispolimit überzogen werden,
    das bei der Kontoeröffnung festzulegen ist. Das Dispolimit ist als Eigenschaft der Klasse `CurrentAccount` zu realisieren
    und kann zu einem späteren Zeitpunkt auch angepasst werden.
    Der Einfachheit halber legen wir zu Grunde, dass für das Überziehen des Girokontos keine Zinsen zu entrichten sind.

  * Klasse `StudentsAccount`</br>Ein Konto für Schüler und Studenten verhält sich im Prinzip
    wie ein Girokonto. Der einzige Unterschied besteht darin, dass es keinen Überziehungsrahmen besitzt.

  * Klasse `DepositAccount`</br>Auf einem Sparkonto fallen für das eingezahlte Geld Zinsen an.
    Der Zinssatz des Sparkontos ist als Eigenschaft der Klasse `DepositAccount` darzustellen.
    Nach der Kontoeröffnung kann der Zinssatz nicht mehr geändert werden.
    Für die Gutschrift der Zinsen auf dem Sparkonto bedarf es einer zusätzlichen Methode `computeInterest`.
    Diese Methode besitzt als Parameter die Anzahl der Tage, für die die Zinsen gutzuschreiben sind.
    Die Zinsen sind nach der Formel

    <img src="Bankkonto_Zinssatz.png" width="300">

    zu berechnen.

---

Die Programmausgabe studieren Sie an folgenden Codefragmenten:

*Beispiel*:

```cpp
CurrentAccount ca(1000);
ca.deposit(100);
ca.withdraw(40);
ca.print();

StudentsAccount sa;
sa.deposit(50);
sa.withdraw(25);
sa.print();

DepositAccount da(4.0);
da.deposit(200);
da.withdraw(120);
da.computeInterest(31);
da.print();
```

*Ausgabe*:

```
CurrentAccount:
    [Nr. 10000]:
    Balance = 60;
    Limit = 1000;
StudentsAccount:
    [Nr. 10001]:
    Balance = 25;
DepositAccount:
    [Nr. 10002]:
    Balance = 80.2718;
    InterestRate = 4;
```

*Beispiel*:

```cpp
CurrentAccount ca(1000);
ca.deposit(100);
ca.print();

StudentsAccount sa;
sa.deposit(50);
sa.print();

DepositAccount da(4.0);
da.deposit(200);
da.print();

IAccount* accounts[3]{ &ca, &sa, &da };

double totalBalance = 0;
for (int i = 0; i < 3; ++i) {

    totalBalance += accounts[i]->getBalance();
}

std::cout << "Total Balance: " << totalBalance << std::endl;
```

*Ausgabe*:

```
CurrentAccount:
    [Nr. 10000]:
    Balance = 100;
    Limit = 1000;
StudentsAccount:
    [Nr. 10001]:
    Balance = 50;
DepositAccount:
    [Nr. 10002]:
    Balance = 200;
    InterestRate = 4;
Total Balance: 350
```

---

## Quellcode der Lösungen:

[*MoreBankAccounts.cpp*](./MoreBankAccounts/MoreBankAccounts.cpp)<br />

---

[Zurück](./Exercises.md)

---
