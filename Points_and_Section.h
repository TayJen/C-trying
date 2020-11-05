#pragma once

class Point {
protected:
    int x, y;
public:
    Point();
    Point(int x_, int y_);
    Point(const Point& a);
    ~Point();
    void move(int dx, int dy);
    void reset();
};

class Point3D : public Point {
protected:
    int z;
public:
    Point3D();
    Point3D(int x_, int y_, int z_);
    Point3D(const Point3D& a);
    ~Point3D();
    void move(int dx, int dy, int dz);
};

class ColoredPoint3D : Point3D {
protected:
    int color;
public:
    ColoredPoint3D();
    ColoredPoint3D(int x_, int y_, int z_, int color_);
    ColoredPoint3D(const ColoredPoint3D& a);
    ~ColoredPoint3D();
    void change_color(int color_);
};

class Section {
protected:
    Point* p1;
    Point* p2;
public:
    Section();
    Section(int x, int y, int x_, int y_);
    Section(const Section& a);
    ~Section();
};