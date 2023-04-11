#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>


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
    void Mix(QColor color);
    QVector<QPair<int,int>> neightbours(QVector<QPair<int,int>> pairVec);
public slots:
    void clickedButt1();
    void clickedButt2();
    void clickedButt3();
    void clickedButt4();
    void clickedButt5();
    void clickedButt6();


private:
    Ui::MainWindow *ui;
    QColor mcolor[6] = {
        (Qt::red),
        (Qt::blue),
        (Qt::green),
        (Qt::magenta),
        (Qt::cyan),
        (Qt::yellow),

    };
    int size = 40;
    QVector<QVector<QColor>> vecColor;
    QVector<QPair<int,int>> vecPair;

    QPushButton *button[6];
    int counter = 1;
};
#endif // MAINWINDOW_H
