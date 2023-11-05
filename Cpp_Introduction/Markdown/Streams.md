# Streams


[Zurück](Agenda.md)

---

## Erläuterungen

Bisher haben wir mit `std::cout` auf den Bildschirm / in eine Konsole geschrieben
und mit `std::cin` von der Tastatur eingelesen, ohne eine genaue
Vorstellung davon zu haben, was sich dahinter verbirgt.


### Streams &ndash; ein Überblick

Wie man in C++ Daten auf dem Bildschirm ausgibt oder in eine Datei schreibt oder wie Daten in ein Programm
eingelesen werden, ist nicht in der Sprachspezifikation festgelegt.

Dies fällt vielmehr in den Bereich der C++&ndash;Standardbibliothek.
Sie enthält eine `iostream`-Teilbibliothek, mit der die Ein- und Ausgabe erleichtert wird.

Für die `iostream`-Klassen ist der Datenfluss vom Programm zum Bildschirm ein Strom (engl. *stream*) von Daten,
bei dem ein Byte dem anderen folgt. Ist das Ziel des Streams eine Datei oder der Bildschirm,
ist die Quelle in der Regel Teil Ihres Programms. Wird die Richtung des Streams umgekehrt,
können die Daten von der Tastatur oder einer Datei kommen und »ergießen« sich in Ihren Datenvariablen.

### Pufferung

Auf die Festplatte (und im geringeren Maße auch auf den Bildschirm) zu schreiben ist sehr »teuer«.
Im Vergleich zu anderen Operationen dauert das Schreiben von Daten auf die Festplatte
oder das Lesen von der Festplatte ziemlich lange,
und die Programmausführung wird für diese Zeitdauer im allgemeinen angehalten.

Um dieses Problem zu umgehen, werden Streams »gepuffert«.
Die Daten werden in den Stream geschrieben, der jedoch noch nicht sofort auf die Platte
zurückgeschrieben wird. Statt dessen füllt sich der Streampuffer stetig,
und wenn er voll ist, schreibt er seinen Inhalt auf einmal auf die Platte.

### Streams und Puffer

Wie nicht anders zu erwarten, werden in C++ Streams objektorientiert implementiert.

  * Die Klasse `std::streambuf` verwaltet den Puffer, und ihre Elementfunktionen übernehmen das Füllen, das
    vollständige oder teilweise Leeren sowie anderweitige Manipulationen des Puffers.
  * Die Klasse `std::ios` ist die Basisklasse für die Ein- und Ausgabe-Streamklassen.
    Die `std::ios`-Klasse verfügt über ein `std::streambuf`-Objekt als Elementvariable.
  * Die `std::istream`- und `std::ostream`-Klassen leiten sich von `std::ios` ab und sind für das Verhalten von Eingabe-
    beziehungsweise Ausgabe-Streams spezialisiert.
  * Die Klasse `iostream` leitet sich von `std::istream` und von `std::ostream` ab und stellt Ein- und Ausgabe-Methoden zur
    Verfügung, um Daten auf dem Bildschirm auszugeben.
  * Die `std::fstream`-Klassen unterstützen die Eingabe und Ausgabe von und in Dateien.


### Standard-E/A-Objekte

Wenn ein C++-Programm, das die `std::iostream`-Klassen einbindet, ausgeführt wird,
werden drei Objekte erzeugt und initialisiert.

  * `std::cin` ist verantwortlich für die Eingabe von dem Standardeingabegerät, der Tastatur.
  * `std::cout` ist verantwortlich für die Ausgabe auf das Standardausgabegerät, den Bildschirm.
  * `std::cerr` ist verantwortlich für die ungepufferte Ausgabe auf das Standardausgabegerät,
    den Bildschirm. Da es sich hier um eine ungepufferte Ausgabe handelt,
    wird alles, was an `std::cerr` geschickt wird, sofort auf das Standardausgabegerät ausgegeben
   (ohne Pufferung).


### Eingabe mit `std::cin`

Das globale Objekt `std::cin` ist verantwortlich für die Eingabe und steht Ihrem Programm
automatisch zur Verfügung, wenn Sie die Header-Datei `<iostream>` einbinden.
In den bisherigen Beispielen haben Sie den überladenen Eingabe-Operator (`>>`) verwendet,
um Daten in Ihre Programmvariablen aufzunehmen.

Wie funktioniert das? Die Syntax, wie Sie sich vielleicht erinnern, sieht folgendermaßen aus:

```cpp
01: int n;
02: std::cout << "Geben Sie eine Zahl ein: ";
03: std::cin >> n;
04: std::cout << "n: " << n << std::endl;
```

Das globale Objekt `std::cout` übergehen wir erst einmal.
Es wird in diesem Kapitel weiter hinten besprochen. Konzentrieren wir uns auf die dritte Zeile:

```cpp
std::cin >> n;
```

Was läßt sich über `std::cin` sagen?
Offensichtlich handelt es sich um ein globales Objekt, da Sie es nicht in Ihrem Code definiert haben.
Aus früheren Erfahrungen mit Operatoren können Sie schließen,
daß `std::cin` den Eingabe-Operator (`>>`) überladen hat, mit der Folge,
daß alles, was im Puffer von `std::cin` steht, in Ihre lokale Variable `n` geschrieben wird.

Was vielleicht nicht so deutlich zu erkennen ist:
`std::cin` überlädt den Eingabe-Operator für eine Vielzahl von Parametern,
unter anderem `int&`, `short&`, `long&`, `double&`, `float&`, `char&`, `char*` und so weiter.
In unserem Beispiel

```cpp
std::cin >> n;
```

wird der Typ von eineVariable vom Compiler ermittelt. Da es sich um einen `int`-Wert
handelt, wird die folgende Funktion aufgerufen:

```cpp
std::istream & operator>> (int &);
```

Beachten Sie, daß der Parameter als **Referenz** übergeben wird.
Deshalb kann der Eingabe-Operator auf der originalen Variablen operieren.


### Ausgabe mit `std::cout`

Bisher haben Sie `std::cout` zusammen mit dem überladenen Ausgabe-Operator (`<<`) verwendet,
um Strings, `int`-Variablen und
andere numerische Daten auf dem Bildschirm auszugeben.
Es ist dabei möglich, die Daten zu formatieren, spaltenweise auszurichten
und numerische Zahlen in dezimaler und hexadezimaler Schreibweise auszugeben.

In der `print`-Methode der Klasse `Time` finden wir zwei Umsetzungen vor:


```cpp
void Time::print()
{
    std::cout << std::setw(2) << std::setfill('0') << m_hours << ":";
    std::cout << std::setw(2) << std::setfill('0') << m_minutes << ":";
    std::cout << std::setw(2) << std::setfill('0') << m_seconds;
    std::cout << std::endl;
}
```

## Beispiele

Wir geben ein kleines Beispiel für das Einlesen eines `int`- und eines `double`-Werts:


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

[Main.cpp](..\Streams\Main.cpp)

---


## Übungen

TBD: TBD 


---


[Zurück](Agenda.md)

---
