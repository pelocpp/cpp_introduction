# Aufgabe zur Klasse `BankAccount`

[Zurück](./Exercises.md)

---

## Übersicht

Zielsetzung ist eine Klasse `BankAccount`, die ein Bankkonto repräsentiert.

Ein Bankkonto hat eine Kontonummer und einen Kontostand.
Es soll möglich sein, Geldbeträge einzahlen und abheben zu können.
Auskünfte über das Bankkonto lassen sich bzgl. Kontonummer und Kontostand einholen.
Die Informationen des Kontos lassen sich in der Konsole ausgeben.

Folgende C++&ndash;-Sprachmittel sollen zum Einsatz kommen:

  * Klasse und Objekt
  * Konstruktoren
  * Zugriffsklassen
  * *getter*- und *setter*-Methoden
  * Methoden
  * Klassenvariablen
  * Überladen von Operatoren

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


*Erster Hinweis*:

einzahlen: engl. &ldquo;*to deposit*&rdquo;<br />
abheben: engl. &ldquo;*to withdraw*&rdquo;<br />
Kontostand: engl. &ldquo;*balance*&rdquo;


*Zweiter Hinweis*:

Die Kontonummer ist intern in der Klasse `BankAccount` geeignet durch eine Klassenvariable
zu verwalten. Der erste Kunde erhält die Kontonummer 10.000, danach werden die Kontonummern
in aufsteigender Reihenfolge vergeben.


### Erste Erweiterung

Die Methode zum Abheben (`withdraw`) schlägt fehl, wenn auf dem Konto nicht genügend Geld vorhanden ist.
Wie könnte man dies in einer Verbesserung der `withdraw`-Methode zum Ausdruck bringen?

*Beispiel*:

```cpp
BankAccount myAccount;
myAccount.deposit(25);
bool succeeded = myAccount.withdraw(50);
if (! succeeded) {
    std::cout << "Need more money :)" << std::endl;
}
```


### Zweite Erweiterung

Bankkonten lassen sich vergleichen. Im echten Leben interessieren wir uns natürlich für den Geldbetrag,
der auf einem Konto verfügbar ist. Wir vergleichen also zwei Bankkonten mit einer `equals`-Methode,
indem wir die jeweiliegen Kontostände vergleichen.

Dies bedeutet anders herum betrachtet, dass die Kontonummer beim Vergleichen keine Rolle spielt.
Dies ist kein Widerspruch, denn unter Einbeziehung der Kontonummer könnte man nie zwei Konten vergleichen,
da Kontonummern ja immer verschieden sein müssen.

Wie ist die Schnittstelle einer Methode `equals` zu definieren?

*Beispiel*:

```cpp
if (firstAccount.equals(secondAccount)) {
    std::cout << "Same Balance" << std::endl;
}
else {
    std::cout << "Different Balances" << std::endl;
}
```

### Dritte Erweiterung

Wir ergänzen nun die Klasse `BankAccount` um den Aspekt *Zinsen*.
Da der Zinsatz variieren kann, fügen wir der Klasse eine Methode
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

auf. Der Parameter `days` gibt die Anzahl der Tage an, für die die Zinsen gutgeschrieben werden.
Eine Berechnung der Zinsen erfolgt nach der Formel

$$Zinsen = \frac{AnzahlTage}{365} * \frac{Zinssatz}{100} * Guthaben$$


### Erweiterung: Zwei Konto-Objekte vergleichen

Wir haben bereits eine Methode `equals` kennen gelernt,
um zwei Bankkonto-Objekte vergleichen zu können.

Dies wollen wir nun erweitern &ndash; und mit Hilfe der Syntax für Operatoren
auch lesbarer gestalten:

Realisieren Sie für die Klasse `BankAccount` die folgenden 6 Operatoren


`==`, `!=`, `<`, `<=`, `>` und `>=`.

Dabei soll gelten:

  * Zwei Konto-Objekte sind genau dann *gleich*, wenn sie denselben Kontostand aufweisen.

  * Ein Konto-Objekt ist *kleiner-oder-gleich* als ein anderes Konto-Objekt,
    wenn die korrespondieren Kontostände (`m_balance`) kleiner oder gleich sind.


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

## Quellcode der Lösungen:

[*BankAccount.h*](./BankAccount/BankAccount.h)<br />
[*BankAccount.cpp*](./BankAccount/BankAccount.cpp)<br />
[*BankAccount_Main.cpp*](./BankAccount/BankAccount_Main.cpp)<br />

---

[Zurück](./Exercises.md)

---
