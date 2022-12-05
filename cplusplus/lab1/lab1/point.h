#ifndef POINT_H
#define POINT_H

class QPainter;
class Point
{
public:
    Point(int x,int y);
    void draw(QPainter *painter);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    int distance(const Point &point);

private:
    int x,y;
};

#endif // POINT_H
