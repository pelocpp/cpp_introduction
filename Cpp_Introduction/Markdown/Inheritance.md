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
18:     int getX() const { return m_x; }
19:     int getY() const { return m_y; }
20:     int getWidth() const { return m_width; }
21:     int getHeight() const { return m_height; }
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
32:             << "Rectangle::draw [x=" << m_x
33:             << ", y=" << m_y << "]" << std::endl;
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
04:     int m_color;   // representing some color model
05: 
06: public:
07:     // c'tor(s)
08:     ColoredRectangle() : ColoredRectangle(0, 0, 0, 0, 0) {}
09: 
10:     ColoredRectangle(int x, int y, int width, int height, int color)
11:         : Rectangle(x, y, width, height), m_color(123)
12:     {}
13: 
14:     void draw() {
15: 
16:         Rectangle::draw();
17: 
18:         std::cout
19:             << "  ColoredRectangle::draw [color = " << m_color << "]" << std::endl;
20:     }
21: };
```

Abgeleitete Klasse `TransparentRectangle`:

#### Datei [*Main.cpp*](../Inheritance/Main.cpp) - Testrahmen:

```cpp
01: class TransparentRectangle : public Rectangle
02: {
03: private:
04:     double m_opacity;  // representing some transparency model
05: 
06: public:
07:     // c'tor(s)
08:     TransparentRectangle()
09:         : TransparentRectangle(0, 0, 0, 0, 0.0)
10:     {}
11: 
12:     TransparentRectangle(int x, int y, int width, int height, double opacity)
13:         : Rectangle(x, y, width, height), m_opacity(123.45)
14:     {}
15: 
16:     void draw() {
17: 
18:         Rectangle::draw();
19: 
20:         std::cout
21:             << "  ColoredRectangle::draw [opacity = " << m_opacity << "]" << std::endl;
22:     }
23: };
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
  ColoredRectangle::draw [color = 123]
Rectangle::draw [x=2, y=2]
  Rectangle::eraseBackground
  ColoredRectangle::draw [opacity = 123.45]
```

## Hinweise zu diesem Beispiel

Es wird in den beiden Klassen `ColoredRectangle` und `TransparentRectangle` 
von der Vaterklasse `Rectangle` eine Methode `draw` geerbt:

  * Betrachten Sie, wie diese Methode in den Klassen `ColoredRectangle` und `TransparentRectangle`
    &bdquo;verbessert&rdquo; realisiert wird.

---

## Quellcode des Beispiels:

[*Main.cpp*](../Inheritance/Main.cpp)

---

[Zurück](Agenda.md)

---
