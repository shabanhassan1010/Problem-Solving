#include <iostream>
#include <cstring>
#include <cstdlib> 
using namespace std;

class Point
{
    int x, y;
public:
    Point()
    {
        x = y = 0;
    }
    Point(int m)
    {
        x = y = m;
    }
    Point(int m, int n)
    {
        x = m;
        y = n;
    }
    void SetX(int m)
    {
        x = m;
    }
    void SetY(int n)
    {
        y = n;
    }
    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    }

    // Overload the << operator to print Point objects
    friend ostream& operator<<(ostream& os, const Point& pt);
};

ostream& operator<<(ostream& os, const Point& pt)
{
    os << "(" << pt.x << ", " << pt.y << ")";
    return os;
}

class Rectangle_C
{
    Point pt1, pt2;
    int length, width;
public:
    Rectangle_C(int x1, int y1, int x2, int y2) : pt1(x1, y1), pt2(x2, y2)
    {
        length = abs(x2 - x1);
        width = abs(y2 - y1);
    }

    void SetPt1(int x, int y)
    {
        pt1.SetX(x);
        pt1.SetY(y);
        length = abs(pt2.GetX() - x);
        width = abs(pt2.GetY() - y);
    }

    void SetPt2(int x, int y)
    {
        pt2.SetX(x);
        pt2.SetY(y);
        length = abs(x - pt1.GetX());
        width = abs(y - pt1.GetY());
    }

    Point GetPt1()
    {
        return pt1;
    }
    Point GetPt2()
    {
        return pt2;
    }
    int Area()
    {
        return (length * width);
    }
};

class Rectangle_A
{
    Point *pt1, *pt2;
    int length, width;
public:
    Rectangle_A()
    {
        pt1 = pt2 = NULL;
        length = width = 0;
    }

    Rectangle_A(Point *p1, Point *p2)
    {
        pt1 = p1;
        pt2 = p2;
        if (pt1 != NULL && pt2 != NULL)
        {
            length = abs(pt2->GetX() - pt1->GetX());
            width = abs(pt2->GetY() - pt1->GetY());
        }
        else
        {
            length = width = 0;
        }
    }

    void SetPt1(Point *pa)
    {
        pt1 = pa;
        if (pt1 != NULL && pt2 != NULL)
        {
            length = abs(pt2->GetX() - pt1->GetX());
            width = abs(pt2->GetY() - pt1->GetY());
        }
        else
        {
            length = width = 0;
        }
    }

    void SetPt2(Point *pb)
    {
        pt2 = pb;
        if (pt1 != NULL && pt2 != NULL)
        {
            length = abs(pt2->GetX() - pt1->GetX());
            width = abs(pt2->GetY() - pt1->GetY());
        }
        else
        {
            length = width = 0;
        }
    }

    Point GetPt1()
    {
        return *pt1;
    }

    Point GetPt2()
    {
        return *pt2;
    }

    int Area()
    {
        return (length * width);
    }
};

int main()
{
    Rectangle_C rect(20, 30, 70, 90);
    cout << "Area of Rectangle_C: " << rect.Area() << endl;

    Rectangle_A rectA;

    Point p1(7);
    Point p2(4, 9);
    Point p3(14);

    rectA.SetPt1(&p2);
    cout << "Point 1 in Rectangle_A: " << rectA.GetPt1() << endl;

    rectA.SetPt2(&p3);
    cout << "Point 2 in Rectangle_A: " << rectA.GetPt2() << endl;

    rectA.SetPt1(&p1);
    cout << "Updated Point 1 in Rectangle_A: " << rectA.GetPt1() << endl;

    return 0;
}





















