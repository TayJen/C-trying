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

int main()
{
    {
        Point a;
        Point b(1, 2);
        Point c(b);
    }
    printf("\n\n");
    {
        Point* p1 = new Point();
        Point* p2 = new Point(3, 4);
        Point* p3 = new Point(*p2);

        delete p1;
        delete p2;
        delete p3;
    }
    printf("\n\n");
    {
        Point* p = new Point(5, 7);
        p->move(10, 10);
        delete p;
        printf("\n");
        Point* p_ = new Point(1, 2);
        p_->reset();
        delete p_;
    }
}