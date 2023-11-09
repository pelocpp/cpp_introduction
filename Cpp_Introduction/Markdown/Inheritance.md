# Vererbung


[Zurück](Agenda.md)

---

## Erläuterungen

Wir betrachten die Konzepte

  * Entwicklung einer Hierarchie von Klassen
  * Konstruktoren von abgeleiteten Klassen und Basisklassen
  * Verwendung von `public`, `protected` und `private`
  * Überschreiben von Methoden (hier: Methode `draw`)

an einem Beispiel:

Basisklasse `Rectangle`:

#### Datei [*Main.cpp*](../Inheritance/Main.cpp) - Testrahmen:

```cpp
01: class Rectangle
02: {
03: private:
04:     int m_x;
05:     int m_y;
06:     int m_width;
07:     int m_height;
08: 
09: public:
10:     // c'tor(s)
11:     Rectangle() : Rectangle(0, 0, 0, 0) {}
12: 
13:     Rectangle(int x, int y, int width, int height)
14:         : m_x(x), m_y(y), m_width(width), m_height(height)
15:     {}
16: 
17:     // getter
18:     int getX() { return m_x; }
19:     int getY() { return m_y; }
20:     int getWidth() { return m_width; }
21:     int getHeight() { return m_height; }
22: 
23:     // public interface
24:     void eraseBackground()
25:     {
26:         std::cout << "  Rectangle::eraseBackground" << std::endl;
27:     }
28: 
29:     void draw() {
30: 
31:         std::cout
32:             << "Rectangle::draw [x=" << getX()
33:             << ", y=" << getY() << "]" << std::endl;
34: 
35:         eraseBackground();
36:     }
37: };
```

Abgeleitete Klasse `ColoredRectangle`:

#### Datei [*Main.cpp*](../Inheritance/Main.cpp) - Testrahmen:

```cpp
01: class ColoredRectangle : public Rectangle
02: {
03: private:
04:     double m_hsv;  // hue, saturation, value
05: 
06: public:
07:     // c'tor(s)
08:     ColoredRectangle() : ColoredRectangle(0, 0, 0, 0, 0.0) {}
09: 
10:     ColoredRectangle(int x, int y, int width, int height, double color)
11:         : Rectangle(x, y, width, height), m_hsv(123)
12:     {}
13: };
```

Abgeleitete Klasse `TransparentRectangle`:

#### Datei [*Main.cpp*](../Inheritance/Main.cpp) - Testrahmen:

```cpp
class TransparentRectangle : public Rectangle
{
private:
    int m_opaque;  // transparency value

public:
    // c'tor(s)
    TransparentRectangle() 
        : TransparentRectangle(0, 0, 0, 0, 0.0)
    {}

    TransparentRectangle(int x, int y, int width, int height, double color)
        : Rectangle(x, y, width, height), m_opaque(123) 
    {}
};
```

Testrahmen:

#### Datei [*Main.cpp*](../Inheritance/Main.cpp) - Testrahmen:

```cpp
01: void testInheritance()
02: {
03:     ColoredRectangle cr(1, 1, 20, 30, 255);
04:     TransparentRectangle tr(2, 2, 30, 40, 111.0);
05: 
06:     cr.draw();
07:     tr.draw();
08: }
```

*Ausgabe*:


```
Rectangle::draw [x=1, y=1]
  Rectangle::eraseBackground
Rectangle::draw [x=2, y=2]
  Rectangle::eraseBackground
```

## Weiterarbeit an diesem Beispiel

Es wird von den beiden Klassen `ColoredRectangle` und `TransparentRectangle` 
von der Vaterklasse `Rectangle` geerbt:

  * Was ist der Nachteil dieser Vorhehensweise?
  * Zeigen Sie auf, wie man diese Methode in den Klassen besser realisieren kann.

Eine verbesserte Lösung finden Sie im Quellcode zu diesem Abschnitt
im Namanesraum `InheritanceImproved` vor.

---

## Quellcode des Beispiels:

[*Main.cpp*](../Inheritance/Main.cpp)

---


## Übungen

TBD: BAnk konto


---


[Zurück](Agenda.md)

---
