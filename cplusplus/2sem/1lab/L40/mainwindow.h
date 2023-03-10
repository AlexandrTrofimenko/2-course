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
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    int distance(QPoint point1,QPoint point2);
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::MainWindow *ui;
    QPoint dote;
    QVector <QPoint> massdote;
    int kIter = 0;
    int sumMin = INT_MAX;
    bool Enter = false;
};
#endif // MAINWINDOW_H
