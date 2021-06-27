#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <models/ImagesDatabase.h>
#include <controllers/ImageUploader.h>
#include "../../interfaces/Observer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow, public Observer {
    Q_OBJECT

public:
    explicit MainWindow(ImagesDatabase* db, ImageUploader* controller, QWidget* parent = nullptr);
    ~MainWindow() override;

    void update() override;

private slots:
    void on_uploadFileButton_pressed();

private:
    Image getImageWithDialog();

    Ui::MainWindow *ui;
    ImagesDatabase* const db;
    ImageUploader* const controller;
};

#endif // MAINWINDOW_H
