#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(60);
}

void MainWindow::paintEvent(QPaintEvent *event)

{
    QPainter painter(this);
    for(int i = -4; i < 4;i++)
    {
        for(int j = -4; j < 4; j++)
        {
            if((i+j)%2==0)
            {
                painter.setBrush(Qt::white);
                painter.drawRect(_width/2+i*size,_height/2+j*size,size,size);
            }
            else
            {
                painter.setBrush(Qt::black);
                painter.drawRect(_width/2+i*size,_height/2+j*size,size,size);
            }
        }
    }
    int k = 0;
    for(int i = -4; i < 4; i++)
    {
        painter.setBrush(Qt::black);
        painter.drawText(_width/2+i*size+size/2,_height/2+4*size+size/3,QString(65+k));
        painter.drawText(_width/2+i*size+size/2,_height/2-4*size-size/6,QString(65+k));
        k++;
    }
    int n = 0;
    for(int i = -4; i < 4;i++)
    {
        painter.setBrush(Qt::black);
        painter.drawText(_width/2-5*size+size/2,_height/2+i*size+size/2,QString(56-n));
        painter.drawText(_width/2+4*size+size/3,_height/2+i*size+size/2,QString(56-n));
        n++;
    }

}

void MainWindow::update()
{
    QRect rect = contentsRect();
    _width = rect.width();
    _height = rect.height();
    repaint();
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QMessageBox msgBox;
    int x,y;
    x = event->x();
    y = event->y();

    if ((x < _width/2+(-4)*size) || (y >_height/2+4*size) || (x > _width/2+4*size) || ( y <_height/2+(-4)*size))
    {
        msgBox.setText("Клик вне шахматной доски");
    }
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
        msgBox.setText(QString(65+x+4)+QString(56-(y+4)));
    }

    msgBox.exec();
}
MainWindow::~MainWindow()
{
    delete ui;
}

