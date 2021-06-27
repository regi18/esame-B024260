#include <QApplication>
#include <models/ImagesDatabase.h>
#include "./views/MainWindow/MainWindow.h"


int main(int argc, char *argv[]) {
    ImagesDatabase db(2);
    ImageUploader controller(&db);

    QApplication a(argc, argv);
    MainWindow w(&db, &controller);
    w.show();
    return QApplication::exec();
}
