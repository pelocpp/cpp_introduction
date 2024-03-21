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

## Quellcode der Lösungen:

[*String.h*](./String/String.h)<br />
[*String.cpp*](./String/String.cpp)<br />
[*String_Main.cpp*](./String/String_Main.cpp)<br />

---

[Zurück](./Exercises.md)

---

