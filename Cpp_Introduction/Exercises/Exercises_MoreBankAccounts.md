# Aufgabe zu Bankkonten und Vererbung

[Zur�ck](./Exercises.md)

---

## �bersicht

Folgende C++&ndash;Sprachmittel sollen zum Einsatz kommen:

  * �berschreiben von Methoden
  * Schl�sselw�rter `virtual`, `override` und `final`
  * Schnittstellenkonzept (*Interface*)
  * Abstrakte Basisklasse


## Beschreibung

Erstellen Sie eine Klasse `Account`, die das Guthaben eines Kontos verwaltet.
Die Kontonummer wird von der Klasse `Account` mit Hilfe einer Klassenvariablen bestimmt.

Die Klasse soll Methoden `deposit` zum Einzahlen und `withdrawal` zum Abheben besitzen.

Ausk�nfte �ber das Bankkonto k�nnen mit Hilfe der Eigenschaften `getNumber` (Kontonummer)
und `getBalance` (Kontostand) eingeholt werden.

---

Da das Bankinstitut mehrere Arten von Konten seinen Kunden anbietet,
ist der Klassenentwurf in mehreren Ebenen zu gestalten:

  * Schnittstelle `IAccount` &ndash; Beschreibung der Methoden der Klasse `Account`.<br />
    Oder anders formuliert: Was sollten alle Realisierungen einer Konto-Klasse f�r Methoden haben?
  * Klasse `Account` &ndash; Teilweise Realisierung der Methoden der Klasse `Account` &ndash; Beschreibung siehe weiter unten.
  * Klassen `CurrentAccount` (Girokonto), `StudentsAccount` (Sch�lerkonto) und `DepositAccount` (Sparbuch).

---

## Girokonten, Sch�lerkonten und Sparb�cher

Schreiben Sie drei weitere Klassen `CurrentAccount` (Girokonto), `StudentsAccount` (Konto ohne �berziehungsrahmen) und `DepositAccount` (Sparbuch), die Sie geeignet mit der Klasse `Account` in Beziehung setzen.
Die drei Klassen sollen folgende Eigenschaften aufweisen:

  * Klasse `CurrentAccount`</br>Ein Girokonto darf um ein Dispolimit �berzogen werden,
    das bei der Kontoer�ffnung festzulegen ist. Das Dispolimit ist als Eigenschaft der Klasse `CurrentAccount` zu realisieren
    und kann zu einem sp�teren Zeitpunkt auch angepasst werden.
    Der Einfachheit halber legen wir zu Grunde, dass f�r das �berziehen des Girokontos keine Zinsen zu entrichten sind.

  * Klasse `StudentsAccount`</br>Ein Konto f�r Sch�ler und Studenten verh�lt sich im Prinzip
    wie ein Girokonto. Der einzige Unterschied besteht darin, dass es keinen �berziehungsrahmen besitzt.

  * Klasse `DepositAccount`</br>Auf einem Sparkonto fallen f�r das eingezahlte Geld Zinsen an.
    Der Zinssatz des Sparkontos ist als Eigenschaft der Klasse `DepositAccount` darzustellen.
    Nach der Kontoer�ffnung kann der Zinssatz nicht mehr ge�ndert werden.
    F�r die Gutschrift der Zinsen auf dem Sparkonto bedarf es einer zus�tzlichen Methode `computeInterest`.
    Diese Methode besitzt als Parameter die Anzahl der Tage, f�r die die Zinsen gutzuschreiben sind.
    Die Zinsen sind nach der Formel

    $$Zinsen = \frac{AnzahlTage}{365} * \frac{Zinssatz}{100} * Guthaben$$

    zu berechnen.

---

## Hinweis zur Realisierung

Man k�nnte geneigt sein, die beiden Kontotypen *Studentenkonto* und *Girokonto* in Beziehung
zueinander zu setzen. Zum Beispiel k�nnte man argumentieren, ein Studentenkonto &ldquo;ist-ein&rdquo; Girokonto
mit Dispolimit 0. Oder auch anders herum: Ein Girokonto &ldquo;ist-ein&rdquo; Studentenkonto erweitert um
das Feature eines Dispolimits.

Warum f�hren beide �berlegungen nicht ans Ziel?

*Antwort*:

�berlegung 1:<br />
Ein Studentenkonto ist *kein* Girokonto, weil es sonst die Methode `setLimit` des Girokontos erben w�rde.
Dies ist aber nicht erw�nscht.

�berlegung 2:<br />
Ein Girokonto ist *kein* Studentenkonto, weil es sonst die Methode `withdraw` des Studentenkonto ersetzen m�sste.
Technisch gesehen geht dies, konzeptionell ist diese Vorgehensweise aber eher fragw�rdig.

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
da.updateInterest(31);
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

## Quellcode der L�sungen:

[*MoreBankAccounts.cpp*](./MoreBankAccounts/MoreBankAccounts_Main.cpp)<br />

---

[Zur�ck](./Exercises.md)

---
