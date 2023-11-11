# Aufgabe Klasse `BankAccount`

## Übersicht

Zielsetzung ist eine Klasse `BankAccount`, die ein Bankkonto repräsentiert.

Ein Bankkonto hat eine Kontonummer und einen Kontostand.
Es soll möglich sein, Geldbeträge einzahlen und abheben zu können.
Auskünfte über das Bankkonto lassen sich bzgl. Kontonummer und Kontostand einholen.
Die Informationen des Kontos lassen sich in der Konsole ausgeben.

### Beschreibung

Folgende C++&ndash;-Sprachmittel sollen zum Einsatz kommen:

  * Klasse und Objekt
  * Konstruktoren
  * Zugriffsklassen
  * *getter*- und *setter*-Methoden
  * Klassenvariablen

Betrachten Sie Details in der Arbeitsweise der Klasse `BankAccount` an folgendem Beispiel:

```cpp
BankAccount myAccount (12345);
myAccount.deposit(50);
myAccount.withdraw(25);
myAccount.print();
```

*Ausgabe*:


```cpp
Konto Nr. 12345: Guthaben 25 Euro.
```


*Hinweise*:

Bei der Kontoeröffnung ist die Kontonummer zu übergeben (dies werden wir verbessern).

*Hinweise*:

einzahlen: engl. &ldquo;*to deposit*&rdquo;<br />
abheben: engl. &ldquo;*to withdraw*&rdquo;<br />
Kontostand: engl. &ldquo;*balance*&rdquo;

### Erweiterung

Die Methode zum Abheben (`withdraw`) schlägt fehl, wenn auf dem Konto nicht genügend Geld vorhanden ist.
Wie könnte man dies in einer Verbesserung der `withdraw`-Methode zum Ausdruck bringen?

*Hinweise*:


```cpp
BankAccount myAccount (12345);
myAccount.deposit(25);
bool succeeded = myAccount.withdraw(50);
if (! succeeded) {
    std::cout << "Need more money :)" << std::endl;
}
```


### Erweiterung

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


### Erweiterung: Zwei Konto-Objekte vergleichen

Wir haben bereits eine Methode `equals` kennen gelernt,
um zwei Bankkonto-Objekte vergleichen zu können.

Dies wollen wir nun erweitern &ndash; und mit Hilfe der Syntax für Operatoren
auch lesbarer gestalten:

Realisieren Sie für die Klasse `BankAccount` 6 Operatoren


`==`, `!=`, `<`, `<=`, `>` und `>=`.

Dabei soll gelten:

  * Zwei Konto-Objekte sind *gleich*, wenn *alle* ihre Instanzvariablen gleich sind,
    die Kontonummer ausgenommen.

  * Ein Konto-Objekt sind *kleiner-oder-gleich* als ein anderes Konto-Objekt,
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

  * Die Klasse `Account` vergibt die Kontonummern selbst
  * Zwei Konto-Objekte vergleichen
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
