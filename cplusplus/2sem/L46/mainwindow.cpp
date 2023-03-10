#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QVector>
#include <QString>
#include <QMessageBox>
#include <QtMath>
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
    QPen pen; pen.setWidth(3);painter.setPen(pen);
    for(int i = 1;i < 11;i++)
    {
        painter.drawEllipse(QPoint(_width/2,_height/2),r*i,r*i);
        painter.drawText(QPoint(_width/2 + (r*(i-1))+2,_height/2),QString().sprintf("%d",11-i));
    }
    for(int i = 0;i < 9 ;i++)
    {
        painter.drawText(QPoint(_width/2,_height/2+r*i+2*r-10),QString().sprintf("%d",9-i));
        painter.drawText(QPoint(_width/2 - (r*i)-2*r+10,_height/2),QString().sprintf("%d",9-i));
        painter.drawText(QPoint(_width/2,_height/2-r*i-2*r+10),QString().sprintf("%d",9-i));
    }

    pen.setColor(Qt::red);pen.setWidth(3);painter.setPen(pen);
    if(!dote.empty())
        for(int i = 0; i < dote.size();i++)
        {
            painter.drawEllipse(dote[i],2,2);
        }

    updater();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int score;QMessageBox msg;
    if(dote.size() < 5)
        dote.append(event->pos());
    for(int i = 0; i < dote.size();i++)
    {
        if(_width/)
            score+=10;
    }
    msg.setText(QString().sprintf("%d",score));
    if(dote.size() == 5)
        msg.exec();
    repaint();
}

void MainWindow::updater()
{
    QRect rect = contentsRect();
    _height = rect.height();
    _width = rect.width();
}

