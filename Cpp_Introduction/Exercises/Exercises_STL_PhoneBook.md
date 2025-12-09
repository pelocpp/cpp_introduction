# Aufgabe zur STL: Klasse `Phonebook`

[Zurück](./Exercises.md)

---

## Übersicht

Folgende Aspekte werden betrachtet:
  * Entwicklung einer Anwendung mit der STL (*Standard Template Library*)
  * Anwendung sequentieller und assoziativer STL-Container (`std::vector`, `std::unordered_map` und `std::forward_list`)
  * Einsatz des Iteratoren-Konzepts
  * Anwendung elementarer STL Algorithmen (`std::find_if`, `std::transform`, `std::accumulate` und `std::for_each`)
  * Aufrufbare Objekte (*Callable Objects*)
  * Klasse `std::ostringstream`
  * Definition einer Schnittstelle (`IPhoneBook`)

---

Legen Sie Ihrer Realisierung folgende Schnittstelle zu Grunde:

```cpp
01: class IPhoneBook
02: {
03: public:
04:     virtual size_t size() = 0;
05:     virtual bool insert(const std::string& first, const std::string& last, size_t number) = 0;
06:     virtual bool update(const std::string& first, const std::string& last, size_t number) = 0;
07:     virtual bool search(const std::string& first, const std::string& last, size_t& number) = 0;
08:     virtual bool remove(const std::string& first, const std::string& last) = 0;
09:     virtual bool contains(const std::string& first, const std::string& last) = 0;
10:     virtual std::forward_list<std::string> getNames() = 0;
11:     virtual std::string toString() = 0;
12:     virtual void print() = 0;
13: };
```

Im Großen und Ganzen kann man sagen, dass die Funktionsweise dieser Methoden
selbsterklärend ist. Weitere Details zur Definition dieser Methoden entnehmen Sie bitte *Tabelle* 1:


| Methode        | Schnittstelle und Beschreibung |
|:-------------- |:-----------------------------------------|
| `size` | `size_t size();`<br/>Liefert die Anzahl der Einträge im Telefonbuch zurück. |
| `insert` | `bool insert(const std::string& first, const std::string& last, size_t number);`<br/>Fügt einen Eintrag, bestehend aus den Werten *Vorname*, *Nachname* und Telefonnummer in das Telefonbuch ein. Ist der Name (*Vorname* und *Nachname*) im Telefonbuch schon enthalten, liefert die Funktion `false` zurück, andernfalls `true`. |
| `update` | `bool update(const std::string& first, const std::string& last, size_t number);`<br/>Ändert einen Eintrag im Telefonbuch. Zu vorgegebenem Namen (*Vorname* und *Nachname*) wird eine neue Nummer im Telefonbuch eingetragen. Sind die Angaben des Namens falsch, liefert die Funktion `false` zurück, andernfalls `true`. |
| `search` | `bool search(const std::string& first, const std::string& last, size_t& number);`<br/>Sucht einen Eintrag im Telefonbuch. Zu vorgegebenem Namen (*Vorname* und *Nachname*) wird die Telefonnummer (im dritten Parameter `number`) zurückgegeben. Sind die Namensangaben falsch, liefert die Funktion `false` zurück, andernfalls `true`. |
| `remove` | `bool remove(const std::string& first, const std::string& last);`<br/>Entfernt einen Eintrag (*Vorname* und *Nachname*) im Telefonbuch. |
| `contains` | `bool contains(const std::string& first, const std::string& last);`<br/>Liefert die Information zurück, ob ein bestimmter Eintrag (*Vorname* und *Nachname*) im Telefonbuch vorhanden ist oder nicht. |
| `getNames` | `std::forward_list<std::string> getNames();`<br/>Es wird ein STL-Container (`std::forward_list<std::string>`) konstruiert, der alle Namen des Telefonbuchs in einer Art Zusammenfassung darstellt. |
| `toString` | `std::string toString();`<br/>Kreiert eine Zeichenkette (`std::string`), die den gesamten Inhalt des Telefonbuchs in einer ansprechenden lesbaren Darstellung enthält. |
| `print` | `void print();`<br/>Gibt den Inhalt des Telefonbuchs in der Konsole aus. |

*Tabelle* 1: Beschreibung der öffentlichen Schnittstelle einer Telefonbuchrealisierung.

---

## Eine erste Realisierung: STL-Container `std::vector`

Die Klasse `std::vector` ist der STL-Allzweckcontainer für eine Ansammlung von Daten,
deren Umfang sich zur Laufzeit eines Programms ändern kann.

Wie müssen Sie ein konkretes `std::vector`-Objekt definieren,
wenn wir pro Eintrag die drei Informationen *Vorname* (`std::string`), *Nachname* (`std::string`) und *Telefonnummer* (`std::size_t`)
im Telefonbuch ablegen wollen?

<img src="./STL_PhoneBook/Resources/cpp_vector_phonebook.svg" width="400">

*Abbildung* 1. Struktureller Aufbau eines `std::vector`-Objekts mit mehreren Telefonbucheinträgen.

Definieren Sie eine geeignete Klasse `Entry`, um dann ein `std::vector<Entry>`-Objekt
anlegen zu können. Dieses Objekt soll Membervariable eine Klasse `PhoneBook` sein.

Bilden Sie dann die geforderten Methoden der öffentlichen Schnittstelle einer `PhoneBook`-Klasse
aus *Tabelle* 1 geeignet auf STL-Algorithmen ab.

Denkbar wäre zum Beispiel:

  * Methode `search` &Rightarrow; `std::find_if`
  * Methode `print` &Rightarrow; `std::for_each`
  * Methode `getNames` &Rightarrow; `std::transform`
  * Methode `toString` &Rightarrow; `std::accumulate`

---

## Eine verbesserte Realisierung: STL-Container `std::unordered_map`

In einer eher einfachen Realisierung werden die Einträge des Telefonbuchs in einem `std::vector`-Objekt abgelegt.
Überlegen Sie, ob diese Container-Klasse ideal für den vorliegenden Anwendungsfall ist.
Nehmen Sie eine zweite Realisierung vor, die auf einem `std::unordered_map`-Container fußt.


<img src="./STL_PhoneBook/Resources/cpp_hash_table_phonebook.svg" width="600">

*Abbildung* 2. Struktureller Aufbau einer Hashtabelle (hier: Hash-Kollision durch separate Verkettung gelöst).

---

## Quellcode der Lösungen:

Im Quellcode zu den Lösungen finden Sie zwei Realisierungen vor: Eine, die als Datenspeicher 
ein `std::vector`-Objekt verwendet sowie eine zweite Realisierung mit einem `std::unordered_map`-Objekt:

[*IPhoneBook.h*](./STL_PhoneBook/IPhoneBook.h)<br />
[*PhoneBookVector.h*](./STL_PhoneBook/PhoneBookVector.h)<br />
[*PhoneBookMap.h*](./STL_PhoneBook/PhoneBookMap.h)<br />

[*PhoneBookVector.cpp*](./STL_PhoneBook/PhoneBookVector.cpp)<br />
[*PhoneBookMap.cpp*](./STL_PhoneBook/PhoneBookMap.cpp)<br />
[*PhoneBookMap.cpp*](./STL_PhoneBook/PhoneBookMap.cpp)<br />
[*PhoneBook_Main.cpp*](./STL_PhoneBook/PhoneBook_Main.cpp)<br />

---

[Zurück](./Exercises.md)

---
