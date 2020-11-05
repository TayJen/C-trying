#include <iostream>
#include "Points_and_Section.h"

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