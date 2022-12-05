#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <rectangle.h>
#include <QPaintEvent>
#include <QBrush>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int i = 0; i < rect.size();i++)
    {
        rect[i]->draw(&painter);
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Rectangle *rect1 = nullptr;
    bool fl;
    if(event->modifiers() && Qt::ControlModifier)
    {
        if(k % 2 == 0)
        {
            x = event->x();
            y = event->y();
        }
        else
        {
            rect1 = new Rectangle(x,y,event->x(),event->y());
            rect.append(rect1);
        }
        k++;
     }
     else
    {
        for(int i = 0; i < rect.size()-1; i++)
        {
            for(int j = 0; j < rect.size(); j++)
            {
                    if(rect[i]->intersect(*rect[j]))
                    {
                        fl = true;
                    }
                    else
                    {
                        fl = false;
                    }

            }

        }


    }




    repaint();
}


MainWindow::~MainWindow()
{
    delete ui;
}

