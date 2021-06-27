#define QT_AUTO_SCREEN_SCALE_FACTOR 1

#include <QApplication>
#include <models/ImagesDatabase.h>
#include "views/mainwindow/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return QApplication::exec();
}
