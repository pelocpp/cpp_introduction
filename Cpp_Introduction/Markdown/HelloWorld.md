# &ldquo;Hello World&rdquo;

[Zur�ck](Agenda.md)

---

## Erl�uterungen

C++ ist eine Programmiersprache, die den vom Entwickler geschriebenen Quelltext des Programms (*Editor*)
zun�chst mittels eines *�bersetzers* (*Compilers*)
in ein ausf�hrbares Programm (*Maschinencode*) umgewandelt.

Erst dann kann das Programm ausgef�hrt werden.

In der *Visual Studio* Entwicklungsumgebung sind alle notwendigen Werkzeuge (Editor, �bersetzer)
vorhanden bwz. integriert.

Den Quelltext f�r ein &ldquo;Hello World&rdquo; Programm sieht so aus:

#### Datei [*Main.cpp*](../HelloWorld/Main.cpp):

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello World" << std::endl;

    return 0;
}
```

Erstellen Sie mit der *Visual Studio* Entwicklungsumgebung ein C++&ndash;Projekt
und bringen Sie das Programm zum Laufen. Sie sollten dann folgende Ausgabe erhalten:

<img src="HelloWorld.png" width="600">

---

## Quellcode des Beispiels:

[*Main.cpp*](../HelloWorld/Main.cpp)

---

[Zur�ck](Agenda.md)

---

