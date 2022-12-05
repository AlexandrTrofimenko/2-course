#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "point.h"
#include <QMouseEvent>
#include <QPainter>

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
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug("click x=%d, y=%d",event->x(),event->y());
    dote = new Point(event->x(),event->y());
    if (f || m==0)
    {
        massdote[m]=dote;
    }
    if (m>=10 && f)
    {
        delete massdote[0];
        massdote[0] = nullptr;
        for(int j=0;j<10;j++)
        {
            massdote[j]=massdote[j+1];
        }
        m=9;
    }

    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    for (int i = 0; i <= m; i++)
        {
        if(massdote[i])
            {
            massdote[i]->draw(&painter);
            }
        }
    for (int i = 0; i < m; i++)
    {
        if(massdote[i] && massdote[i+1])
        {
            painter.drawLine(massdote[i]->getX(),massdote[i]->getY(),massdote[i+1]->getX(),massdote[i+1]->getY());
        }
    }

    if(massdote[m] && m<10)
    {
        m++;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    dote = new Point(event->x(),event->y());
    for(int i=0; i<m; i++)
    {
        if(massdote[i]->distance(*dote) <= 8*8)
        {
            f = false;
            massdote[i]->setX(event->x());
            massdote[i]->setY(event->y());
            repaint();
        }
    }
    delete(dote);
    dote=nullptr;
}

