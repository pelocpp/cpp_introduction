# Referenzen


[Zur�ck](Agenda.md)

---

## Erl�uterungen

Zeiger (Pointer) der Programmiersprache C sind eine M�glichkeit,
um auf Objekte (Variablen) indirekt zugreifen zu k�nnen.

Referenzen bieten nahezu die gleichen M�glichkeiten wie Zeiger, aber mit einer wesentlich *einfacheren*
Syntax.

Es ist wichtig zu verstehen, 

  * was Referenzen sind
  * wie sich Referenzen von Zeigern unterscheiden
  * wie man Referenzen erzeugt und verwendet
  * welche Beschr�nkungen f�r Referenzen gelten
  * wie man Werte und Objekte in und aus Funktionen (Methoden) als Referenz �bergibt.


### Was ist eine Referenz?

Eine *Referenz* ist ein *Alias*-Name. 

Wenn man eine Referenz erzeugt, initialisiert man sie mit dem Namen eines
anderen Objekts, dem Zielobjekt.

Von diesem Moment an ist die Referenz wie ein alternativer Name f�r das Zielobjekt, und alles,
was man mit der Referenz anstellt, bezieht sich tats�chlich auf das Zielobjekt.

Die Deklaration einer Referenz besteht aus dem Typ des Zielobjekts, gefolgt vom Referenzoperator (`&`) und dem
Namen der Referenz.

Viele Programmierer stellen Referenzvariablen ein `r` voran.
Zum Beispiel erzeugt man f�r eine int-Variable einInt eine Referenz mit der folgenden Anweisung:

```cpp
int n = 123;
int &rInt = n;
```

## Beispiele

#### Datei *[Main.cpp](../References/References.cpp)*:

```cpp
01: void referencesUnderstanding()
02: {
03:     int n = 123;
04:     int m;
05: 
06:     // using pointers
07:     int* ip;
08: 
09:     ip = &n;      // address-of
10:         
11:     m = *ip;      // value-of / same as: m = n;
12:         
13:     ++ip;
14:     m = *ip;      // m = ???
15:         
16:     --ip;
17:     m = *ip;      // again value of n
18: 
19:     // using references
20:     int& ri = n;
21:         
22:     m = ri;       // same as: m = n;
23:         
24:     ++ri;         // n is now n + 1
25: }
```

---

## Quellcode des Beispiels:

[*Main.cpp*](../References/Main.cpp)

---

## �bungen

TBD: 

---


[Zur�ck](Agenda.md)

---
