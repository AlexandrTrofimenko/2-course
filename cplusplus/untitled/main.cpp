#include "mainwindow.h"

#include <QApplication>
#include <vector>
#include <QVector>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QVector <int> k2;
    std::vector <int> k1;
    k2.size();
    k2.append(2); k2.append(13);
    k1.push_back(2);
    qDebug("%d",k2[1]);
    w.show();
    return a.exec();
}
