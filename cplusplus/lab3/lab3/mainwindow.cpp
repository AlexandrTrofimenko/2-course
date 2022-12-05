#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <rectangle.h>
#include <QPaintEvent>
#include <QBrush>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    rect.draw(&painter);
    rect1.draw(&painter);
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{

     k++;
     if (k==1 || k==3)
     {
         this->x=event->x();
         this->y=event->y();
     }
     else if(k==2 || k==4)
     {
         if(k==2)
         {
             rect = Rectangle(x,y,event->x(),event->y());
             qDebug("x1 = %d ,y1 = %d , x2 = %d , y2 = %d",x,y,event->x(),event->y());
         }
         else
         {
             rect1 = Rectangle(x,y,event->x(),event->y());
             qDebug("x1 = %d ,y1 = %d , x2 = %d , y2 = %d",x,y,event->x(),event->y());
             if(rect.intersect(rect1))
             {
                 rect.intersect(rect1);
                 qDebug("Пересекаются");
                 rect.intersection(rect1).square();
             }
             else
             {
                 qDebug("Не пересекаются");
                 rect.intersection(rect1).square();
             }
         }
     }
     repaint();
}


MainWindow::~MainWindow()
{
    delete ui;
}

