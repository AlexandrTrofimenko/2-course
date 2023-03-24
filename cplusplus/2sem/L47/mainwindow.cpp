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
}

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

   }
}


