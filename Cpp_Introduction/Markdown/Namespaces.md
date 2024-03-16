# Namensr�ume / Namespaces


[Zur�ck](Agenda.md)

---

## Erl�uterungen

### Hintergrund f�r das Konzept der &ldquo;Namensr�ume&rdquo;

Wenn mehrere Programmierer an einem Projekt arbeiten, dann wird der Quellcode in
verschiedene Module aufgeteilt. Jedes Programmiererteam k�mmert sich um eine
Teilaufgabe. Am Ende werden die einzelnen Module zusammengef�gt.

Wenn sich die Teams nicht haargenau absprechen, dann kommt es schon mal vor, dass
verschiedene Teams gleiche Variablennamen benutzen. Dazu kommt es zu
Namenskonflikten.

Dieses Problem umgehen wir mit Namensr�umen, also Namespaces.

Wenn jeder einen eigenen Namensraum nutzt, kann er in diesem Namensraum seine
Variablen beliebig sinnvoll benennen, ohne Namenskonflikte f�rchten zu m�ssen. Seine
Variablen und Funktionen m�ssen dann jedoch �ber den Namensraum angesprochen
werden.


### Schl�sselw�rter `using` und `namespace`

Namensr�ume werden mit dem Schl�sselwort `namespace` definiert,
f�r eine Einbindung eines Namensraums verwendet man das Schl�sselwort `using` &ndash;
in Kombination mit `namespace`, also in der Schreibweise `using namespace`.


## Beispiele

Studieren Sie das folgende Beispiel.

Die Klasse `TextBox` liegt in mehreren Varianten (von verschiedenen Entwicklern realisiert) vor.

Laden Sie die Datei *Main.cpp* in einen Editor / eine Entwicklungsumgebung
Ihrer Wahl und versuchen Sie, Objekte der unterschiedlichen `TextBox`-Varianten zu erzeugen.

Wann treten Fehlermeldungen auf? Und haben Sie daf�r eine Erkl�rung?


Datei *Main.cpp*:

```cpp
01: namespace MyFirstProject
02: {
03:     namespace Widgets
04:     {
05:         class Textbox
06:         {
07:         };
08:     }
09: }
10: 
11: namespace AnotherProject
12: {
13:     class Textbox
14:     {
15:     };
16: }
17: 
18: 
19: void test_namespace_01()
20: {
21:     using namespace MyFirstProject::Widgets;
22:     // or
23:     // using namespace AnotherProject;
24: 
25:     Textbox tb1;                             // namespace MyFirstProject::Widgets
26:                                              
27:     MyFirstProject::Widgets::Textbox tb2;    // namespace MyFirstProject::Widgets
28: 
29:     AnotherProject::Textbox tb3;             // namespace AnotherProject
30: }
31: 
32: void test_namespace_02()
33: {
34:     // accessing classes with full namespace specification
35:     using namespace MyFirstProject::Widgets;
36:     Textbox tb1;
37: 
38:     using namespace AnotherProject;
39:     // Textbox tb2;                          // doesn't compile: why
40: }
41: 
42: void test_namespace_03()
43: {
44:     // better way
45:     MyFirstProject::Widgets::Textbox tb;
46: 
47:     // or - possible - but 'smells'
48:     using namespace MyFirstProject::Widgets;
49: 
50:     Textbox tb2;
51: }
```

---

## Quellcode des Beispiels:

[*Main.cpp*](../Namespaces/Main.cpp)

---

[Zur�ck](Agenda.md)

---
