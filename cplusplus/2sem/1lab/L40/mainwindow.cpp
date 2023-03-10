#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPoint>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QVector>
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
    QPainter painter(this);
    QPen pen;
    // Провайдер
    pen.setWidth(6);
    pen.setColor(Qt::blue);
    painter.setPen(pen);
    painter.drawPoint(dote);
    // Остальные поросята
    pen.setColor(Qt::black);
    painter.setPen(pen);
    for(int i = 0; i < massdote.size();i++)
    {
        painter.drawPoint(massdote[i]);
    }
    // Интернет
    if(Enter)
    {
        pen.setWidth(2);
        pen.setColor(Qt::blue);
        painter.setPen(pen);
        painter.drawLine(dote,massdote[kIter]);
        for(int i = 0; i < massdote.size();i++)
        {
            pen.setColor(Qt::black);painter.setPen(pen);
            painter.drawLine(massdote[kIter],massdote[i]);
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->modifiers() & Qt::ControlModifier)
    {
        dote = QPoint(event->x(),event->y());
    }
    else
    {
        massdote.append(QPoint(event->x(),event->y()));
    }
    repaint();
}

int MainWindow::distance(QPoint point1,QPoint point2)
{
    double r = 0;
    int x,y,x1,y1;
    x = point1.x(); y=point1.y();
    x1 = point2.x(); y1=point2.y();
    r = sqrt(qPow(x-x1,2) + qPow(y-y1,2));
    return r;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter)
    {
        Enter = true;
        for(int j = 0; j < massdote.size(); j++)
        {
            int sum = 0;
            for(int i = 0; i < massdote.size(); i++)
            {
                if(j!=i)
                {
                    sum+=distance(massdote[j],massdote[i]);
                }
            }
            if(sum<sumMin)
            {
                sumMin = sum;
                kIter = j;
            }
        }
    }
    repaint();
}


