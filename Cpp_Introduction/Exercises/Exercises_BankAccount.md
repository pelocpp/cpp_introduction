# Aufgabe Klasse `BankAccount`

[Zur�ck](./Exercises.md)

---

## �bersicht

Zielsetzung ist eine Klasse `BankAccount`, die ein Bankkonto repr�sentiert.

Ein Bankkonto hat eine Kontonummer und einen Kontostand.
Es soll m�glich sein, Geldbetr�ge einzahlen und abheben zu k�nnen.
Ausk�nfte �ber das Bankkonto lassen sich bzgl. Kontonummer und Kontostand einholen.
Die Informationen des Kontos lassen sich in der Konsole ausgeben.

### Beschreibung

Folgende C++&ndash;-Sprachmittel sollen zum Einsatz kommen:

  * Klasse und Objekt
  * Konstruktoren
  * Zugriffsklassen
  * *getter*- und *setter*-Methoden
  * Methoden
  * Klassenvariablen
  * �berladen von Operatoren

Betrachten Sie Details in der Arbeitsweise der Klasse `BankAccount` an folgendem Beispiel:

```cpp
BankAccount myAccount(50);
myAccount.deposit(50);
myAccount.withdraw(25);
myAccount.print();
```

*Ausgabe*:


```
BankAccount Nr. 10000:   Balance=25.
```


*Hinweise*:

Die Kontonummer ist intern in der Klasse `BankAccount` geeignet durch eine Klassenvariable
zu verwalten. Der erste Kunde erh�lt die Kontonummer 10.000, danach werden die Kontonummern
in aufsteigender Reihenfolge vergeben.


*Hinweise*:

einzahlen: engl. &ldquo;*to deposit*&rdquo;<br />
abheben: engl. &ldquo;*to withdraw*&rdquo;<br />
Kontostand: engl. &ldquo;*balance*&rdquo;

### Erweiterung

Die Methode zum Abheben (`withdraw`) schl�gt fehl, wenn auf dem Konto nicht gen�gend Geld vorhanden ist.
Wie k�nnte man dies in einer Verbesserung der `withdraw`-Methode zum Ausdruck bringen?

*Hinweise*:


```cpp
BankAccount myAccount;
myAccount.deposit(25);
bool succeeded = myAccount.withdraw(50);
if (! succeeded) {
    std::cout << "Need more money :)" << std::endl;
}
```


### Erweiterung

Wir erg�nzen nun die Klasse `BankAccount` um den Aspekt *Zinsen*.
Da der Zinsatz variieren kann, f�gen wir der Klasse eine Methode
`setInterestRate` hinzu:

```cpp
void setInterestRate (double rate);  // stellt den aktuellen Zinsatz ein
```

Damit ist der Zinssatz im Konto vorhanden bzw. akualisiert.

Werden am Ende eines Monats oder eines Quartals die Zinsen auf dem Konto gutgeschrieben,
rufen wir die Methode

```cpp
void updateInterest (int days);
```

auf. Der Parameter `days` gibt die Anzahl der Tage an, f�r die die Zinsen gutgeschrieben werden.


### Erweiterung: Zwei Konto-Objekte vergleichen

Wir haben bereits eine Methode `equals` kennen gelernt,
um zwei Bankkonto-Objekte vergleichen zu k�nnen.

Dies wollen wir nun erweitern &ndash; und mit Hilfe der Syntax f�r Operatoren
auch lesbarer gestalten:

Realisieren Sie f�r die Klasse `BankAccount` 6 Operatoren


`==`, `!=`, `<`, `<=`, `>` und `>=`.

Dabei soll gelten:

  * Zwei Konto-Objekte sind genau dann *gleich*, wenn sie denselben Kontostand aufweisen.

  * Ein Konto-Objekt ist *kleiner-oder-gleich* als ein anderes Konto-Objekt,
    wenn die korrespondieren Kontost�nde (`m_balance`) kleiner oder gleich sind.


*Beispiel*:

```cpp
BankAccount accountJohn (12345);
BankAccount accountJack (12346);
accountJohn.deposit(50);
accountJack.deposit(25);
...
if (accountJohn > accountJack) {
    std::cout << "John has more money than Jack :)" << std::endl;
}
```


### Weiterarbeit

  * Ein Konto mit `std::cout` auf der Konsole ausgeben
  * Mehrere Konten in einem Array verwalten.



---

## Quellcode der L�sungen:

[*BankAccount.h*](./BankAccount/BankAccount.h)<br />
[*BankAccount.cpp*](./BankAccount/BankAccount.cpp)<br />
[*BankAccount_Main.cpp*](./BankAccount/BankAccount_Main.cpp)<br />

---

[Zur�ck](./Exercises.md)

---
