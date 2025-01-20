#include <iostream>
#include <cstring>
using namespace std;

class shape
{
protected:
    int dim1, dim2;
public:
    shape()
    {
        dim1 = dim2 = 0;
    }
    shape(int d)
    {
        dim1 = dim2 = d;
    }
    shape(int D1, int D2)
    {
        dim1 = D1;
        dim2 = D2;
    }

    void setDim1(int d)
    {
        dim1 = d;
    }

    void setDim2(int d)
    {
        dim2 = d;
    }

    int getDim1()
    {
        return dim1;
    }

    int getDim2()
    {
        return dim2;
    }

    virtual float Area() = 0;
};

class circle : public shape
{
public:
    circle() 
    {

    }
    circle(int c) : shape(c) 
    {

    }
    float Area()
    {
        return (3.14 * dim1 * dim2);
    }
};

class Triangle : public shape
{
public:
    Triangle() {}
    Triangle(int r, int r2) : shape(r, r2) {}
    float Area()
    {
        return (0.5 * dim1 * dim2);
    }
};

class Rectangle : public shape
{
public:
    Rectangle() {}
    Rectangle(int r, int r2) : shape(r, r2) {}
    float Area()
    {
        return (1.0 * dim1 * dim2);
    }
};

class Square : public Rectangle
{
public:
    Square() {}
    Square(int s) : Rectangle(s, s) {}
};

class GeoShape
{
    shape ** ptr;
    int size;
public:
    GeoShape(shape *shapes[] , int s)
    {
        size = s;
        ptr = new shape*[size];
        for(int i = 0 ; i < size ;i++)
        {
         ptr[i] = shapes[i]; 
        }
    }
    void TotalArea()
    {
        int sum = 0;
        for(int i = 0 ; i < size ;i++)
        {
            sum += ptr[i]->Area();
        }
        cout << "Total Area: " << sum << endl;
    }

    ~GeoShape(){
        delete [] ptr;
    }
};



int main()
{
    circle C(7);
    Rectangle R(5, 2);
    Rectangle R2(5, 2);
    Triangle T(10, 20);
    Square S(6);

    shape* shapes[] = { &C, &R, &T, &S , &R2 };

    GeoShape g(shapes, 5);

    g.TotalArea();
    return 0;
}