#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPoint>
#include <qmath.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QRect rect;
    rect = contentsRect();
    int width,height;
    width = rect.width();
    height = rect.height();
    QPainter painter(this);
    for(int i = 0; i < width; i+=20)
    {
        for(int j = 0; j < height; j+=20)
        {
            painter.drawRect(i,j,20,20);
            if((qPow(i-point.x(),2) + qPow(j-point.y(),2))<=qPow(rxy,2) && qPow(i+20-point.x(),2)+ qPow(j+20-point.y(),2)<=qPow(rxy,2) && (qPow(i-point.x(),2) + qPow(j+20-point.y(),2))<=qPow(rxy,2) && (qPow(i+20-point.x(),2)+qPow(j-point.y(),2))<=qPow(rxy,2))
            {
                painter.fillRect(i,j,20,20,Qt::blue);
            }
        }
    }
    if(fl)
        painter.drawEllipse(point,rxy,rxy);

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    srand(time(NULL));
    fl = true;
    rxy = rand()%50+100;
    point = QPoint(event->x(),event->y());
    repaint();
}

