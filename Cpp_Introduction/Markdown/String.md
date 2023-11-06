# Zeichenketten: Klasse `std::string`


[Zurück](Agenda.md)

---

## Erläuterungen

Zeichenketten werden in der Programmiersprache C auf den Datentyp `const char*` abgebildet.
Es stehen in C auch Funktionen für Verkettung, Vergleich, Kopie usw. zur Verfügung,
diese sind in ihrem Gebrauch jedoch nicht sehr einfach bzw. intuitiv.

Einem C++&ndash;Entwickler steht aus der C++ Standardbibliothek
(*Standard Template Library*, *STL*) die Klasse `std::string` zur Verfügung.
Sie ist in der Hantierung erheblich einfacher als das Arbeiten mit Variablen des Typs `const char*`.

### Einbinden von Klassen aus der C++&ndash;Standardbibliothek

Zur Benutzung der Klasse `std::string` muss ein entsprechendes STL-Headerfile eingebunden werden:

```cpp
#include <string>
```

Durch diese Anweisung wird die Klasse `string` aus dem Namensraum `std` bekannt gemacht,
so daß für die korrekte Verwendung `std::string` verwendet werden muss.


## Beispiele

Das folgende Beispiel versucht, einige der bisher betrachteten objektorientierten Techniken
an einer C++ Standardklasse zu demonstrieren bzw. zu beobachten:

  * Konstruktoren
  * *getter*/*setter*
  * Methode
  * Operatoren
  * Ausgabe (Operator `<<`)


### Die Klasse `std::string` exemplarisch betrachtet


```cpp
01: void testString()
02: {
03:     // constructor
04:     std::string s("12345");
05: 
06:     // operator <<
07:     std::cout << s << std::endl;
08: 
09:     // getter: size
10:     size_t len = s.size();
11:     std::cout << "Length: " << len << std::endl;
12: 
13:     // getter: empty
14:     bool b = s.empty();
15:     std::cout << "Empty: " << std::boolalpha << b << std::endl;
16: 
17:     // method: insert
18:     // insert "ABC" at position 2
19:     s.insert(2, "ABC");
20:     std::cout << "s.insert(2, \"ABC\") ==> " << s << std::endl;
21: 
22:     // method: append
23:     // append "!!!"
24:     s.append("!!!");
25:     std::cout << "s.append(\"!!!\")    ==> " << s << std::endl;
26: 
27:     // comparison operators
28:     std::string s1("12345");
29:     std::string s2("12345");
30:     std::string s3("123456");
31: 
32:     bool b1 = (s1 == s2);
33:     bool b2 = (s1 == s3);
34: 
35:     std::cout << "s1 == s2           ==> " << std::boolalpha << b1 << std::endl;
36:     std::cout << "s1 == s3           ==> " << std::boolalpha << b2 << std::endl;
37: 
38:     // index operator []
39:     s[8] = '?';
40:     std::cout << "s[8] = '?'         ==> " << s << std::endl;
41: 
42:     // method: append
43:     // append another std::string object
44:     std::string result;
45:     result = s1.append(s2);
46:     std::cout << "s1.append(s2)      ==> " << result << std::endl;
47: 
48:     // operator +
49:     // concatenating two strings (same as using method append)
50:     result = s1 + s3;
51:     std::cout << "s1 + s3            ==> " << result << std::endl;
52: 
53:     // just kidding you:
54:     // using an operator with 'method call' syntax
55:     result = operator+ (s1, s2);
56:     std::cout << "s1 + s2            ==> " << result << std::endl;
57: }
```

*Ausgabe*:

```
12345
Length: 5
Empty: false
s.insert(2, "ABC") ==> 12ABC345
s.append("!!!")    ==> 12ABC345!!!
s1 == s2           ==> true
s1 == s3           ==> false
s[8] = '?'         ==> 12ABC345?!!
s1.append(s2)      ==> 1234512345
s1 + s3            ==> 1234512345123456
s1 + s2            ==> 123451234512345
```


*Bemerkung*:
Welche Unterschiede erkennen Sie in der Schreibweise des Beispiel im Gegensatz
zu den von mir verwendeten Beispielen?

*Antwort*:
Die *getter*-Methoden halten sich nicht an die Konvention, den Methodennamen mit `get` einzuleiten.

An Stelle der erwarteten Methodenbezeichner

  * `getLength` bzw. `getSize` 
  * `isEmpty`
  * `getCapacity`

haben sich die Bibliotheksentwickler für die Bezeichner


  * `length` bzw. `size` 
  * `empty`
  * `capacity`


entschieden.


---

## Quellcode des Beispiels:

[*Main.cpp*](../String/Main.cpp)

---


## Übungen

TBD: TBD


---


[Zurück](Agenda.md)

---
