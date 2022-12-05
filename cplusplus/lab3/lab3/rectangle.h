#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QPainter>
class Rectangle
{
public:
    Rectangle();
    Rectangle(int x1, int y1,int x2,int y2);
    void draw(QPainter *painter);
    bool contains(int x, int y);
    bool intersect(Rectangle rect);
    Rectangle intersection(Rectangle rect);
    void square();
    int getWidth()
    {
        return x2-x1;
    }
    int getHeight()
    {
        return y2-y1;
    }

    int getX1() const;
    void setX1(int value);

    int getY1() const;
    void setY1(int value);

    int getX2() const;
    void setX2(int value);

    int getY2() const;
    void setY2(int value);

    private:
        int x1, y1, x2, y2;

    };
#endif // RECTANGLE_H
