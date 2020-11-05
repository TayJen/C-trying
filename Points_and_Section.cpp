#include "Points_and_Section.h"
#include <iostream>

Point::Point() {
    printf("Point()\n");
    x = 0;
    y = 0;
}
Point::Point(int x_, int y_) {
    printf("Point(int x_, int y_)\n");
    x = x_;
    y = y_;
}
Point::Point(const Point& a) {
    printf("Point(const Point& a)\n");
    x = a.x;
    y = a.y;
}
Point::~Point() {
    printf("~Point(%d, %d)\n", x, y);
}
void Point::move(int dx, int dy) {
    x += dx;
    y += dy;
}
void Point::reset() {
    x = 0;
    y = 0;
}


Point3D::Point3D() : Point() {
    printf("Point3D()\n");
    z = 0;
}
Point3D::Point3D(int x_, int y_, int z_) : Point(x_, y_) {
    printf("Point3D(int x_, int y_, int z_)\n");
    z = z_;
}
Point3D::Point3D(const Point3D& a) : Point(a) {
    printf("Point3D(const Point3D& a)\n");
    z = a.z;
}
Point3D::~Point3D() {
    printf("~Point3D(%d, %d, %d)\n", x, y, z);
}
void Point3D::move(int dx, int dy, int dz) {
    Point::move(dx, dy);
    z += dz;
}


ColoredPoint3D::ColoredPoint3D() : Point3D() {
    printf("ColoredPoint3D()\n");
    color = 0;
}
ColoredPoint3D::ColoredPoint3D(int x_, int y_, int z_, int color_) : Point3D(x_, y_, z_) {
    printf("ColoredPoint3D(int x_, int y_, int z_, int color_)\n");
    color = color_;
}
ColoredPoint3D::ColoredPoint3D(const ColoredPoint3D& a) : Point3D(a) {
    printf("ColoredPoint3D(const ColoredPoint3D& a)\n");
    color = a.color;
}
ColoredPoint3D::~ColoredPoint3D() {
    printf("~ColoredPoint3D(%d, %d, %d, %d)\n", x, y, z, color);
}
void ColoredPoint3D::change_color(int color_) {
    color = color_;
}


Section::Section() {
    printf("Section()\n");
    p1 = new Point();
    p2 = new Point();
}
Section::Section(int x, int y, int x_, int y_) {
    printf("Section(int x, int y, int x_, int y_)\n");
    p1 = new Point(x, y);
    p2 = new Point(x_, y_);
}
Section::Section(const Section& a) {
    printf("Section(const Section& a)\n");
    p1 = new Point(*a.p1);
    p2 = new Point(*a.p2);
}
Section::~Section() {
    delete p1;
    delete p2;
    printf("~Section()\n");
}