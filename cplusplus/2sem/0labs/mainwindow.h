#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVector <QPoint> masspoint;
    bool f = false;
    int x=-100,y=-100,x1=10,y1=10;
};
#endif // MAINWINDOW_H
