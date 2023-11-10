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
01: // interfaces
02: class IRectangle
03: {
04: public:
05:     virtual void draw() = 0;
06:     virtual void drawForeground() = 0;
07:     virtual void eraseBackground() = 0;
08: };
```

Abstrakte Basisklasse `Rectangle`:

#### Datei [*Main.cpp*](../MoreInheritance/Main.cpp):

```cpp
01: // abstract base class
02: class Rectangle : public IRectangle
03: {
04: protected:
05:     int m_x;
06:     int m_y;
07:     int m_width;
08:     int m_height;
09: 
10: public:
11:     Rectangle() 
12:         : Rectangle(0, 0, 0, 0)
13:     {}
14: 
15:     Rectangle(int x, int y, int width, int height)
16:         : m_x(x), m_y(y), m_width(width), m_height(height)
17:     {}
18: 
19:     virtual void eraseBackground() override final {
20:         std::cout << "  Rectangle::eraseBackground" << std::endl;
21:     }
22: 
23:     virtual void draw() override final {
24:         std::cout << "Rectangle::draw [x=" << m_x << ", y=" << m_y << "]" << std::endl;
25:         eraseBackground();
26:         drawForeground();
27:     }
28: };
```

Konkrete Klasse `ColoredRectangle`:

#### Datei [*Main.cpp*](../MoreInheritance/Main.cpp):

```cpp
01: class ColoredRectangle : public Rectangle
02: {
03: private:
04:     int m_color;  // representing some color model
05: 
06: public:
07:     ColoredRectangle()
08:         : ColoredRectangle(0, 0, 0, 0, 0)
09:     {}
10: 
11:     ColoredRectangle(int x, int y, int width, int height, int color)
12:         : Rectangle(x, y, width, height), m_color(123)
13:     {}
14: 
15:     void paint() {
16:         std::cout
17:             << "  ColoredRectangle::paint: width=" << m_width
18:             << ", height: " << m_height << std::endl;
19:     }
20: 
21:     virtual void drawForeground() override {
22:         std::cout << "  ColoredRectangle::drawForeground" << std::endl;
23:     }
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
Rectangle::draw [x=2, y=2]
  Rectangle::eraseBackground
  TransparentRectangle::drawForeground
Rectangle::draw [x=3, y=3]
  Rectangle::eraseBackground
  ColoredRectangle::drawForeground
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
