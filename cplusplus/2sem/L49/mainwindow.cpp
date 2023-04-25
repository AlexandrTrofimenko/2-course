#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <ctime>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(NULL));
    for(int i = 0 ; i < k; i++) {
        for(int j = 0; j < n ;j++) {
            rects[i][j] = QRect(size*i,500+size*j,size,size);
        }
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            rectscolor[i][j] = mcolor[rand()%5];
        }
    }
    mainrectcolor = rectscolor[0][0];

    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(update()));
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QWidget::resize(300,500);

    painter.setBrush(mainrectcolor);
    painter.drawRect(mainrect);

    for(int i = 0 ; i < k; i++) {
        for(int j = 0; j < n ;j++) {
            painter.setBrush(rectscolor[i][j]);
            painter.drawRect(rects[i][j]);
        }
    }


}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->modifiers() && Qt::ControlModifier){
        mainrectcolor = mcolor[rand()%5];
    }


    mainrect.moveTo(rects[event->x()/size][0].x(),rects[0][0].y()-size);

    if(true_color()){
        count++;
        mainrect.setTop(mainrect.top() + size);
        mainrect.setBottom(mainrect.bottom() + size);
        for(int i = 0;i < k;i++) {
            for(int j = 0;j<n;j++){
                rects[i][j].setBottom(rects[i][j].bottom() + size);
                rects[i][j].setTop(rects[i][j].top() + size);

            }
        }
    }
    repaint();
}

bool MainWindow::true_color()
{
    int j = 0;
    while (mainrectcolor == rectscolor[mainrect.x() / size][j]) {
        j++;
        qSwap(rectscolor[mainrect.x() / size][j],rectscolor[mainrect.x() / size][j+1]);
    }
}


void MainWindow::update()
{
    if(gameover)
        return;
    if(rects[0][0].y() == 0 ){
      QMessageBox msg;
      gameover = true;
      msg.setText(QString::number(count));
      msg.exec();
      return;
    }
    mainrect.moveTop(mainrect.y()-5);
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            rects[i][j].moveTop(rects[i][j].y()-5);
        }
    }
    repaint();
}
