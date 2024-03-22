# Aufgabe zur STL: Klasse `Phonebook`

[Zurück](./Exercises.md)

---

## Übersicht

Folgende Aspekte werden betrachtet:
  * Entwicklung einer Anwendung mit der STL (*Standard Template Library*)
  * Anwendung elementarer STL-Container (`std::vector`)
  * Anwendung elementarer STL Algorithmen (`std::find_if`, `std::copy_if`, `std::remove_if`, `std::sort`, `std::accumulate`, `std::for_each`)
  * Das Iteratoren-Konzept (Methode `import`)
  * Einsatz von Funktionsobjekten (*Callable Objects*)
  * Klasse `std::ostringstream`
  * Sortieren (`std::sort`)
  * Definition einer Schnittstelle (`IPhoneBook`)


## Weiterarbeit

In der vorliegenden Realisierung werden die Einträge des Telefonbuchs in einem `std::vector` abgelegt.
Überlegen Sie, ob diese Container-Klasse ideal für den vorliegenden Anwendungsfall ist.
Nehmen Sie eine zweite Realisierung vor, die auf einem `std::unordered_map`-Container fußt.


<img src="./STL_PhoneBook/Resources/cpp_hash_table.svg" width="600">

*Abbildung* 1. Struktureller Aufbau einer Hashtabelle (hier: Hash-Kollision durch separate Verkettung gelöst).


---

Legen Sie Ihrer Realisierung folgende Schnittstelle zu Grunde:

```cpp
01: class IPhoneBook
02: {
03: public:
04:     virtual bool insert(const std::string& first, const std::string& last, long number) = 0;
05:     virtual bool update(const std::string& first, const std::string& last, long number) = 0;
06:     virtual bool search(const std::string& first, const std::string& last, long& number) = 0;
07:     virtual bool contains(const std::string& first, const std::string& last) = 0;
08:     virtual bool remove(const std::string& first, const std::string& last) = 0;
09:     virtual std::forward_list<std::string> getNames() = 0;
10:     virtual void sort() = 0;
11:     virtual void print() = 0;
12: };
```


---


## Quellcode der Lösungen:

[*IPhoneBook.h*](./STL_PhoneBook/IPhoneBook.h)<br />
[*PhoneBook.h*](./STL_PhoneBook/PhoneBook.h)<br /><br />



[*String_Main.cpp*](./STL_PhoneBook/String_Main.cpp)<br />

---

[Zurück](./Exercises.md)

---

