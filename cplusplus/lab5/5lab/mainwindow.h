#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <rectangle.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
private:
    Ui::MainWindow *ui;
    QVector <Rectangle *> rect;
    int k = 0;
    int x,y;
};
#endif // MAINWINDOW_H
