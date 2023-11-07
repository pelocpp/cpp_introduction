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

### Einbinden der Klasse `std::string` aus der C++&ndash;Standardbibliothek

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
03:     // standard class 'std::string'
04: 
05:     // constructor
06:     std::string s("12345");
07: 
08:     // operator <<
09:     std::cout << s << std::endl;
10: 
11:     // getter: size
12:     size_t len = s.size();
13:     std::cout << "Length: " << len << std::endl;
14: 
15:     // getter: empty
16:     bool b = s.empty();
17:     std::cout << "Empty: " << std::boolalpha << b << std::endl;
18: 
19:     // method: insert
20:     // insert "ABC" at position 2
21:     s.insert(2, "ABC");
22:     std::cout << "s.insert(2, \"ABC\") ==> " << s << std::endl;
23: 
24:     // method: append
25:     // append "!!!"
26:     s.append("!!!");
27:     std::cout << "s.append(\"!!!\")    ==> " << s << std::endl;
28: 
29:     // comparison operators
30:     std::string s1("12345");
31:     std::string s2("12345");
32:     std::string s3("123456");
33: 
34:     bool b1 = (s1 == s2);
35:     bool b2 = (s1 == s3);
36: 
37:     std::cout << "s1 == s2           ==> " << std::boolalpha << b1 << std::endl;
38:     std::cout << "s1 == s3           ==> " << std::boolalpha << b2 << std::endl;
39: 
40:     // method: substr
41:     // retrieve a sub string
42:     // first param = position of the first character to include
43:     // second param = length of the substring
44:     std::string sub = s1.substr(1, 3);
45:     std::cout << "s1.substr(1, 3)    ==> " << std::boolalpha << sub << std::endl;
46:         
47:     // index operator []
48:     s[8] = '?';
49:     std::cout << "s[8] = '?'         ==> " << s << std::endl;
50: 
51:     // method: append
52:     // append another std::string object
53:     std::string result;
54:     result = s1.append(s2);
55:     std::cout << "s1.append(s2)      ==> " << result << std::endl;
56: 
57:     // operator +
58:     // concatenating two strings (same as using method append)
59:     result = s1 + s3;
60:     std::cout << "s1 + s3            ==> " << result << std::endl;
61: 
62:     // just kidding you:
63:     // using an operator with 'method call' syntax
64:     result = operator+ (s1, s2);
65:     std::cout << "s1 + s2            ==> " << result << std::endl;
66: }
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
s1.substr(1, 3)    ==> 234
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
