#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
   // printf("Yo");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
