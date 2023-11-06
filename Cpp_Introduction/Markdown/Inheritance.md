# Vererbung


[Zurück](Agenda.md)

---

## Erläuterungen

Wir betrachten die Konzepte

  * Entwicklung einer Hierarchie von Klassen
  * Konstruktoren von abgeleiteten Klassen und Basisklassen
  * Verwendung von `public`, `protected` und `private`

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
24:     void drawBorder()
25:     {
26:         std::cout
27:             << "  Rectangle::drawBorder: width=" << m_width
28:             << ", height: " << m_height << std::endl;
29:     }
30: 
31:     void eraseBackground()
32:     {
33:         std::cout << "  Rectangle::eraseBackground" << std::endl;
34:     }
35: };
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
13: 
14:     // public interface
15:     void draw() {
16: 
17:         eraseBackground();
18:         drawBorder();
19:         std::cout
20:             << "ColoredRectangle::draw [x=" << getX()
21:             << ", y=" << getY() << "]" << std::endl;
22:     }
23: };
```

Abgeleitete Klasse `TransparentRectangle`:

#### Datei [*Main.cpp*](../Inheritance/Main.cpp) - Testrahmen:

```cpp
01: class TransparentRectangle : public Rectangle
02: {
03: private:
04:     int m_opaque;  // transparency value
05: 
06: public:
07:     // c'tor(s)
08:     TransparentRectangle() 
09:         : TransparentRectangle(0, 0, 0, 0, 0.0)
10:     {}
11: 
12:     TransparentRectangle(int x, int y, int width, int height, double color)
13:         : Rectangle(x, y, width, height), m_opaque(123) 
14:     {}
15: 
16:     // public interface
17:     void draw()
18:     {
19:         eraseBackground();
20:         drawBorder();
21: 
22:         std::cout
23:             << "TransparentRectangle::draw [x=" 
24:             << getX() << ", y=" << getY() << "]" << std::endl;
25:     }
26: };
```


Testrahmen:

#### Datei [*Main.cpp*](../Inheritance/Main.cpp) - Testrahmen:

```cpp
01: void testInheritance()
02: {
03:     using namespace Inheritance;
04: 
05:     ColoredRectangle cr(1, 1, 20, 30, 255);
06:     TransparentRectangle tr(2, 2, 30, 40, 111.0);
07: 
08:     cr.draw();
09:     tr.draw();
10: }
```


*Ausgabe*:


```
  Rectangle::eraseBackground
  Rectangle::drawBorder: width=20, height: 30
ColoredRectangle::draw [x=1, y=1]
  Rectangle::eraseBackground
  Rectangle::drawBorder: width=30, height: 40
TransparentRectangle::draw [x=2, y=2]
```



---

## Quellcode des Beispiels:

[*Main.cpp*](../Inheritance/Main.cpp)

---


## Übungen

TBD: BAnk konto


---


[Zurück](Agenda.md)

---
