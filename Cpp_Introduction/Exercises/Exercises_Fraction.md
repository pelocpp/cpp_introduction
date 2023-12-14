# Aufgabe zur Klasse `Fraction`

[Zurück](./Exercises.md)

---

## Einführung

In dieser Übung wollen wir uns der Klasse `Fraction` in einer zusammenfassenden Betrachtung annehmen.

---

*Hinweis*:
Der Quellcode im Repository zu dieser Übung ist bewußt sehr elementar gehalten.
Oder um es anders zu formulieren: Viele der syntaktischen Neuerungen von C++ 11/14/17/20
sind bewußt außer Acht gelassen worden.
Es ist dem interessierten Leser überlassen, diese Neuerungen einzuarbeiten.

---

Folgenden Eigenschaften sollen in Ihrer Realisierung der Klasse `Fraction` Berücksichtigung finden:

  * Objekte der Klasse `Fraction` sollen die von ihr verwaltete rationale Zahl immer in einer
    optimal gekürzten Form verwalteten. Schreiben Sie dazu eine Methode `reduce`, die den
    Bruch optimal kürzt.

  * Rationale Zahlen können sowohl positiv als auch negativ sein. Um die klasseninterne
    Arbeitsweise der einzelnen Methoden zu vereinfachen, soll die Regel gelten, dass der
    Nenner einer rationalen Zahl immer positiv ist. Damit kann der Zähler eines
    `Fraction`-Objekts in Abhängigkeit vom Vorzeichen der rationalen Zahl entweder positiv
    oder negativ sein. Achten Sie darauf, dass bei allen Änderungen am Objektzustand (zum
    Beispiel nach einer Subtraktion) der Nenner positiv ist.

  * Gängige Konstruktoren zur Objekterzeugung.

  * Implementieren Sie die folgenden mathematischen Rechenoperationen:
    * Grundrechenoperationen (`+`, `-`, `*` und `/`).
    * Grundrechenoperationen in Verbindung mit dem Zuweisungsoperator (`+=`, `-=`, `*=`, `/=`).
    * Inkrement- und Dekrementoperator (`++` und `--`).
    * Inverse einer rationalen Zahl (Operator `~`).
    * Unärer Minus-Operator (`-`).
    * Vergleichsoperatoren (`==`, `!=`, `<`, `<=`, `>` und `>=`).

  * Methode `gcd` (*greatest common divisor*) zur Bestimmung des größten gemeinsamen Teilers von Zähler und Nenner (*ggT*).
    Die `gcd`-Methode kann von der `reduce`-Methode verwendet werden.

  * Operatoren zur Typumwandlung: Ein `Fraction`-Objekt soll in einem arithmetischen
    Ausdruck auch dann verwendet werden können, wenn auf Grund des Kontextes ein `float` oder
    `double`-Wert erwartet wird.

  * Ein- und Ausgabe: Eine rationale Zahl soll in der Form &ldquo;Zähler / Nenner&ldquo; ausgegeben werden.
    Für Eingaben ist dasselbe Format zu Grunde zu legen. Zwischen den numerischen
    Werten und dem Schrägstrich sind beliebige Leerzeichen und Tabulatoren erlaubt.

---

## Quellcode der Lösungen:

[*Fraction.h*](./Fraction/Fraction.h)<br />
[*Fraction.cpp*](./Fraction/Fraction.cpp)<br />
[*Fraction_Main.cpp*](./Fraction/Fraction_Main.cpp)<br />

---

[Zurück](./Exercises.md)

---
