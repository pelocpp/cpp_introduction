# Historisches zu C++

[Zurück](../../Readme.md)

---

## Ursprünge von C und C++

### C: Mutter aller modernen Programmiersprachen

  * Entstehungsjahr: 1972
  * Entwickler: Dennis Ritchie
  * Motivation: C wurde entwickelt, um das Betriebssystem UNIX zu schreiben und bot im Vergleich zu Assemblersprachen eine höhere Abstraktion und Portabilität.
  * Auswirkungen: C war fundamental für die Entwicklung vieler Betriebssysteme und hat eine Reihe anderer Programmiersprachen beeinflusst, einschließlich seines direkten Nachfolgers C++.

### C++: Ergänzung um die Möglichkeiten der objektorientierten und generischen Programmierung

  * Entstehungsjahr: 1983
  * Entwickler: Bjarne Stroustrup (STL: Alexander Stepanov)
  * Motivation: C++ wurde entwickelt, um Objektorientierung und Datenabstraktion zur Sprache C hinzuzufügen, mit dem Ziel, die Softwareentwicklung produktiver und qualitativer zu gestalten.
  * Auswirkungen: Mit seinen erweiterten Fähigkeiten förderte C++ die Entwicklung komplexerer und leistungsstärkerer Software-Anwendungen.

## Historisches zu C

In den frühen 1970er Jahren entwickelte Dennis Ritchie an den Bell Labs eine Programmiersprache mit dem minimalistischen Namen C. Sie basiert auf dem Vorläufer, der Programmiersprache B, daher ihr Name. C wurde zur besseren Programmierung des Betriebssystems Unix geschaffen und verbreitete sich entsprechend schnell in der Systemprogrammierung.

<br />

<img src="Ken_Thompson_and_Dennis_Ritchie.jpg" width="400">

*Abbildung* 1: Der Erfinder von C: *Dennis Ritchie* (rechts), zusammem mit Ken Thompson.

C ist eine so genannte imperative und prozedurale Programmiersprache, sie ist eine der am weitesten verbreiteten Programmiersprachen.

Bei der Entwicklung von C stützte sich Dennis Ritchie auf die Programmiersprache B,
die er mit Ken Thompson in den Jahren 1969/70 geschrieben hatten &ndash; der Name C entstand als Weiterentwicklung von B.
B wiederum geht auf die von Martin Richards Mitte der 1960er-Jahre entwickelte Programmiersprache BCPL zurück.Ursprünglich war der Name NB („New B“) vorgesehen, daraus wurde schließlich C. Ritchie schrieb auch den ersten Compiler für C.
1973 war die Sprache so weit ausgereift, dass man nun den Unix-Kernel für die PDP-11 neu in C schreiben konnte.

## Historisches zu C++

**C++** ist eine high-level, general-purpose Programmiersprache, 
die von dem dänischen Informatiker *Bjarne Stroustrup* als Erweiterung der Programmiersprache C erfunden wurde.

<br />

<img src="BjarneStroustrup.png" width="400">

*Abbildung* 2: Der Erfinder von C++: *Bjarne Stroustrup*.

Stroustrup wollte eine leistungsfähige, effiziente Sprache schaffen, die sich für die Erstellung komplexer Softwareanwendungen eignet.
Er war frustriert über die Einschränkungen von C und suchte nach einer Möglichkeit, die Programmiersprache zu erweitern,
um eine höhere Abstraktionsebene und eine objektorientierte Programmierung (Object Oriented Programming) zu ermöglichen.
Der erste Prototyp von C++ wurde 1983 erstellt und hatte den Namen “C with Classes”.

Eine Pilotsprache &ldquo;C mit Klassen&rdquo; diente als Vorlage für C++,
sie griff auf Strukturen und Konzepte von C zurück und war um objektorientierte Elemente erweitert.
&ldquo;C mit Klassen&rdquo; wiederum besaß eine Reihe von Anleihen bei *Simula-67*,
die man wohl als älteste objektorientierte Programmiersprache bezeichnen kann.
Sie wurde im Jahre 1967 konzipiert, kannte bereits das Konzept der Klassen, der abgeleiteten Klassen und der virtuellen Funktionen.
Zur damaligen Zeit kamen diese Konzepte jedoch zu früh und Simula-67 konnte sich am Markt nicht durchsetzen.
1983 prägte *Rick Mascitti* den Begriff “*C++*” in Anlehnung an den Inkrementoperator `++` von C.
In der Tat wurde auch der Name *D* diskutiert. 
Da C komplett in C++ als Teilmenge enthalten sein sollte, wollte man dies in der Bezeichnung des Namens
auch zum Ausdruck bringen und verwarf den Namen *D*.

Im Jahre 1985 existierte in der Firma AT&amp;T die erste Version eines C++&ndash;Compilers:
Er firmierte unter den Namen *Cfront* und konvertierte C++ Quellcode in C Quellcode.

In den darauffolgenden sechs Monaten glückte die kommerzielle Portierung dieses Übersetzers auf über 24 verschiedene Systeme. 
AT&amp;T Bell Laboratories gestand Bjarne Stroustrup das Recht zu, das Referenzhandbuch seines Sprachentwurfs
mit anderen zu diskutieren und es weiterzugeben.
Durch Informationen und Diskussionen, die in der Newsgroup *comp.lang.c++* geführt wurden,
kam es zu einer schnellen Verbreitung und Akzeptanz der neugeschaffenen Programmiersprache C++.
In Papierform wurde C++ im Jahre 1986 durch das Referenzhandbuch *The C++ Programming Language* beschrieben.

Die Standardisierungsbemühungen des American National Standards Institutes (ANSI) wurden 1989
durch die Gründung des Kommitees X3J16 auf Initiative von Hewlett Packard vorangetrieben.
Das standardisierte C++ soll auf die AT&amp;T-Version 2.0 des C++&ndash;Compilers aufbauen sowie im wesentlichen ANSI C beinhalten. 
1990 veröffentlichten *Margaret A. Ellis* und Bjarne Stroustrup das
Referenzmanual *The Annotated C++ Reference Manual* im Addison-Wesley-Verlag.
Ab diesem Zeitpunkt finden regelmäßig Konferenzen über C++ statt,
die neue Entwicklungen der Sprache diskutieren. 
Im März 1996 veröffentlichen das Komitee X3J16 der ANSI und die Arbeitsgruppe WG21 der ISO in Austin, Texas ein Dokument,
das als &ldquo;*Draft C++ Standard*&rdquo; bekannt wurde.
Nach neun Jahren Arbeit verabschieden diese beiden Standardisierungsgremien den ANSI C++&ndash;Standard (ISO/IEC 14882).

Die Sprache hat sich im Laufe der Zeit erheblich erweitert, und *Modern C++* verfügt jetzt
über objektorientierte, generische und funktionale Möglichkeiten sowie über Funktionen zur Low-Level Speichermanipulation.
Es wird fast immer als kompilierte Sprache implementiert, und viele Anbieter bieten für C++ Compiler an,
darunter die Free Software Foundation, LLVM, Microsoft, Intel, Oracle und IBM.
C++ ist daher auf sehr vielen Plattformen verfügbar.

Einen genauen Abriss zur geschichtlichen Entwicklung von C++ kann man
[hier](https://en.cppreference.com/w/cpp/language/history)
nachlesen.


## Unterschiede zwischen C und C++

Alleine durch das jeweilige Alter der beiden Programmiersprachen bedingt ergeben sich eine Reihe von Unterschieden in deren technischen Möglichkeiten:

  * C wurde 1972 eingeführt, während C++ erst 1984 erschien. Seitdem hat sich Einiges in der Entwicklung von Computern und Programmiersprachen getan.
  * C ist eine prozedurale Programmiersprache und arbeitet nah an der Maschinenebene, sodass die Befehle auch vergleichsweise einfach und rudimentär sind.
  * C war lange Zeit der Standard unter den Programmiersprachen. Auch heutzutage lernen viele Studierende als erste Programmiersprachen C.
  * C lässt sich durch seine Low-Level-Programmierung für die Gerätesteuerung (Hardware) wie beispielsweise im BIOS
  oder für die Programmierung von Betriebssystemen (Firmware, Treiber) einsetzen. Aber auch für Game-Engines, komplexe Berechnungen und Kryprographie eignet sich C bestens.
  * C++ hingegen ist in manchen Prinzipien an C angelehnt, beherzigt aber außer der prozeduralen Programmierung auch Objektorientierung und generische Programmierung und ist daher auch heute noch in der Lage, Programme mit der Komplexität von Java, Python oder C# zu erstellen.
  * C++ eignet sich durch seine Nähe zu C für schnell laufende und gut abgestimmte Programme. Als ursprüngliche Erweiterung kann C++ alles, was C kann. Umgekehrt ist das nicht der Fall.
  * Trotz der Unterschiede gibt es auch Gemeinsamkeiten. Neben einer ähnlichen Syntax und den flüssig laufenden Programmen sind vor allem das komplizierte Speichermanagement und eine geringe Fehlertoleranz zu nennen.
  * Allerdings ist bei C++ die Lernkurve sehr steil, weil Anfänger schnell komplexere Programme schreiben können und Umsteiger von C sich schnell zurechtfinden.

---

## Was denken andere Entwickler über C++?

&ldquo;*C++ makes it much harder to shoot yourself in the foot, but when you do, it blows off your whole leg.*&rdquo; &ndash; **Bjarne Stroustrup**.

&ldquo;*In C we had to code our own bugs. In C++ we can inherit them.*&rdquo; &ndash; **Prof. Gerald Karam**.

&ldquo;*Fifty years of programming language research, and we end up with C++&nbsp;???*&rdquo; &ndash; **Richard A. O'Keefe**, Computer scientist, concentrating on languages for logic programming and functional programming (including Prolog and Haskell).

&ldquo;*I invented the term 'Object-Oriented', and I can tell you I did not have C++ in mind.*&rdquo; &ndash; **Alan Kay**, creator of Smalltalk.

&ldquo;*C++: Hard to learn and built to stay that way."*&rdquo; &ndash; *Without author*;

&ldquo;*Java is, in many ways, C++--.*&rdquo; &ndash; **Michael Feldman**, Professor Emeritus at the George Washington University, Department of Computer Science, Washington.

&ldquo;*Writing in C or C++ is like running a chain saw with all the safety guards removed.*&rdquo; &ndash; **Bob Gray**.

&ldquo;*Ever spend a little time reading comp.lang.c++&nbsp;? That's really the best place to learn about the number of C++ users looking for a better language.*&rdquo; &ndash; **R. William Beckwith**.

&ldquo;*The evolution of languages: FORTRAN is a non-typed language. C is a weakly typed language. Ada is a strongly typed language. C++ is a strongly hyped language.*&rdquo; &ndash; **Ron Sercely**.

&ldquo;*C(++) is a write-only, high-level assembler language.*&rdquo; &ndash; **Stefan Van Baelen**.

&ldquo;*C++ : Where friends have access to your private members.*&rdquo; &ndash; **Gavin Russell Baker**.

&ldquo;*C++ would make a decent teaching language if we could teach the ++ part without the C part.*&rdquo; &ndash; **Michael B. Feldman**.

&ldquo;*The great thing about Object Oriented code is that it can make small, simple problems look like large, complex ones.*&rdquo; &ndash; *Without author*.

&ldquo;*Hybrid ('half-assed') object languages like C++ are worst of all, as they unite the simplicity of Brainfuck with the inherent security of C and the speed of Perl.*&rdquo; &ndash; **Tony**.

---

[Zurück](../../Readme.md)

---
