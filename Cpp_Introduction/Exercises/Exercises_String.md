# Aufgabe zur Klasse `String`

[Zur�ck](./Exercises.md)

---

## �bersicht

In einer objektorientierten Sprache wie C++ geh�rt eine Klasse `String` f�r den komfortablen Umgang
mit Zeichenketten zum Pflichtbestandteil der Klassenbibliothek.

wir finden die gesuchte Klasse unter dem Namen `std::string` in der STL (&bdquo;Standard Template Library&bdquo;) vor.

Um �bung in der Anwendung der Programmiersprache C++ zu erlangen, besch�ftigen wir uns im folgenden mit der Realisierung
unserer eigenen Klasse `String`, siehe dazu die Beschreibung der �ffentlichen Schnittstelle dieser `String`-Klasse in *Tabelle* 1.

## Beschreibung

Bei der Implementierung der Klasse `String` ist der Speicherbereich f�r die einzelnen Zeichen
der Zeichenkette dynamisch zu allokieren. Der Einfachheit halber legen wir zus�tzlich zu Grunde,
dass der Umfang dieses Speicherbereichs exakt an die L�nge der Zeichenkette angepasst wird,
siehe *Abbildung* 1. Den Overhead im Arbeitsaufwand der einzelnen Methoden nehmen wir billigend in Kauf,
da wir mit dieser Vorschrift eine einfachere Realisierung erzielen  k�nnen.

<img src="String/Resources/cpp_class_string.svg" width="320">

Abbildung 1. Instanzdatenbereich eines `String`-Objekts mit dynamisch allokiertem Datenpuffer.

## M�gliche Spezifikation einer Klasse `String`

Die Klassenelemente in *Tabelle 1* m�gen eine Orientierung f�r Ihre Realisierung der Klasse `String` darstellen:

| Konstruktor    | Schnittstelle und Beschreibung |
|:-------------- |-----------------------------------------|
| Konstruktor | `String();`<br/> Standard-Konstruktor zum Anlegen einer leeren Zeichenkette.|
| Benutzerdefinierter Konstruktor | `String(const char*);`<br/> Benutzerdefinierter Konstruktor. Als Argument wird eine Folge von `char`-Elementen erwartet, die mit `'\0'` abgeschlossen ist, sprich eine klassische &bdquo;C-Zeichenkette&rdquo;. |
| Methode `length` | `int length() const;`<br/> Liefert die L�nge der Zeichenkette zur�ck. |
| Methode `insert` | `bool insert(const String& s, int ofs);`<br/> F�gt die Zeichenkette `s` in die aktuelle Zeichenketten-Instanz an der Position `ofs` ein. |
| Methode `append` | `void append(const String& s);`<br/> H�ngt die Zeichenkette `s` am Ende des aktuellen Zeichenkettenobjekts an. |
| Methode `remove` | `bool remove (int ofs, int num);`<br/> Entfernt `num` Zeichen an der Position `ofs` des aktuellen Zeichenkettenobjekts. |
| Methode `subString` | `String subString(int ofs, int num) const;`<br/> Extrahiert eine Teilzeichenkette (beginnend an der Position `ofs` mit `num` Zeichen) aus dem aktuellen Zeichenkettenobjekt. Das Ergebnis wird in Gestalt eines `String`-Objekts zur�ckgeliefert. |
| Methode `find` | `int find(const String& s) const;`<br/> Sucht nach der Zeichenkette `s` im aktuellen Zeichenkettenobjekt. Wird die Zeichenkette gefunden, wird der Index (ihres ersten Vorkommens) innerhalb des aktuellen Zeichenkettenobjekts zur�ckgeliefert, andernfalls der Wert -1. |
| Methode `toUpper` | `void toUpper();`<br/> Wandelt alle Kleinbuchstaben im aktuellen Zeichenkettenobjekt in Gro�buchstaben um. |
| Methode `toLower` | `void toLower();`<br/> Wandelt alle Gro�buchstaben im aktuellen Zeichenkettenobjekt in Kleinbuchstaben um. |
| Methode `left` | `String left (int num);`<br/> Liefert die ersten `num` Zeichen des aktuellen Zeichenkettenobjekts in Gestalt eines eigenst�ndigen Zeichenkettenobjekts zur�ck. |
| Methode `right` | `String right (int num);`<br/> Liefert die letzten `num` Zeichen des aktuellen Zeichenkettenobjekts in Gestalt eines eigenst�ndigen Zeichenkettenobjekts zur�ck. |
| operator `[]` | `char& operator[] (int n);`<br/> Indexoperator, liefert das *n*.-te Zeichen aus der Zeichenkette zur�ck oder erm�glicht das Ver�ndern dieses Zeichens. |
| operator `+` | `friend String operator+ (const String& s1, const String& s2);`<br/> Verkn�pfung von zwei Zeichenketten in Operatorenschreibweise als Alternative zur `append`-Methode. Der `+`&ndash;Operator liefert als Resultatobjekt die Verkettung der zwei Zeichenketten `s1` und `s2` zur�ck, d.h. ihre Hintereinanderschreibung. Die Objekte `s1` und `s2` bleiben bei dieser Operation unver�ndert. |
| operator `+=` | `friend String& operator+= (String& s, const String& s1);`<br/> Verkn�pfung von zwei Zeichenketten in Operatorenschreibweise als Alternative zur `append`-Methode. Der `+=`-Operator h�ngt die Zeichenkette `s1` an `s` an, das Ergebnis der Verkettung kommt folglich in Objekt `s` zum Tragen. |
| operator `==` | `friend bool operator== (const String& s1, const String& s2);`<br/> Der ==-Operator vergleicht zwei Zeichenkettenobjekte auf inhaltliche Gleichheit. |
| operator `!=` | `friend bool operator!= (const String& s1, const String& s2);`<br/> Der !=-Operator vergleicht zwei Zeichenkettenobjekte auf inhaltliche Ungleichheit. |
| Ausgabe | `friend std::ostream & operator<< (std::ostream&, const String&);` <br/> Ausgabe einer Zeichenkette in der Konsole. Die Ausgabe der Zeichenkette `"ABC"` sollte wiederum im Format `"ABC"[3]` erfolgen, die L�nge der Zeichenkette ist in eckigen Klammern aufzuf�hren. |
| Eingabe | `friend std::istream & operator>> (std::istream&, String&);` <br/> Eingabe einer Zeichenkette in der Konsole. Bei der Eingabe darf man in der Implementierung eine maximale Anzahl f�r die einzulesenden Zeichen voraussetzen. |

*Tabelle* 1. Elemente der Klasse `String`.

*Hinweis*: Klassenelemente wie der Kopierkonstruktor oder der Destruktor fehlen in *Tabelle* 1,
da sie in einer korrekten Realisierung ohnehin vorhanden sein m�ssen.

Die in der L�sung vorgestellte Implementierung der Klasse `String` verzichtet auf jegliche Unterst�tzung aus der *C Runtime Library* (*CRT*).
Dies erfolgt zu Lehrzwecken, um die Realisierung einer Klasse ohne jegliche Unterst�tzung durch eine externe Bibliothek zu betrachten.
In der Praxis w�rde man zur Realisierung die *CRT* mit einbeziehen, um das Rad f�r eine Reihe elementarer Operationen wie
&bdquo;Zeichenkette kopieren&rdquo;, &bdquo;Zeichenkette vergleichen&rdquo;, usw. nicht zweimal erfinden zu m�ssen.

---

## Quellcode der L�sungen:

[*String.h*](./String/String.h)<br />
[*String.cpp*](./String/String.cpp)<br />
[*String_Main.cpp*](./String/String_Main.cpp)<br />

---

[Zur�ck](./Exercises.md)

---

