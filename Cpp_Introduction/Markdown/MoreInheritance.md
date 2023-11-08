# Vererbung - weiterführende Themen


[Zurück](Agenda.md)

---

## Erläuterungen

Wir betrachten die Konzepte

  * Überschreiben von Methoden
  * Schlüsselwörter `virtual`, `override` und `final`
  * Polymorphismus
  * Schnittstellekonzept (Interface)
  * Kontrakt mit mehreren Schnittstellen
  * Abstrakten Basisklasse
  * Unterschied Schnittstelle versus abstrakte Basisklasse

an einem Beispiel:

Schnittstellenklasse `IRectangle`:

#### Datei [*Main.cpp*](../MoreInheritance/Main.cpp):

```cpp
01: class IRectangle
02: {
03: public:
04:     virtual void draw() = 0;
05:     virtual void drawForeground() = 0;
06:     virtual void drawBorder() = 0;
07:     virtual void eraseBackground() = 0;
08: };
```

Abstrakte Basisklasse `Rectangle`:

#### Datei [*Main.cpp*](../MoreInheritance/Main.cpp):

```cpp
01: class Rectangle : public IRectangle
02: {
03: protected:
04:     int m_x;
05:     int m_y;
06:     int m_width;
07:     int m_height;
08: 
09: public:
10:     Rectangle() 
11:         : Rectangle(0, 0, 0, 0)
12:     {}
13: 
14:     Rectangle(int x, int y, int width, int height)
15:         : m_x(x), m_y(y), m_width(width), m_height(height)
16:     {}
17: 
18:     virtual void drawBorder() override final {
19:         std::cout
20:             << "  Rectangle::drawBorder: width=" << m_width
21:             << ", height: " << m_height << std::endl;
22:     }
23: 
24:     virtual void eraseBackground() override final {
25:         std::cout << "  Rectangle::eraseBackground" << std::endl;
26:     }
27: 
28:     virtual void draw() override final {
29:         std::cout << "Rectangle::draw [x=" << m_x << ", y=" << m_y << "]" << std::endl;
30:         eraseBackground();
31:         drawForeground();
32:         drawBorder();
33:     }
34: };
```

Konkrete Klasse `ColoredRectangle`:

#### Datei [*Main.cpp*](../MoreInheritance/Main.cpp):

```cpp
01: class ColoredRectangle : public Rectangle
02: {
03: public:
04:     ColoredRectangle()
05:         : ColoredRectangle(0, 0, 0, 0, 0.0)
06:     {}
07: 
08:     ColoredRectangle(int x, int y, int width, int height, double color)
09:         : Rectangle(x, y, width, height), m_hsv(123)
10:     {}
11: 
12:     void paint() {
13:         std::cout
14:             << "  ColoredRectangle::paint: width=" << m_width
15:             << ", height: " << m_height << std::endl;
16:     }
17: 
18:     virtual void drawForeground() override {
19:         std::cout << "  ColoredRectangle::drawForeground" << std::endl;
20:     }
21: 
22: private:
23:     double m_hsv;  // hue, saturation, value
24: };
```

Testrahmen:

#### Datei [*Main.cpp*](../MoreInheritance/Main.cpp) - Testrahmen:

```cpp
01: void testMoreInheritance()
02: {
03:     using namespace MoreInheritance;
04: 
05:     ColoredRectangle cr1(1, 1, 20, 30, 255);
06:     TransparentRectangle tr(2, 2, 30, 40, 111.0);
07:     ColoredRectangle cr3(3, 3, 50, 60, 127);
08: 
09:     IRectangle* rects[]{ &cr1, &tr, &cr3 };
10: 
11:     for (int i = 0; i < 3; ++i) {
12:         rects[i]->draw();
13:     }
14: }
```

*Ausgabe*:


```
Rectangle::draw [x=1, y=1]
  Rectangle::eraseBackground
  ColoredRectangle::drawForeground
  Rectangle::drawBorder: width=20, height: 30
Rectangle::draw [x=2, y=2]
  Rectangle::eraseBackground
  TransparentRectangle::drawForeground
  Rectangle::drawBorder: width=30, height: 40
Rectangle::draw [x=3, y=3]
  Rectangle::eraseBackground
  ColoredRectangle::drawForeground
  Rectangle::drawBorder: width=50, height: 60
```

---

## Quellcode des Beispiels:

[*Main.cpp*](../MoreInheritance/Main.cpp)

---


## Übungen

TBD: Rectangle

---


[Zurück](Agenda.md)

---
