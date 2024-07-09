# Aufgaben


[Zurück](../../Readme.md)

---

In diesem Repository sind zahlreiche kleinere C++&ndash;Programme abgelegt,
um diverse Features von C++ zu demonstrieren.

Im Großen und Ganzen wurde dabei versucht,
die Beispiele auf dem Niveau für C++-Einsteiger
(mit Kenntnissen anderer Programmiersprachen wie zum Beispiel C oder Java) zu halten.

---

## Inhaltsverzeichnis:


<!--


#### [Low-Level Programmierung in C/C++](Examples/LowLevelProgramming/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Operatoren zur Bitmanipulation: `&`, `|`, `^` und `~` sowie die beiden Shift-Operatoren `<<` und `>>`
  * Kleinere Beispiele auf Basis der Bitmanipulationsoperatoren.


---

-->


#### [Klasse *Rectangle*](./Exercises_Rectangle.md)

Folgende Aspekte werden betrachtet:
  * Klasse und Objekt
  * Konstruktoren
  * Zugriffsrechte (`private`, `public`)
  * *getter*/*setter*-Methoden
  * Realisierung einfacher Methoden
  * Objekte als Rückgabewert von Methoden


---

#### [Klasse *BankAccount*](./Exercises_BankAccount.md)

Folgende Aspekte werden betrachtet:
  * Klasse und Objekt
  * Konstruktoren
  * Zugriffsrechte (`private`, `public`)
  * *getter*/*setter*-Methoden
  * Realisierung einfacher Methoden
  * Klassenvariablen

---

#### [Klasse *Time*](./Exercises_Time.md)

Folgende Aspekte werden betrachtet:
  * Prinzipielle Realisierung einer einfachen Klasse *ohne* dynamische Daten im Instanzvariablenbereich
  * Konstruktoren
  * Zugriffsrechte (`private`, `public`)
  * Überladen von Operatoren
  * `friend`-Mechanismus
  * *getter*/*setter*-Methoden
  * Objekte als Rückgabewert von Methoden

---

#### [Klasse *Fraction*](Examples/Fraction/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Prinzipielle Realisierung einer einfachen Klasse *ohne* dynamische Daten im Instanzvariablenbereich
  * Konstruktoren
  * Zugriffsrechte (`private`, `public`)
  * Überladen von Operatoren
  * `friend`-Mechanismus
  * *getter*/*setter*-Methoden
  * Objekte als Rückgabewert von Methoden
  * Klassenmethoden

---

#### [Betrachtungen zur Parameterübergabe](./Exercises_References_Pointers.md)

Folgende Aspekte werden betrachtet:
  * Parameterübergabe mit Kopien
  * Parameterübergabe mit Zeigern
  * Parameterübergabe mit Referenzen

---

#### [Zeichenketten &ndash; Klasse `std::string`](./Exercises_Strings.md)

Folgende Aspekte werden betrachtet:
  * Umgang mit der Klasse `std::string`
  * Methoden `substr` und `append`
  * *getter*-Methode `length`
  * Index-Operator `operator []`, Konkatenationsoperator `+`
  * Weitere Bibliotheksfunktionen `std::isdigit` und `std::stoi`

---

#### [Aufgabe zu einem Geldbeutel: Klasse `Wallet`](./Exercises_Wallet.md)

Folgende Aspekte werden betrachtet:
  * Klasse und Objekt
  * Konstruktoren
  * Zugriffsrechte (`private`, `public`)
  * *getter*-Methoden
  * Realisierung einfacher Methoden
  * Klasse `std::string`
  * Überladen von Operatoren
  * Exception-Handling mit `try`, `catch` und `throw`

---

#### [Dynamische Daten &ndash; Klasse `DynamicIntArray`](./Exercises_DynamicIntArray.md)

Folgende Aspekte werden betrachtet:
  * Umgang mit den Operatoren `new` und `delete`
  * Realisierung einer Klasse mit dynamischen Daten
  * Handhabung der Regel *Rule-of-Three*

---

#### [Dynamische Daten &ndash; Realisierung einer Klasse `String`](./Exercises_String.md)

Folgende Aspekte werden betrachtet:
  * Prinzipielle Realisierung einer einfachen Klasse *mit* dynamischen Daten im Instanzvariablenbereich
  * Konstruktoren und Destruktor (*Big&ndash;Three*)
  * Zugriffsrechte (`private`, `public`)
  * Überladen von Operatoren
  * `friend`-Mechanismus

---

#### [Vererbung am Beispiel von Bankkonten](./Exercises_MoreBankAccounts.md)

Folgende Aspekte werden betrachtet:
  * Überschreiben von Methoden
  * Schlüsselwörter `virtual`, `override` und `final`
  * Schnittstellenkonzept (*Interface*)
  * Abstrakte Basisklasse
   
---

#### [Klassentemplate zur Klasse `DynamicArray`](./Exercises_DynamicArrayTemplate.md)

Folgende Aspekte werden betrachtet:
  * Templates

---

#### [STL - Zwei einführende Aufgaben](./Exercises_STL.md)

Folgende Aspekte werden betrachtet:
  * Zwei einfache, einführende Beispiel zur STL (*Standard Template Library*)
  * Berechnung der Teuflischen Zahlenfolge und von Fibonacci Zahlen
  * Grundlegende STL-Konzepte: STL-Container, -Iteratoren, -Algorithmen und Funktionsobjekte
  * `std::for_each`, `std::generate`, `std::vector`

---

#### [STL - Ziehung der Lottozahlen &ndash; Klasse `Lottery` (inklusive Iteratoren-Konzept)](./Exercises_STL_Lotto.md)

Folgende Aspekte werden betrachtet:
  * Entwicklung einer Anwendung &ndash; Klasse `Lottery` &ndash; mit der STL (*Standard Template Library*)
  * Einsatz eines sequentiellen STL-Containers (hier: Klasse `std::vector`)
  * Realisierung des STL Iteratoren-Konzepts für Klasse  `Lottery`
  * Anwendung elementarer STL Algorithmen (`std::find_if` und `std::for_each`)

---

#### [STL - Klasse `Phonebook`](./Exercises_STL_PhoneBook.md)

Folgende Aspekte werden betrachtet:
  * Entwicklung einer Anwendung mit der STL (*Standard Template Library*)
  * Anwendung sequentieller und assoziativer STL-Container (`std::vector`, `std::unordered_map` und `std::forward_list`)
  * Einsatz des Iteratoren-Konzepts
  * Anwendung elementarer STL Algorithmen (`std::find_if`, `std::transform`, `std::accumulate`, `std::sort` und `std::for_each`)
  * Einsatz von aufrufbaren Objekten (*Callable Objects*)
  * Klasse `std::ostringstream`
  * Definition einer Schnittstelle (`IPhoneBook`)


<!--

---

#### [Klasse *IntegerSet*](Examples/IntegerSet/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Realisierung einer Klasse mit dynamischen Daten im Instanzvariablenbereich (Variante 1)
  * Realisierung einer Klasse mit einem STL-Container (`std::vector`) im Instanzvariablenbereich (Variante 2)
  * Korrekte Verwaltung dynamischer Daten einer Klasse ("*Big-Three*")
  * Verbesserung des Laufverzeitverhaltens: Implementierung der Move-Semantik ("*Big-Five*" &ndash; Variante 3 und 4)
  * Betrachtung des *Swap-Idioms* als eine Möglichkeit zur Umsetzung der Move-Semantik


---

#### [Vererbung am Beispiel von Rechtecken](Examples/Rectangles/Resources/Readme.md)

Folgende Aspekte werden zum Thema &bdquo;Vererbung&rdquo; betrachtet:
  * Entwicklung einer Hierarchie von Klassen
  * Konstruktoren von abgeleiteten Klassen und Basisklassen
  * Verwendung von `public`, `protected` und `private`
  * Verdecken von Methoden
  * Überschreiben von Methoden
  * Schlüsselwörter `virtual`, `override` und `final`
  * Polymorphismus
  * Betrachtung einer Schnittstelle (*Interface*)
  * Kontrakt mit mehreren Schnittstellen
  * Betrachtung einer abstrakten Basisklasse 
  * Betrachtung von konkreten Klassen
  * Unterschied Schnittstelle versus abstrakte Basisklasse


---

-->


---

[Zurück](../../Readme.md)

---
