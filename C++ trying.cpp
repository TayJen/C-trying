#include <iostream>

class Point {
protected:
    int x, y;
public:
    Point() {
        printf("Point()\n");
        x = 0;
        y = 0;
    }

    Point(int x_, int y_) {
        printf("Point(int x_, int y_)\n");
        x = x_;
        y = y_;
    }

    Point(const Point& a) {
        printf("Point(const Point& a)\n");
        x = a.x;
        y = a.y;
    }

    ~Point() {
        printf("~Point(%d, %d)\n", x, y);
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    void reset();
};

void Point::reset() {
    x = 0;
    y = 0;
}

class Point3D : public Point {
protected:
    int z;
public:
    Point3D(): Point() {
        printf("Point3D()\n");
        z = 0;
    }

    Point3D(int x_, int y_, int z_): Point(x_, y_) {
        printf("Point3D(int x_, int y_, int z_)\n");
        z = z_;
    }

    Point3D(const Point3D& a): Point(a) {
        printf("Point3D(const Point3D& a)\n");
        z = a.z;
    }

    ~Point3D() {
        printf("~Point3D(%d, %d, %d)\n", x, y, z);
    }

    void move(int dx, int dy, int dz) {
        Point::move(dx, dy);
        z += dz;
    }
};

class ColoredPoint3D : Point3D {
protected:
    int color;
public:
    ColoredPoint3D() : Point3D() {
        printf("ColoredPoint3D()\n");
        color = 0;
    }

    ColoredPoint3D(int x_, int y_, int z_, int color_) : Point3D(x_, y_, z_) {
        printf("ColoredPoint3D(int x_, int y_, int z_, int color_)\n");
        color = color_;
    }

    ColoredPoint3D(const ColoredPoint3D& a) : Point3D(a) {
        printf("ColoredPoint3D(const ColoredPoint3D& a)\n");
        color = a.color;
    }

    ~ColoredPoint3D() {
        printf("~ColoredPoint3D(%d, %d, %d, %d)\n", x, y, z, color);
    }

    void change_color(int color_) {
        color = color_;
    }
};

class Section {
protected:
    Point* p1;
    Point* p2;
public:
    Section() {
        printf("Section()\n");
        p1 = new Point();
        p2 = new Point();
    }

    Section(int x, int y, int x_, int y_) {
        printf("Section(int x, int y, int x_, int y_)\n");
        p1 = new Point(x, y);
        p2 = new Point(x_, y_);
    }

    Section(const Section& a) {
        printf("Section(const Section& a)\n");
        p1 = new Point(*a.p1);
        p2 = new Point(*a.p2);
    }

    ~Section() {
        delete p1;
        delete p2;
        printf("~Section()\n");
    }
};

int main()
{
    printf("1.\n");
    {
        Point a;
        Point b(1, 2);
        Point c(b);
    }
    printf("\n\n2.\n");
    {
        Point* p1 = new Point();
        Point* p2 = new Point(3, 4);
        Point* p3 = new Point(*p2);

        delete p1;
        delete p2;
        delete p3;
    }
    printf("\n\n3.\n");
    {
        Point* p = new Point(5, 7);
        p->move(10, 10);
        delete p;
        printf("\n");
        Point* p_ = new Point(1, 2);
        p_->reset();
        delete p_;
    }
    printf("\n\n4.\n");
    {
        Point3D* p = new Point3D(11, 22, 30);
        delete p;
        printf("\n");
        Point* p_ = new Point3D(1, 2, 3);
        delete p_;
    }
    printf("\n\n5.\n");
    {
        Section* s = new Section();
        printf("\n");
        Section* s_ = new Section(*s);
        printf("\n");
        Section* s1 = new Section(13, 24, 11, 15);
        printf("\n");
        delete s;
        printf("\n");
        delete s_;
        printf("\n");
        delete s1;
    }
    printf("\n\n6.\n");
    {
        ColoredPoint3D* p1 = new ColoredPoint3D();
        printf("\n");
        ColoredPoint3D* p2 = new ColoredPoint3D(11, 20, 33, 45);
        printf("\n");
        delete p2;
        printf("\n");
        delete p1;
    }
}