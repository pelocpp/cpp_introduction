# Streams


[Zur�ck](Agenda.md)

---

## Erl�uterungen

Bisher haben wir mit `std::cout` auf den Bildschirm / in eine Konsole geschrieben
und mit `std::cin` von der Tastatur eingelesen, ohne eine genaue
Vorstellung davon zu haben, was sich dahinter verbirgt.


### Ein �berblick �ber Streams

Wie man in C++ Daten auf dem Bildschirm ausgibt oder in eine Datei schreibt oder wie Daten in ein Programm
eingelesen werden, ist nicht in der Sprachspezifikation festgelegt.

Dies f�llt vielmehr in den Bereich der C++&ndash;Standardbibliothek.
Sie enth�lt eine `iostream`-Teilbibliothek, mit der die Ein- und Ausgabe erleichtert wird.

F�r die `iostream`-Klassen ist der Datenfluss vom Programm zum Bildschirm ein Strom (engl. *stream*) von Daten,
bei dem ein Byte dem anderen folgt. Ist das Ziel des Stroms eine Datei oder der Bildschirm,
ist die Quelle in der Regel Teil Ihres Programms. Wird die Richtung des Stroms umgekehrt,
k�nnen die Daten von der Tastatur oder einer Datei kommen und �ergie�en� sich in Ihren Programmvariablen.

### Pufferung

Auf die Festplatte (und im geringeren Ma�e auch auf den Bildschirm) zu schreiben ist sehr �teuer�, soll hei�en: Laufzeitaufwendig.
Im Vergleich zu anderen Operationen dauert das Schreiben von Daten auf die Festplatte
oder das Lesen von der Festplatte ziemlich lange,
und die Programmausf�hrung wird f�r diese Zeitdauer im allgemeinen angehalten.

Um dieses Problem zu umgehen, werden Streams �gepuffert�.
Die Daten werden in den Stream geschrieben, der jedoch noch nicht sofort auf die Platte
zur�ckgeschrieben wird. Statt dessen f�llt sich der Strompuffer stetig,
und wenn er voll ist, schreibt er seinen Inhalt in einem Rutsch auf die Festplatte.

### Streams und Puffer

Wie nicht anders zu erwarten, werden in C++ Streams objektorientiert implementiert.

  * Die Klasse `std::streambuf` verwaltet den Puffer, und ihre Elementfunktionen �bernehmen das F�llen, das
    vollst�ndige oder teilweise Leeren sowie anderweitige Manipulationen des Puffers.
  * Die Klasse `std::ios` ist die Basisklasse f�r die Ein- und Ausgabe-Streamklassen.
    Die `std::ios`-Klasse verf�gt �ber ein `std::streambuf`-Objekt als Instanzvariable.
  * Die `std::istream`- und `std::ostream`-Klassen leiten sich von `std::ios` ab und sind f�r das Verhalten von Eingabe-
    beziehungsweise Ausgabe-Streams spezialisiert.
  * Die Klasse `iostream` leitet sich von `std::istream` und von `std::ostream` ab und stellt Ein- und Ausgabe-Methoden zur
    Verf�gung, um Daten auf dem Bildschirm auszugeben.
  * Die `std::fstream`-Klassen unterst�tzen die Eingabe und Ausgabe von und in Dateien.


### Standard-E/A-Objekte

Wenn ein C++-Programm, das die `std::iostream`-Klassen einbindet, ausgef�hrt wird,
werden drei Objekte automatisch erzeugt und initialisiert.

  * `std::cin` ist verantwortlich f�r die Eingabe von dem Standardeingabeger�t, der Tastatur.
  * `std::cout` ist verantwortlich f�r die Ausgabe auf das Standardausgabeger�t, den Bildschirm.
  * `std::cerr` ist verantwortlich f�r die ungepufferte Ausgabe auf das Standardausgabeger�t,
    den Bildschirm. Da es sich hier um eine ungepufferte Ausgabe handelt,
    wird alles, was an `std::cerr` geschickt wird, sofort auf das Standardausgabeger�t ausgegeben
   (ohne Pufferung).


### Eingabe mit `std::cin`

Das globale Objekt `std::cin` ist verantwortlich f�r die Eingabe und steht Ihrem Programm
automatisch zur Verf�gung, wenn Sie die Header-Datei `<iostream>` einbinden.
In den bisherigen Beispielen haben Sie den �berladenen Eingabe-Operator (`>>`) verwendet,
um Daten in Ihre Programmvariablen aufzunehmen.

Wie funktioniert das? Die Syntax, wie Sie sich vielleicht erinnern, sieht folgenderma�en aus:

```cpp
01: int n;
02: std::cout << "Geben Sie eine Zahl ein: ";
03: std::cin >> n;
04: std::cout << "n: " << n << std::endl;
```

Das globale Objekt `std::cout` �bergehen wir erst einmal.
Es wird in diesem Kapitel weiter hinten besprochen. Konzentrieren wir uns auf die dritte Zeile:

```cpp
std::cin >> n;
```

Was l��t sich �ber `std::cin` sagen?
Offensichtlich handelt es sich um ein globales Objekt, da Sie es nicht in Ihrem Code definiert haben.
Aus fr�heren Erfahrungen mit Operatoren k�nnen Sie schlie�en,
da� `std::cin` den Eingabe-Operator (`>>`) �berladen hat, mit der Folge,
da� alles, was im Puffer von `std::cin` steht, in Ihre lokale Variable `n` geschrieben wird.

Was vielleicht nicht so deutlich zu erkennen ist:
`std::cin` �berl�dt den Eingabe-Operator f�r eine Vielzahl von Parametern,
unter anderem `int&`, `short&`, `long&`, `double&`, `float&`, `char&`, `char*` und so weiter.
In unserem Beispiel

```cpp
std::cin >> n;
```

wird der Typ von `n` vom Compiler ermittelt. Da es sich um den Datentyp `int` handelt,
wird die folgende Funktion aufgerufen:

```cpp
std::istream& operator>> (int&);
```

Beachten Sie, da� der Parameter als **Referenz** �bergeben wird.
Deshalb kann der Eingabe-Operator auf der originalen Variablen operieren.


### Ausgabe mit `std::cout`

Bisher haben Sie `std::cout` zusammen mit dem �berladenen Ausgabe-Operator (`<<`) verwendet,
um Strings, `int`-Variablen und
andere numerische Daten auf dem Bildschirm auszugeben.
Es ist dabei m�glich, die Daten zu formatieren, spaltenweise auszurichten
und numerische Zahlen in dezimaler und hexadezimaler Schreibweise auszugeben.

Eine minimalistische Umsetzung all dieser M�glichkeiten
finden wir in der `print`-Methode der Klasse `Time` vor:


```cpp
void Time::print()
{
    std::cout << std::setw(2) << std::setfill('0') << m_hours << ":";
    std::cout << std::setw(2) << std::setfill('0') << m_minutes << ":";
    std::cout << std::setw(2) << std::setfill('0') << m_seconds;
    std::cout << std::endl;
}
```

`std::setw` setzt die Feldbreite zur Ausgabe eines Werts, mit `std::setfill` lassen sich F�llzeichen ausgeben,
wenn das vorgesehene Feld f�r die Ausgabe eines Werts gr��er als der dazu erforderliche Bereich ist.


## Beispiele

Wir geben ein kleines Beispiel f�r das Einlesen eines `int`- und eines `double`-Werts:


*Beispiele*:

```cpp
01: void testCinCout()
02: {
03:     int myInt;
04:     double myDouble;
05: 
06:     std::cout << "int:    ";
07:     std::cin >> myInt;
08: 
09:     std::cout << "double: ";
10:     std::cin >> myDouble;
11: 
12:     std::cout << "Int:    " << myInt << std::endl;
13:     std::cout << "Double: " << myDouble << std::endl;
14: }
```

*Ausgabe*:


```
int:    123
double: 123.456
Int:    123
Double: 123.456
```

---

## Quellcode des Beispiels:

[*Main.cpp*](../Streams/Main.cpp)


---

[Zur�ck](Agenda.md)

---
