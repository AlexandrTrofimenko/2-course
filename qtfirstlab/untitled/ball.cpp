#include "ball.h"
#include <QPainter>
Ball::Ball()
    :Ball(0,0,0,0,0) // инициализация из конструктора (конструктор из конструктора)
{

}
Ball::Ball(int x,int y,int r,int dx,int dy)
    :x(x),y(y),dx(0),dy(0),r(r)  // списочная инициализация
{

}

bool Ball::contains(int x, int y)
{
    int dx = this->x - x, dx2 = dx*dx;
    int dy = this->y - y,dy2=dy*dy;
    return ((dx2+dy2) <= r*r);
}

int Ball::getX() const
{
    return x;
}

void Ball::setX(int value)
{
    x = value;
}

int Ball::getY() const
{
    return y;
}

void Ball::setY(int value)
{
    y = value;
}

int Ball::getDx() const
{
    return dx;
}

void Ball::setDx(int value)
{
    dx = value;
}

int Ball::getDy() const
{
    return dy;
}

void Ball::setDy(int value)
{
    dy = value;
}

int Ball::getR() const
{
    return r;
}

void Ball::setR(int value)
{
    r = value;
}


void Ball::draw(QPainter *painter)
{
    painter->drawEllipse(x-r,y-r,r*2,r*2);
}
