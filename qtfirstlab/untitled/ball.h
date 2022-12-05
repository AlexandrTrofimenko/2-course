#ifndef BALL_H
#define BALL_H

class QPainter;
class Ball
{
public:
    Ball();
    Ball(int x,int y,int r,int dx = 0,int dy = 0);
    bool contains(int x,int y);
    void draw(QPainter *painter);
    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    int getDx() const;
    void setDx(int value);

    int getDy() const;
    void setDy(int value);

    int getR() const;
    void setR(int value);

private:
    int x,y,dx,dy,r;
};

#endif // BALL_H
