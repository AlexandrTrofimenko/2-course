#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>
#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    for(int i = 0; i < 6;i++) {
        button[i] = new QPushButton(this);
        button[i]->setGeometry(size*i+size*i+size,540,size,size);
        QString qss = QString("background-color: %1").arg(mcolor[i].name());
        button[i]->setStyleSheet(qss);
    }

    connect(button[0],&QPushButton::pressed,this,&MainWindow::clickedButt1);
    connect(button[1],&QPushButton::pressed,this,&MainWindow::clickedButt2);
    connect(button[2],&QPushButton::pressed,this,&MainWindow::clickedButt3);
    connect(button[3],&QPushButton::pressed,this,&MainWindow::clickedButt4);
    connect(button[4],&QPushButton::pressed,this,&MainWindow::clickedButt5);
    connect(button[5],&QPushButton::pressed,this,&MainWindow::clickedButt6);

    srand(time(NULL));
    QVector<QColor> color(12,Qt::white);
    QVector<QVector<QColor>> _vecColor(12,color);
    for(int i = 0 ; i < _vecColor.size() ; i++) {
        for(int j = 0; j < _vecColor[i].size(); j++) {
            _vecColor[i][j] = mcolor[rand()%6];
        }
    }
    vecColor = _vecColor;
    vecPair.push_back(QPair<int,int>(0,0));
    vecPair = neightbours(vecPair);
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
    for(int i = 0;i < 6;i++){
        disconnect(button[i]);
        button[i]->deleteLater();
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    srand(time(NULL));
    QPainter painter(this);
    for(int i = 0; i < 12 ; i++) {
        for(int j = 0; j < 12; j++) {
            painter.setBrush(vecColor[i][j]);
            painter.drawRect(QRect(i*size+size,j*size+size,size,size));
        }
    }
    painter.drawText(540,40,QString().sprintf("%d",counter));
}

void MainWindow::Mix(QColor color)
{
    qDebug() << color;
    QVector<QPair<int,int>> vecPair2;
    QVector<QPair<int,int>> vecPair3;
    QVector<QPair<int,int>> vecPair4;
    for(int i = 0; i < vecPair.size();i++) {
        QPair<int,int> intI_J = vecPair[i];
        if(intI_J.second + 1 < 12) {
            if(vecPair.indexOf(QPair<int,int>(intI_J.first,intI_J.second + 1)) == -1) {
                if(vecColor[intI_J.first][intI_J.second + 1] == color) {
                    if (vecPair2.indexOf(QPair<int,int>(intI_J.first,intI_J.second + 1)) == -1){
                        vecPair2.append(QPair<int,int>(intI_J.first,intI_J.second + 1));
                    }
                }
            }
        }
        if(intI_J.first + 1 < 12) {
            if(vecPair.indexOf(QPair<int,int>(intI_J.first +1 ,intI_J.second)) == -1) {
                if(vecColor[intI_J.first + 1][intI_J.second] == color) {
                    if (vecPair2.indexOf(QPair<int,int>(intI_J.first + 1,intI_J.second)) == -1){
                        vecPair2.append(QPair<int,int>(intI_J.first + 1,intI_J.second));
                    }
                }
            }
        }
        if(intI_J.second - 1 > 0) {
            if(vecPair.indexOf(QPair<int,int>(intI_J.first,intI_J.second - 1)) == -1) {
                if(vecColor[intI_J.first][intI_J.second - 1] == color) {
                    if (vecPair2.indexOf(QPair<int,int>(intI_J.first,intI_J.second - 1)) == -1){
                            vecPair2.append(QPair<int,int>(intI_J.first,intI_J.second - 1));
                    }
                }
            }
        }
        if(intI_J.first - 1 > 0 ) {
            if(vecPair.indexOf(QPair<int,int>(intI_J.first - 1 ,intI_J.second)) == -1) {
                if(vecColor[intI_J.first - 1][intI_J.second] == color) {
                    if (vecPair2.indexOf(QPair<int,int>(intI_J.first - 1,intI_J.second)) == -1) {
                            vecPair2.append(QPair<int,int>(intI_J.first - 1,intI_J.second));
                    }
                }
            }
        }
    }
    for(int i = 0; i < vecPair.size(); i ++) {
        QPair<int,int> intI_J = vecPair[i];
        vecColor[intI_J.first][intI_J.second] = color;
    }

    for(auto i:vecPair2) {
        vecPair3.clear();
        vecPair3.append(i);
        vecPair3 = neightbours(vecPair3);

        for(auto j:vecPair3) {
            if(vecPair4.indexOf(j) == -1) {
                vecPair4.append(j);
            }
        }
    }
    vecPair.append(vecPair4);  
    if (vecPair.size() == 12 * 12)
        qDebug() << "fsolo";
    repaint();
}
QVector<QPair<int,int>> MainWindow::neightbours(QVector<QPair<int,int>> pairVec)
{
    QVector<QPair<int,int>> pairVec2 = pairVec;
    QPair<int,int> _intI_J = pairVec[pairVec.size()-1];
    QColor color = vecColor[pairVec[0].first][pairVec[0].second];
    if(_intI_J.second + 1 < 12) {
        if(pairVec.indexOf(QPair<int,int>(_intI_J.first,_intI_J.second + 1)) == -1) {
            if(vecColor[_intI_J.first][_intI_J.second + 1] == color
                    && vecPair.indexOf(QPair<int,int>(_intI_J.first,_intI_J.second + 1)) == -1) {
                pairVec2.append(QPair<int,int>(_intI_J.first,_intI_J.second + 1));
                pairVec2 = neightbours(pairVec2);
            }
        }
    }
    if(_intI_J.first + 1 < 12) {
        if(pairVec.indexOf(QPair<int,int>(_intI_J.first +1 ,_intI_J.second)) == -1) {
            if(vecColor[_intI_J.first + 1][_intI_J.second] == color
                    && vecPair.indexOf(QPair<int,int>(_intI_J.first + 1,_intI_J.second)) == -1) {
                pairVec2.append(QPair<int,int>(_intI_J.first + 1,_intI_J.second));
                pairVec2 = neightbours(pairVec2);
            }
        }
    }
    if(_intI_J.second - 1 > 0) {
        if(pairVec.indexOf(QPair<int,int>(_intI_J.first,_intI_J.second - 1)) == -1) {
            if(vecColor[_intI_J.first][_intI_J.second - 1] == color
                    && vecPair.indexOf(QPair<int,int>(_intI_J.first,_intI_J.second - 1)) == -1) {
                pairVec2.append(QPair<int,int>(_intI_J.first,_intI_J.second - 1));
                pairVec2 = neightbours(pairVec2);
            }
        }
    }
    if(_intI_J.first - 1 > 0 ) {
        if(pairVec.indexOf(QPair<int,int>(_intI_J.first - 1 ,_intI_J.second)) == -1) {
            if(vecColor[_intI_J.first - 1][_intI_J.second] == color
                    && vecPair.indexOf(QPair<int,int>(_intI_J.first - 1,_intI_J.second)) == -1) {
                pairVec2.append(QPair<int,int>(_intI_J.first - 1,_intI_J.second));
                pairVec2 = neightbours(pairVec2);
            }
        }
    }
    return pairVec2;
}
void MainWindow::clickedButt1()
{
    Mix(mcolor[0]);
    counter++;
}
void MainWindow::clickedButt2()
{
    Mix(mcolor[1]);
    counter++;
}
void MainWindow::clickedButt3()
{
    Mix(mcolor[2]);
    counter++;
}
void MainWindow::clickedButt4()
{
    Mix(mcolor[3]);
    counter++;
}
void MainWindow::clickedButt5()
{
    Mix(mcolor[4]);
    counter++;
}
void MainWindow::clickedButt6()
{
    Mix(mcolor[5]);
    counter++;
}
