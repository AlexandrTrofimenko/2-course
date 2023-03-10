#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QVector>
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
    int r = 50;
    int counter = 0;
    QPainter painter(this);
    QPen pen;
    painter.setPen(pen);
    QVector <QColor> color;
    color.append(QColor(Qt::red));
    for(int i = 0; i < circle.size();i++)
    {
        pen.setColor(Qt::black);painter.setPen(pen);
        painter.drawEllipse(circle[i],r,r);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    circle.append(QPoint(event->x(),event->y()));
    repaint();
}

void MainWindow::intersect()
{
    QPen pen;
    int counter;
    for(int i = 0; i < geometry().width();i++)
    {
        for(int j = 0; j < geometry().height();j++)
        {
            counter = 0;
            for(int k = 0; k < circle.size();k++)
            {
                if((((circle[k].x() - i)*(circle[k].x() - i)) + ((circle[k].y()-j)*(circle[k].y()-j))) < r*r)
                {
                    counter++;
                }
            }
            if(counter == 2)
                pen.setColor(color[0]);

            if(counter == 3)
                pen.setColor(Qt::darkYellow);

            if(counter == 4)
                pen.setColor(Qt::yellow);

            if(counter == 5)
                pen.setColor(Qt::green);

            if(counter == 6)
                pen.setColor(Qt::darkMagenta);

            if(counter >= 7)
                pen.setColor(Qt::magenta);

            if(counter < 2 )
                pen.setColor(Qt::white);

            painter.setPen(pen);
            painter.drawPoint(i,j);
        }
}
