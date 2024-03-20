# Agenda

[Zur�ck](../../Readme.md)

---

<p align="center">
<img src="./Embedded_Cpp.jpg" width="700" />
</p>

---

Es ist nicht einfach, bei dem enormen Umfang von sprachlichen Konstrukten,
Erweiterungen und Neuerungen von C++ den �berblick zu behalten.
Das von mir zusammengestellte Inhaltsverzeichnis unternimmt den Versuch,
die sprachlichen Konstrukte f�r einen Einstieg 
nach gewissen systematischen und methodischen Gesichtspunkten so zu gliedern und zusammenzufassen,
dass bei deren Betrachtung der &ldquo;rote Faden&rdquo; nicht verloren geht.

---

## [&ldquo;Hello World&rdquo;](HelloWorld.md) 
  * Umgang mit der Entwicklungsumgebung
  * Ein &ldquo;Hello World&rdquo; erstellen und ablaufen lassen


## [Erster Blick auf Klassen und Objekte](ClassesObjects.md) 
  * Dateiorganisation (Header-Dateien, Implementierungs-Dateien)
  * Begriffe *Klasse* und *Objekt*
  * Nomenklator
  * Punkt-Operator f�r den Zugriff


## [Vergleich zwischen prozeduraler und objektorientierter Programmierung](ProceduralVsOOProgramming.md) 
  * Was bedeutet &ldquo;prozedurale&rdquo; Programmierung
  * Was bedeutet &ldquo;objektorientierte&rdquo; Programmierung
  * Vorteile der objektorientierten Programmierung


## [Vertiefungen zu Klassen und Objekten](ClassesObjectsImproved.md) 
  * Zugriffsklassen (`private`, `public`)
  * *setter*-/*getter*-Methoden
  * Der `this`-Operator
  

## [Initialisierung von Objekten: Konstruktoren](Constructors.md) 
  * Was sind Konstruktoren?
  * �berladen von Konstruktoren
  * Element-Initialisierungsliste (*Member Initializer List*)
  * Konvertierungskonstruktoren


## [Statische Datenelemente (`static`)](Static.md) 
  * Statische Datenelemente
  * Statische Elementfunktionen


## [Referenzen](References.md) 
  * Was ist eine Referenz?
  * Der Adre�operator `&` bei Referenzen
  * Referenzen k�nnen nicht erneut zugewiesen werden
  * Null-Zeiger und Null-Referenzen
  * Zeiger und Referenzen im Vergleich
  * Parameter mit Referenzen �bergeben


## [Technik der �bergabe von Parametern](ParameterPassingTechniques.md) 
  * Parameter�bergabemechanismen: *Call-by-Value*, *Call-by-Address* und *Call-by-Reference*
  * Vergleich der Aufrufmethoden


## [�berladen von Operatoren](OperatorOverloading.md) 
  * Stelligkeit und Priorit�t
  * Assoziativit�t
  * Realisierung: Innerhalb und au�erhalb der Klasse


## [Ein- und Ausgabe mit *Streams*](Streams.md) 
  * Ein �berblick �ber Streams
  * Pufferung
  * Streams und Puffer
  * Standard-E/A-Objekte
  * Eingabe mit `std::cin`
  * Ausgabe mit `std::cout`


## [Namensr�ume / Namespaces](Namespaces.md) 
  * Hintergrund f�r das Konzept der &ldquo;Namensr�ume&rdquo;
  * Schl�sselw�rter `using` und `namespace`


## [Zeichenketten: Klasse `std::string`](Strings.md)
  * Einbinden der Klasse `std::string` aus der C++&ndash;Standardbibliothek
  * Die Klasse `std::string` exemplarisch betrachtet


## [Exceptions / Behandlung von Ausnahmen](Exceptions.md)
  * Was sind Exceptions?
  * Komponenten in der Behandlung von Ausnahmen
  * Schl�sselw�rter `try` und `catch`


## [Dynamische Speicherverwaltung](DynamicMemoryManagement.md) 
  * Speicherbereiche eines C++&ndash;Programms
  * Lebensdauer von Variablen in einem C++&ndash;Programm
  * Stack und Heap (Stapel und Halde)
  * Operatoren `new` und `delete`


## [&ldquo;Rule of Three&rdquo;: Kopierkonstruktor, Wertzuweisungsoperator und Destruktor](RuleOfThree.md)
  * Objekte mit dynamischen Daten
  * Ein Destruktor zum automatisierten Freigeben von allokiertem Speicher
  * Objekte kopieren und zuweisen
  * *Flat Copy* versus *Deep Copy*
  * �berladen von Kopierkonstruktor und Wertzuweisungsoperator
  * Die &ldquo;Rule of Three&rdquo;


## [Vererbung](Inheritance.md)
  * Entwicklung einer Hierarchie von Klassen
  * Konstruktoren von abgeleiteten Klassen und Basisklassen
  * Verwendung von `public`, `protected` und `private`


## [Vererbung - weiterf�hrende Themen](MoreInheritance.md)
  * �berschreiben von Methoden
  * Schl�sselw�rter `virtual`, `override` und `final`
  * Polymorphismus
  * Schnittstellenkonzept (Interface)
  * Kontrakt mit mehreren Schnittstellen
  * Abstrakte Basisklasse
  * Unterschied Schnittstelle versus abstrakte Basisklasse


## [Templates / Schablonen](Templates.md)
  * Was sind Templates?
  * Ein universeller Taschenrechner


## [STL (Standard Template Library)](STL.md)
  * Container
  * Iteratoren
  * Algorithmen
  * Aufrufbare Objekte

---

[Zur�ck](../../Readme.md)

---
