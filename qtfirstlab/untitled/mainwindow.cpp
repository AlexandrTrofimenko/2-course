#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QBrush>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
  //  qDebug("hello world");
    QPainter painter(this);
 //   painter.drawLine(x-10,y,x+10,y);
 //   painter.drawLine(x,y-10,x,y+10);
    QBrush brush(Qt::darkRed); //QBrush brush(Qcolor(0,255,0,100));
    painter.setBrush(brush);
   if(bim)
   {
       bim->draw(&painter);
   }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->modifiers() & Qt::ControlModifier)
    {
        qDebug("Сntrl-click");
        if(bim && bim->contains(event->x(),event->y()))
        {
            qDebug("попал");
            delete bim;
            bim = nullptr;
        }
    }
    else if(event->modifiers() & Qt::ShiftModifier)
    {
        qDebug("Shift-click");
    }
    else if(event->modifiers() & Qt::AltModifier)
    {
        qDebug("Alt-click");
    }
    else
    {
        qDebug("click x=%d y=%d",event->x(),event->y(),40,-20,-20);
        bim = new Ball(event->x(),event->y(),40);
        bim->setDx(-5);
        bim->setDy(-5);
    }
      repaint();
}

void MainWindow::update()
{
    if(!bim)
    {
        return;
    }
    QRect rect = contentsRect();
    rect.width(); rect.height();

    if(bim->getX()-bim->getR()<=0) bim->setDx(-bim->getDx());
    if(bim->getY()-bim->getR()<= 0) bim->setDy(-bim->getDy());
    if(bim->getX()+bim->getR()>rect.width()) bim->setDx(-bim->getDx());
    if(bim->getY()+bim->getR()>rect.height()) bim->setDy(-bim->getDy());
    bim->setX(bim->getX()+bim->getDx());
    bim->setY(bim->getY()+bim->getDy());

    repaint();
}

