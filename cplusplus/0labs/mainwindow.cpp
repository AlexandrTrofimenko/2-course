#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QMoveEvent>
#include <QVector>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    x = event->x();
    y = event->y();
    x1 = event->x();
    y1 = event->y();
    masspoint.append(QPoint(event->x(),event->y()));

    repaint();
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    pen.setWidth(2);
    pen.setStyle(Qt::DashDotLine);
    painter.setPen(pen);
    if(x>0)
    {
        painter.drawRect(QRect(x,y,x1-x,y1-y));
    }
    if(f)
    {
        painter.drawEllipse(masspoint,3,3);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    x1 = event->x();
    y1 = event->y();
    repaint();
}


MainWindow::~MainWindow()
{
    delete ui;
}
