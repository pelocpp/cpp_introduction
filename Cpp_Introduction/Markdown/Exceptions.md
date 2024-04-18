# Exceptions / Behandlung von Ausnahmen


[Zur�ck](Agenda.md)

---

## Erl�uterungen

Auch wenn wir es nicht wahr haben wollen:
In den von uns geschriebenen Programmen k�nnen Fehler auftreten.
Einen Teil dieser Fehler k�nnten wir durch entsprechende Anweisungen im Quellcode erkennen
und w�ren somit in der Lage, darauf zu reagieren:

Entsprechende Gegenreaktionen k�nnten sein:

  * Die Beschreibung durch den R�ckgabewert einer Funktion/Methode.
  * Die �bergabe einer Variablen per Referenz,
    die den Fehler dann in kodierter Form beschreibt.
  * Das Beschreiben einer globalen Variablen.

Andere Fehler wiederum treten &ldquo;�berraschend&rdquo; auf, und im schlimmsten Fall
kommt es zu einem Absturz der Programms.

In C++ hat man ein weiteres Sprachmittel hinzugef�gt: 

### Exceptions

*Exceptions* (*Ausnahmen*) werden in C++ durch ein Objekt beschrieben,
das aus dem Codeabschnitt, in dem das Problem / der Fehler / der Absturz auftritt,
an einen anderen Abschnitt im Code �bergeben wird, in dem das Problem dann behandelt werden soll.

Der Typ der *Exception* (*Exceptions* sind Instanzen einer bestimmten Klasse) legt fest,
welche Anweisungen im Code die weitere Behandlung des Fehlers �bernehmen.
Der Inhalt des ausgel�sten Objekts l�sst sich zur weiteren Behandlung
durch den Anwender einsetzen.


### Komponenten der Exception-Behandlung

Codeabschnitte, die ein Problem hervorrufen k�nnen,
schlie�t man in `try`-Bl�cke ein. Zum Beispiel

```cpp
01: try
02: {
03:     dangerousFunction();
04: }
```

`catch`-Bl�cke behandeln die im `try`-Block aufgetretenen Exceptions. Zum Beispiel:


```cpp
01: try
02: {
03:     dangerousFunction();
04: }
05: catch (std::out_of_range)
06: {
07:     // do something because of out_of_range exception
08: }
09: catch (std::overflow_error)
10: {
11:     // do something because of overflow_error exception
12: }
13: catch (std::invalid_argument)
14: {
15:     // do something because of invalid_argument exception
16: }
17: catch (std::exception)
18: {
19:     // an unexpected exception occurred
20: }
```

Wir erkennen: Beim Einsatz von *Exceptions* sind folgende grundlegende Schritte auszuf�hren:

  * Die Programmbereiche ermitteln, in denen Operationen zu Ausnahmen f�hren k�nnen, und diese
    Bereiche in `try`-Bl�cke einschlie�en.
  * `catch`-Bl�cke aufsetzen, um eventuell ausgel�ste Ausnahmen abzufangen, reservierten Speicher
    freizugeben und den Anwender in geeigneter Weise zu informieren.

*Exceptions* (Ausnahmen) sind Objekte, die Informationen �ber ein Problem �bermitteln.

Ein `try`-Block ist ein in geschweifte Klammern eingeschlossener Block,
in dem Ausnahmen auftreten k�nnen.

Der `catch`-Block ist der unmittelbar auf einen `try`-Block folgende Block.
Hier werden die Exceptions behandelt.

Nach dem Ausl�sen einer Ausnahme geht die Programmsteuerung an den `catch`-Block �ber,
der unmittelbar auf den aktuellen `try`-Block folgt.

Tritt keine Ausnahme ein, werden alle `catch`-Bl�cke �bersprungen.


## Beispiele


*Beispiele*:

```cpp
01: void testExceptions()
02: {
03:     try
04:     {
05:         std::string str("Zeichenkette");
06:         std::cout << str << std::endl;
07: 
08:         int pos = 123;
09:         char ch = str.at(pos);
10: 
11:         size_t len = str.length();
12:         std::cout << "Length: " << len << std::endl;
13: 
14:         str.insert(123, " !!!");
15:         std::cout << str << std::endl;
16:     }
17:     catch (std::out_of_range ex)
18:     {
19:         // do something because of out_of_range exception
20:         std::cout << "std::out_of_range: " << ex.what() << std::endl;
21:     }
22:     catch (std::invalid_argument ex)
23:     {
24:         // do something because of invalid_argument exception
25:         std::cout << "std::invalid_argument: " << ex.what() << std::endl;
26:     }
27:     catch (std::length_error ex)
28:     {
29:         // do something because of invalid_argument exception
30:         std::cout << "std::length_error: " << ex.what() << std::endl;
31:     }
32:     catch (std::exception ex)
33:     {
34:         // an unexpected exception occurred
35:         std::cout << "std::exception: " << ex.what() << std::endl;
36:     }
37: 
38:     std::cout << "Done." << std::endl;
39: }
```

*Ausgabe*:


```
Zeichenkette
std::out_of_range: invalid string position
Done.
```

*1. Bemerkung*:
Setzen Sie in Zeile 8 des Beispiels die Variable `pos` auf einen korrekten Wert.
Beobachten Sie dann die Ausf�hrung des Programms.

*2. Bemerkung*:
Setzen Sie im Beispiel die Zeilen 17 bis 21 in Kommentar.
Beobachten Sie jetzt die Ausf�hrung des Programms.
Was f�llt Ihnen auf?

---

## Quellcode des Beispiels:

[*Main.cpp*](../Exceptions/Main.cpp)

---

## Aufgaben

[Aufgabe zu einem Geldbeutel: Klasse `Wallet`](../Exercises/Exercises_Wallet.md)

Die Realisierung von Konstruktoren der Klasse `Wallet` kann geignet bei negativen Geldbetr�gen reagieren.


[Aufgabe zur Klasse `DynamicIntArray`](../Exercises/Exercises_DynamicIntArray.md)

Die Realisierung des Operators `[]` bzw. eine Methode `at`
kann nun geeignet auf falsche Indices reagieren.

---

[Zur�ck](Agenda.md)

---
