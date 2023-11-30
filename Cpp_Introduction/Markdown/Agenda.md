# Agenda

[Zurück](../../Readme.md)

---

Es ist nicht einfach, bei dem enormen Umfang von sprachlichen Konstrukten,
Erweiterungen und Neuerungen von C++ den Überblick zu behalten.
Das von mir zusammengestellte Inhaltsverzeichnis unternimmt den Versuch,
die sprachlichen Konstrukte für einen Einstieg 
nach gewissen systematischen und methodischen Gesichtspunkten so zu gliedern und zusammenzufassen,
dass bei deren Betrachtung der &ldquo;rote Faden&rdquo; nicht verloren geht.


## [&ldquo;Hello World&rdquo;](HelloWorld.md) 
  * Umgang mit der Entwicklungsumgebung
  * Ein &ldquo;Hello World&rdquo; erstellen und ablaufen lassen


## [Erster Blick auf Klassen und Objekte](ClassesObjects.md) 
  * Dateiorganisation (Header-Dateien, Implementierungs-Dateien)
  * Begriffe *Klasse* und *Objekt*
  * Nomenklator
  * Punkt-Operator für den Zugriff


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
  * Überladen von Konstruktoren
  * Element-Initialisierungsliste (*Member Initializer List*)
  * Konvertierungskonstruktoren


## [Statische Datenelemente (`static`)](Static.md) 
  * Statische Datenelemente
  * Statische Elementfunktionen


## [Referenzen](References.md) 
  * Was ist eine Referenz?
  * Der Adreßoperator `&` bei Referenzen
  * Referenzen können nicht erneut zugewiesen werden
  * Null-Zeiger und Null-Referenzen
  * Zeiger und Referenzen im Vergleich
  * Parameter mit Referenzen übergeben


## [Technik der Übergabe von Parametern](ParameterPassingTechniques.md) 
  * Parameterübergabemechanismen: *Call-by-Value*, *Call-by-Address* und *Call-by-Reference*
  * Vergleich der Aufrufmethoden


## [Überladen von Operatoren](OperatorOverloading.md) 
  * Stelligkeit und Priorität
  * Assoziativität
  * Realisierung: Innerhalb und außerhalb der Klasse


## [Ein- und Ausgabe mit *Streams*](Streams.md) 
  * Ein Überblick über Streams
  * Pufferung
  * Streams und Puffer
  * Standard-E/A-Objekte
  * Eingabe mit `std::cin`
  * Ausgabe mit `std::cout`


## [Namensräume / Namespaces](Namespaces.md) 
  * Hintergrund für das Konzept der &ldquo;Namensräume&rdquo;
  * Schlüsselwörter `using` und `namespace`


## [Zeichenketten: Klasse `std::string`](Strings.md)
  * Einbinden der Klasse `std::string` aus der C++&ndash;Standardbibliothek
  * Die Klasse `std::string` exemplarisch betrachtet


## [Exceptions / Behandlung von Ausnahmen](Exceptions.md)
  * Was sind Exceptions?
  * Komponenten in der Behandlung von Ausnahmen
  * Schlüsselwörter `try` und `catch`


## [Dynamische Speicherverwaltung](DynamicMemoryManagement.md) 
  * Speicherbereiche eines C++&ndash;Programms
  * Lebensdauer von Variablen in einem C++&ndash;Programm
  * Stack und Heap (Stapel und Halde)
  * Operatoren `new` und `delete`


## [&ldquo;Rule of Three&rdquo;: Kopierkonstruktor, Wertzuweisungsoperator und Destruktor](RuleOfThree.md)
  * Objekte mit dynamischen Daten
  * Ein Destruktor zum automatisierten Freigeben von allokierten Speicher
  * Objekte kopieren und zuweisen
  * *Flat Copy* versus *Deep Copy*
  * Überladen von Kopierkonstruktor und Wertzuweisungsoperator
  * Die &ldquo;Rule of Three&rdquo;


## [Vererbung](Inheritance.md)
  * Entwicklung einer Hierarchie von Klassen
  * Konstruktoren von abgeleiteten Klassen und Basisklassen
  * Verwendung von `public`, `protected` und `private`


## [Vererbung - weiterführende Themen](MoreInheritance.md)
  * Überschreiben von Methoden
  * Schlüsselwörter `virtual`, `override` und `final`
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
  * Funktoren

---

[Zurück](../../Readme.md)

---
