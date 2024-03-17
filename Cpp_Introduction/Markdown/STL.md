# Standard Template Library &ndash; STL


[Zurück](Agenda.md)

---

## Erläuterungen

Wir betrachten die grundlegenden Konzepte

  * Container
  * Iteratoren
  * Algorithmen
  * Aufrufbare Objekte
   
an Hand einer Reihe von Beispielen:

---

### Container `std::vector<int>`

[*Main.cpp*](../STL/Main.cpp)

```cpp
01: void testSTL01()
02: {
03:     // array of arbitraty length of int-values
04:     std::vector<int> vec;
05: 
06:     vec.push_back(1);
07:     vec.push_back(2);
08:     vec.push_back(3);
09: 
10:     // works only for STL container (random access operator [])
11:     for (int i = 0; i < vec.size(); ++i) {
12: 
13:         std::cout << i << ": " << vec[i] << std::endl;
14:     }
15: }
```

---

### Das Iteratoren-Konzept

[*Main.cpp*](../STL/Main.cpp)

```cpp
01: void testSTL02()
02: {
03:     // array of arbitraty length of int-values
04:     std::vector<int> vec;
05: 
06:     vec.push_back(1);
07:     vec.push_back(2);
08:     vec.push_back(3);
09: 
10:     // defining STL interators
11:     std::vector<int>::iterator first = vec.begin();
12:     std::vector<int>::iterator ende = vec.end();
13: 
14:     int value = *first;
15:     std::cout << value << std::endl;
16: 
17:     ++first;
18:     value = *first;
19:     std::cout << value << std::endl;
20: 
21:     ++first;
22:     value = *first;
23:     std::cout << value << std::endl;
24: 
25:     ++first;
26:     // value = *first;   // does this line work?
27: }
```

---

### Einen STL-Container mit Hilfe von Iteratoren traversieren

[*Main.cpp*](../STL/Main.cpp)

```cpp
01: void testSTL03()
02: {
03:     // array of arbitraty length of int-values
04:     std::vector<int> vec;
05: 
06:     vec.push_back(1);
07:     vec.push_back(2);
08:     vec.push_back(3);
09: 
10:     // defining STL interators
11:     std::vector<int>::iterator first = vec.begin();
12:     std::vector<int>::iterator ende = vec.end();
13: 
14:     // traversal of a STL container,
15:     // being conformant with the STL iterator concept
16:     for (; first != ende; ++first) {
17: 
18:         int value = *first;
19:         std::cout << value << std::endl;
20:     }
21: }
```

---

### STL-Algorithmus `std::for_each`

[*Main.cpp*](../STL/Main.cpp)

```cpp
01: void print(int value)
02: {
03:     std::cout << value << std::endl;
04: }
05: 
06: void testSTL04()
07: {
08:     // array of arbitraty length of int-values
09:     std::vector<int> vec;
10: 
11:     vec.push_back(1);
12:     vec.push_back(2);
13:     vec.push_back(3);
14: 
15:     std::for_each(
16:         vec.begin(),
17:         vec.end(),
18:         print
19:     );
20: }
```

---

### Die Eigenschaften `size` und `capacity` der Klasse `std::vector<int>`

[*Main.cpp*](../STL/Main.cpp)

```cpp
01: void testSTL05()
02: {
03:     std::vector<int> vec;
04: 
05:     for (int i = 0; i < 100; ++i) {
06: 
07:         vec.push_back(2 * i);
08: 
09:         std::cout
10:             << i << ": " << vec[i] << ", size: " << vec.size()
11:             << ", capacity: " << vec.capacity() << std::endl;
12:     }
13: }
```

---

### Initialisieren eines Container: `for`-Wiederholungsschleife oder `std::fill`

[*Main.cpp*](../STL/Main.cpp)

```cpp
01: void testSTL06()
02: {
03:     std::vector<int> vec;
04: 
05:     vec.resize(100);
06: 
07:     // initialize all elements with the value 1
08:     for (int i = 0; i < 100; ++i) {
09:         vec[i] = 1;
10:     }
11: 
12:     // or
13: 
14:     std::fill(vec.begin(), vec.end(), 1);
15: }
```

---

### Initialisieren eines Container mit variablen Werten: `std::generate`

[*Main.cpp*](../STL/Main.cpp)

```cpp
01: int i = -1;
02: 
03: int init() {
04:     ++i;
05:     return 2 * i + 1;
06: }
07: 
08: void testSTL07()
09: {
10:     std::vector<int> vec;
11: 
12:     vec.resize(100);
13: 
14:     // initialize with computed values
15:     for (int i = 0; i < 100; ++i) {
16:         vec[i] = 2 * i + 1;
17:     }
18: 
19:     // or 
20: 
21:     std::generate(vec.begin(), vec.end(), init);
22: }
```

---

### Aufrufbare Objekte / *Callable Objects*

[*Main.cpp*](../STL/Main.cpp)

```cpp
01: class InitializerForVector
02: {
03: private:
04:     int m_value;
05: 
06: public:
07:     InitializerForVector() {
08:         m_value = -1;
09:     }
10: 
11:     int nextValue() {
12: 
13:         ++m_value;
14:         return 2 * m_value + 1;
15:     }
16: 
17:     int operator () () {
18: 
19:         ++m_value;
20:         return 2 * m_value + 1;
21:     }
22: };
23: 
24: class OutputForVector
25: {
26: public:
27: 
28:     void operator () (int value) {
29:         std::cout << value << std::endl;
30:     }
31: };
32: 
33: void testSTL09()
34: {
35:     std::vector<int> vec;
36:     vec.resize(5);
37: 
38:     OutputForVector output;
39: 
40:     std::for_each(
41:         vec.begin(),
42:         vec.end(),
43:         output
44:     );
45: 
46:     InitializerForVector initializer;
47: 
48:     std::generate(
49:         vec.begin(),
50:         vec.end(),
51:         initializer
52:     );
53: 
54:     std::for_each(
55:         vec.begin(),
56:         vec.end(),
57:         output
58:     );
59: }
```

---

### Suchen in einem Container: `std::find`

[*Main.cpp*](../STL/Main.cpp)

```cpp
01: void testSTL10()
02: {
03:     std::vector<int> vec;
04:     vec.resize(100);
05: 
06:     std::generate(vec.begin(), vec.end(), init);
07: 
08:     // searching a value
09:     int element = 99;  // 99 should be an element of the vector, 98 not.
10: 
11:     std::vector<int>::iterator pos = std::find(vec.begin(), vec.end(), element);
12: 
13:     if (pos == vec.end()) {
14: 
15:         std::cout << "Element " << element << " not found!" << std::endl;
16:     }
17:     else {
18:         std::cout << "Element " << element << " found!" << std::endl;
19:     }
20: }
```

---

### Hash-Tabellen in der STL: Container `std::unordered_map`

[*Main.cpp*](../STL/Main.cpp)

```cpp
01: class PhonebookHelper
02: {
03: public:
04:     void operator () (std::pair <std::string, int> entry) {
05: 
06:         std::cout << entry.first << " - " << entry.second << std::endl;
07:     }
08: };
09: 
10: void testSTL20()
11: {
12:     // hash table with STL
13:     std::unordered_map<std::string, int> phoneBook;
14: 
15:     std::pair <std::string, int> firstEntry("Hans", 123456);
16:     phoneBook.insert(firstEntry);
17: 
18:     std::pair <std::string, int> secondEntry("Sepp", 654321);
19:     phoneBook.insert(secondEntry);
20: 
21:     std::pair <std::string, int> thirdEntry("Anton", 223355);
22:     phoneBook.insert(thirdEntry);
23: 
24:     // print phonebook to console
25:     PhonebookHelper helper;
26:     std::for_each(
27:         phoneBook.begin(),
28:         phoneBook.end(),
29:         helper
30:     );
31: }
```

---

### Suchen in einer Hash-Tabelle

[*Main.cpp*](../STL/Main.cpp)

```cpp
01: void testSTL21()
02: {
03:     // hash table with STL
04:     std::unordered_map<std::string, int> phoneBook;
05: 
06:     std::pair <std::string, int> firstEntry("Hans", 123456);
07:     phoneBook.insert(firstEntry);
08: 
09:     std::pair <std::string, int> secondEntry("Sepp", 654321);
10:     phoneBook.insert(secondEntry);
11: 
12:     std::pair <std::string, int> thirdEntry("Anton", 223355);
13:     phoneBook.insert(thirdEntry);
14: 
15:     // searching an entry
16:     std::string key("Sepp");
17: 
18:     std::unordered_map<std::string, int>::iterator  position = phoneBook.find(key);
19: 
20:     if (position == phoneBook.end()) {
21: 
22:         std::cout << "Name " << key << " not found in phonebook" << std::endl;
23:     }
24:     else {
25:         std::cout << "Name " << key << " found: ";
26:         std::pair <std::string, int> foundEntry = *position;
27:         int number = foundEntry.second;
28:         std::cout << number << std::endl;
29:     }
30: }
```

---

## Aufgaben

[Aufgabe zur STL - Standard Template Library](../Exercises/Exercises_STL.md)

---

[Zurück](Agenda.md)

---
