#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QVector>
#include <QMessageBox>
#include <QKeyEvent>
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
    if(!dote.empty())
        for(auto i: dote) {
            painter.drawEllipse(i,r,r);
        }
    painter.drawEllipse(shot,5,5);


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QMessageBox msg;
    if(event->modifiers() && Qt::ControlModifier) {
        shot = QPoint(event->pos());
    }
    else
        dote.append(QPoint(event->pos()));

    repaint();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

   if(event->key()==Qt::Key_Enter) {
        qDebug("pressed");
        for(int i = 0; i < dote.size();i++) {
            k = (dote[i].y() - shot.y()) / (dote[i].x() - shot.x());
            b = ((dote[i].x() - shot.y()) * (shot.x() - dote[i].y())) / (dote[i].x() - shot.x());
        }
   }

}

void MainWindow::kasatelnie()
{
    double X,Y;
    d = qSqrt(qPow(dote[i].x() - shot.x(),2) + qPow(dote[i].y() - shot.x(),2));
    double a = ((r*r) - (d/2*d/2)  +  d*d )/(2*d);
    double h = qSqrt(r*r-a*a);
    for(int i = 0; i < dote.size(); i++) {
        X = shot.x()+a*(dote[i].x() - shot.x())/d;
        Y = shot.y()+a*(dote[i].y() - shot.y())/d;

    }

}


