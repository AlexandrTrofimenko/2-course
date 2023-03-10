#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QCursor>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    centralWidget()->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    painter.setPen(pen);
    painter.drawRect(rectangle);

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(abs(event->x() -rectangle.topLeft().x()) < EPS && abs(event->y() - rectangle.topLeft().y())<EPS)
    {
        this->setCursor(Qt::SizeFDiagCursor);
        pos = 1;
    }
    else if(abs(event->x() - rectangle.topRight().x()) < EPS && abs(event->y()-rectangle.topRight().y()) < EPS)
    {
        this->setCursor(Qt::SizeBDiagCursor);
        pos = 2;

    }
    else if(abs(event->x() - rectangle.bottomLeft().x()) < EPS && abs(event->y()-rectangle.bottomLeft().y()) < EPS)
    {
        this->setCursor(Qt::SizeBDiagCursor);
        pos = 3;
    }
    else if(abs(event->x() - rectangle.bottomRight().x()) < EPS && abs(event->y()-rectangle.bottomRight().y()) < EPS)
    {
        this->setCursor(Qt::SizeFDiagCursor);
        pos = 4;
    }
    else if(event->x() > rectangle.left() && event->x() < rectangle.right() && abs(event->y() - rectangle.top()) < EPS)
    {
        this->setCursor(Qt::SizeVerCursor);
        pos = 5;
    }
    else if(rectangle.bottom() > event->y() && rectangle.top() < event->y() && abs(rectangle.left() - event->x())<EPS)
    {
        this->setCursor(Qt::SizeHorCursor);
        pos = 6;
    }
    else if(abs(event->y()-rectangle.bottom())<EPS && event->x() > rectangle.left() && event->x() < rectangle.right())
    {
        this->setCursor(Qt::SizeVerCursor);
        pos = 7;
    }
    else if(abs(event->x() - rectangle.right()) < EPS && rectangle.bottom() > event->y() && rectangle.top() < event->y())
    {
        this->setCursor(Qt::SizeHorCursor);
        pos = 8;
    }
    else
    {
        this->setCursor(Qt::ArrowCursor);
    }
    if (fl)
    {
        if(pos == 1)
        {
            this->setCursor(Qt::SizeFDiagCursor);
            rectangle.setTopLeft(QPoint(event->x(),event->y()));
        }
        if(pos == 2)
        {
             this->setCursor(Qt::SizeBDiagCursor);
             rectangle.setTopRight(QPoint(event->x(),event->y()));
        }
        if (pos == 3)
        {
            this->setCursor(Qt::SizeBDiagCursor);
            rectangle.setBottomLeft(QPoint(event->x(),event->y()));
        }
        if (pos == 4)
        {
            this->setCursor(Qt::SizeFDiagCursor);
            rectangle.setBottomRight(QPoint(event->x(),event->y()));
        }
        if(pos == 5)
        {
            this->setCursor(Qt::SizeVerCursor);
            rectangle.setTop(event->y());
        }
        if(pos == 6)
        {
            this->setCursor(Qt::SizeHorCursor);
            rectangle.setLeft(event->x());
        }
        if(pos == 7)
        {
            this->setCursor(Qt::SizeVerCursor);
            rectangle.setBottom(event->y());
        }
        if(pos == 8)
        {
            this->setCursor(Qt::SizeHorCursor);
            rectangle.setRight(event->x());
        }
    }

    repaint();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    fl = false;
    pos = 0;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(pos!=0)
        fl = true;
}
