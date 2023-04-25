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
    bool true_color();
public slots:
    void update();

private:
    Ui::MainWindow *ui;
    QColor mcolor[5] = {
        (Qt::red),
        (Qt::blue),
        (Qt::green),
        (Qt::magenta),
        (Qt::yellow),
    };
    int k=5,n=9,count = 0;
    QRect rects[5][9];
    QColor rectscolor[5][9];
    QColor mainrectcolor;
    QRect mainrect = QRect(0,440,60,60);
    int size = 60;
    bool gameover = false;
};
#endif // MAINWINDOW_H
