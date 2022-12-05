#include "point.h"
#include <QPainter>

Point::Point(int x, int y)
    :x(x),y(y)
{

}

void Point::draw(QPainter *painter)
{
    painter->drawLine(x-3,y,x+3,y);
    painter->drawLine(x,y-3,x,y+3);
}

int Point::getX() const
{
    return x;
}

void Point::setX(int value)
{
    x = value;
}

int Point::getY() const
{
    return y;
}

void Point::setY(int value)
{
    y = value;
}

int Point::distance(const Point &point)
{
    int dx = this->x - point.getX(), dy = this->y - point.getY();
    return(dx*dx+dy*dy);
}

