# Technik der �bergabe von Parametern


[Zur�ck](Agenda.md)

---

## Erl�uterungen

Es gibt verschiedene M�glichkeiten, Parameter an Methoden (Funktionen) zu �bergeben.

*Vorab zur Nomenklatur*:

Die an die Funktion �bergebenen Parameter werden als *Aktualparameter* (*Actual Parameter*) bezeichnet,
w�hrend die von der Funktion empfangenen Parameter als *Formalparameter* (*Formal Parameter*) bezeichnet werden.

*Beispiel*:

```cpp
void func(int a, int b)
{
    int sum;

    sum = a + b;

    std::cout << "In func: a = " << a << ", b = " << b << ", sum = " << sum << std::endl;
}
    
void testFunc()
{
    int x = 123;
    int y = 456;

    // passing parameters
    func(x, y);

    // passing again parameters
    func(123, 321);
}
```

Funktion `func` besitzt die beiden formalen Parameter `a` und `b` (vom Datentyp `int`).
Als Aktualparameter treten die beiden Variablen `x` und `y` sowohl die Konstanten `123` und `321` in Erscheinung.


### Parameter�bergabemechanismus *Call-by-Value*

Bei der *Call-by-Value*-Aufrufmethode der Parameter�bergabe werden die Werte der Aktualparameter
in die formalen Parameter der Funktion kopiert.

Es gibt folglich pro Parameter zwei verschiedene Speicherorte, an denen der Wert eines Parameters vorhanden ist:

  * Einen originalen Speicherort, der den Wert des Aktualparameters als Inhalt hat.
  * Eine Funktionskopie, die denselben Inhalt wie der originale Speicherort hat, aber nur in der Funktion verf�gbar ist.

Alle innerhalb von Funktionen vorgenommenen �nderungen werden an den Funktionskopien vorgenommen und damit
nicht in den tats�chlichen Parametern (originaler Speicherort) des Funktionsaufrufs widergespiegelt.


<img src="cpp_call_by_value.svg" width="360">

*Abbildung* 1: Parameter�bergabemechanismus *Call-by-Value*.


### Parameter�bergabemechanismus *Call-by-Reference*

Bei der *Call-by-Reference*-Aufrufmethode wird die Adresse des Aktualparameters als formaler Parameter an die Funktion �bergeben.

  * Sowohl der Aktualparameter als auch der formale Parameter (Funktionskopie) beziehen sich damit auf denselben Speicherort.
  * Alle innerhalb der Funktion vorgenommenen �nderungen an den Funktionskopien
    spiegeln sich in den aktuellen Parametern des Aufrufs wider.


<img src="cpp_call_by_reference.svg" width="500">

*Abbildung* 2: Parameter�bergabemechanismus *Call-by-Reference*.


### Zur Abrundung: Parameter�bergabemechanismus *Call-by-Address*

Im Prinzip ist diese Aufrufmethode identisch zur *Call-by-Reference*-Methode.
Da wir in C++ die beiden Sprachmittel *Zeiger* und *Referenz* haben,
k�nnen Aktualparameter durch eine explizite Adresse (explizite Verwendung des Adress-Operators `&`)
oder eben durch eine Referenz (Adresse wird implizit gebildet) �bergeben werden.
Im zweiten Fall bedarf es keines Gebrauchs des Adress-Operators,
allerdings muss der Parameter der Funktion vom Typ *Referenz* sein.

<img src="cpp_call_by_address.svg" width="500">

*Abbildung* 3: Parameter�bergabemechanismus *Call-by-Address*.


## Beispiele

Studieren Sie sorgf�ltig die folgenden drei Realisierungen einer Funktion `multiplyByTwo`:

#### Datei [*Main.cpp*](../ParameterPassingTechniques/Main.cpp) - Testrahmen:

```cpp
01: void multiplyByTwo(int n)
02: {
03:     n = 2 * n;
04: }
05: 
06: void multiplyByTwo(int* ip) 
07: {
08:     int tmp = *ip; 
09:     tmp = 2 * tmp;
10:     *ip = tmp;
11: }
12: 
13: void multiplyByTwo(int& n) 
14: {
15:     n = 2 * n;
16: }
```

```cpp
void testMultiplyByTwo()
{
    int x = 10;

    std::cout << x << std::endl;
    multiplyByTwo01(123);
    std::cout << x << std::endl;

    multiplyByTwo02(&x);           // &: address-of / pointer is passed
    std::cout << x << std::endl;

    multiplyByTwo03(x);            // a reference of 'x' is passed
    std::cout << x << std::endl;
}
```

*Ausgabe*:

```
10
10
20
40
```

*Hinweis*:
Der Datentyp *Zeiger* (*Pointer*) ist Bestandteil der Programmiersprache C &ndash; und deshalb gewisserma�en automatisch
auch in C++ vorhanden. Auf Grund der nicht ganz einfachen Syntax bzw. Handhabung dieses Sprachmittels
wurde in C++ der Sprachkonstrukt der *Referenz* hinzugef�gt.
Aus diesem Grund lassen sich nun Funktionen wie `multiplyByTwo` prinzipiell auf zwei Weisen programmieren.
Man sollte aber immer, wenn m�glich, den Referenzen den Vorzug geben.

*Hinweis*:
Warum ist f�r die Aufrufmethoden *Call-by-Address* und *Call-by-Reference* die folgende Anweisung
nicht �bersetzungsf�hig?

```cpp
multiplyByTwo(123);
```

---

## Anwendung der Parameter�bergabetechnik auf Methoden einer Klasse

### Design einer Methoden-Schnittstelle

Wenn Sie Methoden eine Klasse definieren, die Parameter besitzt,
sollten Sie genau darauf achten, wie Sie die Schnittstelle der Methode definieren.

Betrachten wir als Beispiel eine Methode `diff` der Klasse `Time`,
die die Differenz zweier Uhrzeiten berechnet:

1. Ansatz:

```cpp
 Time diff(Time other);
```

Machbar, allerdings wird beim Aufruf von `diff` eine Kopie erzeugt und an  `diff` �bergeben.
Das kostet unn�tz verbrauchte Laufzeit.

2. Ansatz:

```cpp
 Time diff(Time& other);
```

Besser, es wird eine Referenz an `diff` �bergeben und damit keine �berfl�ssige Kopie erzeugt.
Nachteilig ist, dass in der Realisierung von `diff` das Originalobjekt modifiziert werden k�nnte.
`diff` verwendet einen Alias-Namen.

3. Ansatz:

```cpp
 Time diff(const Time& other);
```

Besser, es wird eine Referenz an `diff` �bergeben und verhindert,
dass `diff` das Originalobjekt durch Verwendung des Alias-Namens ver�ndert.
Allerdings k�nnte das Objekt, an dem die `diff`-Methode aufgerufen wird,
seine eigenen Instanzvariablen ver�ndern.

4. Ansatz:

```cpp
 Time diff(const Time& other) const;
```

Optimale Realisierung: `diff` operiert auf einem Alias-Objekt, also laufzeit-optimal mit einer Referenz.
Weder das �bergebene Objekt noch das rufende Objekt k�nnen in der Realisierung
von `diff` ver�ndert werden.


### Schl�sselwort `const`

In den letzten Beispiel wurde viel das Schl�sselwort `const` eingesetzt.
Dies kann Nebenwirkungen bzgl. unterlagerter Methoden haben.

Ein Beispiel hierzu:

Ruft man im Kontext einer Methode `diff` mit der Signatur

```cpp
 Time diff(const Time& other) const;
```

weitere, unterlagerte Methoden auf &ndash; entweder am Objekt `other` oder am gerufenen Objekt (`*this`) &ndash;,
dann m�ssen diese Methoden ebenfalls als `const` definiert sein, siehe zum Beispiel
die *getter* der `Time`-Klasse:


```cpp
// getter
int getSeconds() const { return m_seconds; }
int getMinutes() const { return m_minutes; }
int getHours() const { return m_hours; }
```

Im aktuellen Beispiel der `diff`-Methoden verwenden wir eine Hilfsmethode `timeToSeconds`,
ihre Schnittstelle muss so aussehen:

```cpp
int timeToSeconds() const;
```

---

## Quellcode des Beispiels:

[*Main_ParametersPassing.cpp*](../ParameterPassingTechniques/Main_ParametersPassing.cpp)<br />
[*Time.cpp*](../ParameterPassingTechniques/Time.cpp)<br />
[*Time.h*](../ParameterPassingTechniques/Time.h)<br />
[*Main_Time.cpp*](../ParameterPassingTechniques/Main_Time.cpp)<br />

---

## Aufgaben

[Aufgabe zur Funktion `swap`](../Exercises/Exercises_References_Pointers.md)

---

[Zur�ck](Agenda.md)

---
