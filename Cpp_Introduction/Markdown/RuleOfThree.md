# &ldquo;Rule of Three&rdquo;: Kopierkonstruktor, Wertzuweisungsoperator und Destruktor


[Zurück](Agenda.md)

---

## Erläuterungen

Wann immer in C++ ein Objekt kopiert wird, ist daran entweder ein Kopierkonstruktor
oder ein Zuweisungsoperator beteiligt.

Der Zuweisungsoperator wird ausgeführt, wenn wir eine Wertzuweisung zweier Objekte tätigen:

```cpp
01: Time t1;
02: Time t2;
03: // ...     
04: t1 = t2;
```

Der Kopierkonstruktor ist ein Konstruktor,
der als Argument ein anderes Objekt seiner Klasse übergeben bekommt.

Er kommt &ndash; unter anderem &ndash; zum Zuge,
wenn er direkt zur Erzeugung eines Objekts aufgerufen wird:

```cpp
01: Time t1;
02: // ...
03: Time t2 (t1);
```

Das interessante an diesen beiden Anweisungen (Wertzuweisung und Objekterzeugung) ist,
dass wir hierzu keinerlei Untertützung leisten müssen.

C++ stellt hierzu Standardversionen eines Kopierkonstruktors und eines Zuweisungsoperators zur Verfügung,
die bei Bedarf aufgerufen werden.

Diese kopieren die beteiligten Objekte, indem sie einfach die Inhalte der einzelnen Instanzvariablen
1:1 von Objekt *A* in das Objekt *B* kopieren.

Man bezeichnet diese Vorgehensweise auch als *flaches* Kopieren (engl. *flat copy* oder auch *shallow copy*).

<img src="cpp_standard_flat_copy.svg" width="400">

*Abbildung* 1: Erstellung einer flachen Kopie.


Die Standardversionen für das Kopieren und Zuweisen sind völlig ausreichend,
wenn in den Instanzvariablen der beteiligten Objekte **keine** Zeigervariablen vorhanden sind.

Worin besteht das Problem, wenn Objekte Zeiger als Instanzvariablen habe`?



Betrachten wir zu diesem Beispiel eine Klasse `BigData` mit folgender Definition:

```cpp
01: class BigData
02: {
03: private:
04:     // private member data
05:     int m_size;   // current number of elements
06:     int* m_data;  // dynamically allocated array of elements
07: 
08: public:
09:     // c'tors
10:     BigData();
11:     BigData(int size);
12: };
```

Objekte von `BigData` sollen &ndash; dynamisch &ndash; einen Datenbereich verwalten.
Die Länge dieses Datenbereichs ist bei der Objekterzeugung dem Konstruktor im Parameter `size` zu übergeben
(siehe Zeile 11 des letzten Code-Fragments).

Betrachten Sie nun *Abbildung* 2 genau. Sie visualisiert eine Zuweisung zweier `BigData`-Objekte.
Worin besteht das Problem?

<img src="cpp_flat_copy.svg" width="400">

*Abbildung* 2: Fehlerhafte Erstellung eines Objekts mit dynamisch allokierten Daten.


Eine korrekte Realisierung derartiger Klassen erreichen Sie nur,
indem Sie sowohl für den Kopierkonstruktor als auch den Zuweisungsoperator
eine Implementierung (Überladung) bereitstellen, die so implementiert wird,
dass für jeden Zeiger ein eigener Speicherbereich mít `new` allokiert wird und anschließend der Inhalt,
auf den der Zeiger verweist, umkopiert wird.

Man bezeichnet dies als das so geannte *tiefe* Kopieren (engl. *deep copy*),
siehe dazu auch *Abbildung* 3:

<img src="cpp_deep_copy.svg" width="400">

*Abbildung* 3: Korrekte Erstellung eines Objekts mit dynamisch allokierten Daten.


Die notwendigen Realisierung entnehmen Sie bitte dem nun folgenden Quellcode des nächsten Abschnitts.


## Beispiele

Datei *BigData.h*:

```cpp
```

Datei *BigData.cpp*:

```cpp
```


---

#### Datei *Main.cpp* - Testrahmen:


```cpp
```

*Ausgabe*:


```
```

---

## Quellcode des Beispiels:

[Time.h](..\RuleOfThree\BigData.h)<br />
[Time.cpp](..\RuleOfThree\BigData.cpp)<br />
[Main.cpp](..\RuleOfThree\Main.cpp)

---


## Übungen

TBD: Rectangle


---


[Zurück](Agenda.md)

---
