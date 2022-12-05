#include "rectangle.h"
#include <QPainter>
Rectangle::Rectangle()
    :Rectangle(0,0,0,0)
{

}
Rectangle::Rectangle(int x1,int y1,int x2, int y2)
{
    this->x1=x1 < x2 ? x1:x2;
    this->y1=y1 < y2 ? y1:y2;
    this->x2=x2 > x1 ? x2:x1;
    this->y2=y2 > y1 ? y2:y1;
}

void Rectangle::draw(QPainter *painter)
{
    painter->drawRect(x1,y1, getWidth(),getHeight());
}


int Rectangle::getX1() const
{
    return x1;
}

void Rectangle::setX1(int value)
{
    x1 = value;
}

int Rectangle::getY1() const
{
    return y1;
}

void Rectangle::setY1(int value)
{
    y1 = value;
}

int Rectangle::getX2() const
{
    return x2;
}

void Rectangle::setX2(int value)
{
    x2 = value;
}

int Rectangle::getY2() const
{
    return y2;
}

void Rectangle::setY2(int value)
{
    y2 = value;
}

bool Rectangle::contains(int x, int y)
{
    if(x<x1) return false;
    if(x>x2) return false;
    if(y<y1) return false;
    if(y>y2) return false;
    return true;
}

bool Rectangle::intersect(Rectangle rect)
{
    if(rect.x2<x1) return false;
    if(rect.x1>x2) return false;
    if(rect.y2<y1) return false;
    if(rect.y1>y2) return false;
    return true;
}

Rectangle Rectangle::intersection(Rectangle rect)
{
    int xl,xr,yl,yr;
    Rectangle r;
    if(!intersect(rect)) return r;
    xl=x1 > rect.x1 ? x1: rect.x1;
    xr=x2 > rect.x2 ? x2: rect.x2;
    yl=y1 > rect.y1 ? y1: rect.y1;
    yr=y2 > rect.y2 ? y2: rect.y2;
    return Rectangle(xl,yl,xr,yr);
}




