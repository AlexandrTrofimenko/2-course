#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QMessageBox>
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
    for(int i = -4; i < 4;i++)
    {
        for(int j = -4; j < 4;j++)
        {
            painter.setBrush((i+j)%2==0 ? Qt::white : Qt::black);
            painter.drawRect(_width/2+i*size,_height/2+j*size,size,size);

        }
    }
    int k = 0;
    for(int i = -4; i < 4; i++)
    {
        painter.setBrush(Qt::black);
        painter.drawText(_width/2+i*size+size/2,_height/2+4*size+size/3,QString(65+k));
        k++;
    }
    k = 0;
    for(int j = - 4; j < 4 ; j++)
    {
        painter.setBrush(Qt::black);
        painter.drawText(_width/2-5*size+size/2,_height/2+j*size+size/2,QString(56-k));
        k++;
    }
    update();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QMessageBox msg;
    int x,y;
    x = event->x();y=event->y();
    if ((x < _width/2+(-4)*size) || (y >_height/2+4*size) || (x > _width/2+4*size) || ( y <_height/2+(-4)*size))
            msg.setText("Клик вне шахматной доски");
    else
    {
        if(event->x()<_width/2)
            {
                x=(event->x() - _width/2-size)/size;
            }
            else
            {
                x=(event->x()- _width/2)/size;
            }
            y=(event->y() - _height/2)/size;
            if(event->y() < _height/2)
            {
                y=(event->y() - _height/2 - size)/size;
            }
            else
            {
                y=(event->y() - _height/2)/size;
            }
            msg.setText(QString(69+x)+QString(52-(y)));
    }
    msg.exec();
    repaint();
}

void MainWindow::update()
{
    QRect rect = contentsRect();
    _height = rect.height();
    _width = rect.width();

}

