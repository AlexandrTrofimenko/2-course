#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QVector>
#include <qmath.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    for(int i = size; i < 10*size;i+=size)
    {
        for(int j = size; j < 10*size; j+=size)
        {
            if(gcd(i,j)==1)
            {
                points.append(QPoint(i+size,j+size));
            }
        }
    }
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    for(int i = 0; i < 10 ;i++)
    {
        for (int j = 0; j < 10;j++)
        {
            painter.drawRect(QRect(i*size+size,j*size+size,size,size));
        }
    }
    QPen pen;
    pen.setWidth(5);pen.setColor(Qt::green);
    painter.setPen(pen);painter.drawEllipse(QPoint(size,size),2,2);
    pen.setColor(Qt::blue);painter.setPen(pen);
    for(int i = 0;i < points.size();i++)
    {
        painter.drawEllipse(points[i],2,2);
    }
}

int MainWindow::gcd(int a, int b)
{
    int sum = 0;
    for(int i=size;i<10*size;i+=size)
    {
        if(a%i==0 & b%i==0)
            sum++;
    }
    return sum;
}



