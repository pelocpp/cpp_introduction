# Aufgabe zur STL: Klasse `Phonebook`

[Zur�ck](./Exercises.md)

---

## �bersicht

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

In der vorliegenden Realisierung werden die Eintr�ge des Telefonbuchs in einem `std::vector` abgelegt.
�berlegen Sie, ob diese Container-Klasse ideal f�r den vorliegenden Anwendungsfall ist.
Nehmen Sie eine zweite Realisierung vor, die auf einem `std::unordered_map`-Container fu�t.


<img src="./STL_PhoneBook/Resources/cpp_hash_table.svg" width="600">

*Abbildung* 1. Struktureller Aufbau einer Hashtabelle (hier: Hash-Kollision durch separate Verkettung gel�st).


---

## Quellcode der L�sungen:

[*String.h*](./String/String.h)<br />
[*String.cpp*](./String/String.cpp)<br />
[*String_Main.cpp*](./String/String_Main.cpp)<br />

---

[Zur�ck](./Exercises.md)

---

