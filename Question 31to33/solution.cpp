#include <iostream>
#include <cmath>
#include <set>
#include <iterator>

using namespace std;

class Point
{
private:
  float x;
  float y;

public:
  Point()
  {
    x = 0;
    y = 0;
  }

  Point(float xval, float yval)
  {
    x = xval;
    y = yval;
  }

  float getX()
  {
    return x;
  }

  float getY()
  {
    return y;
  }

  void setX(float val)
  {
    x = val;
  }

  void setY(float val)
  {
    y = val;
  }

  void printPoint()
  {
    cout << "(" << x << ", " << y << ")";
  }

  float getDistance(Point p)
  {
    float xdif = x - p.getX();
    float ydif = y - p.getY();
    float distance = 0.0;
    xdif *= xdif;
    ydif *= ydif;
    distance = sqrt((xdif + ydif));
    return distance;
  }
};

class Segment
{
private:
  Point point1;
  Point point2;

public:
  Segment() : point1(), point2()
  {
  }

  Segment(Point p1, Point p2)
  {
    point1 = p1;
    point2 = p2;
  }

  float getLength()
  {
    return point1.getDistance(point2);
  }
};

class Shape
{
protected:
  Segment seg[10];
  int edgeCount;

public:
  Shape()
  {
    edgeCount = 0;

    for (int i = 0; i < 10; i++)
    {
      seg[i] = Segment();
    }
  }

  Shape(Segment *s, int ec)
  {
    edgeCount = ec;

    for (int i = 0; i < edgeCount; i++)
    {
      seg[i] = s[i];
    }
  }

  float getPerimeter()
  {
    float perimeter = 0;
    for (int i = 0; i < edgeCount; i++)
    {
      perimeter += seg[i].getLength();
    }
    return perimeter;
  }
};

class Rectangle : public Shape
{
public:
  Rectangle(Segment *s, int ec) : Shape(s, ec) {}

  float getArea()
  {
    set<float> sides;
    for (int i = 0; i < edgeCount; i++)
    {
      sides.insert(seg[i].getLength());
    }
    float area = 1;
    set<float>::iterator itr;
    for (itr = sides.begin(); itr != sides.end(); itr++)
    {
      area *= *itr;
    }
    return area;
  }
};

class Triangle : public Shape
{
public:
  Triangle(Segment *s, int ec) : Shape(s, ec) {}

  float getArea()
  {
    float area = 1;
    float sides[3];
    for (int i = 0; i < 3; i++)
    {
      sides[i] = seg[i].getLength();
    }

    float hypotenuse = sides[0];
    int location = 0;
    for (int i = 0; i < 3; i++)
    {
      if (sides[i] > hypotenuse)
      {
        hypotenuse = sides[i];
        location = i;
      }
    }

    for (int i = 0; i < 3; i++)
    {
      if (location != i)
      {
        area *= sides[i];
      }
    }

    area /= 2;
    return area;
  }
};

int main()
{

  return 0;
}