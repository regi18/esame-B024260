#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(ImagesDatabase* db, ImageUploader* controller, QWidget* parent) : QMainWindow(parent),
                                                                                         ui(new Ui::MainWindow),
                                                                                         db(db),
                                                                                         controller(controller) {
    this->ui->setupUi(this);
    this->ui->totalNumberUploadedProgress->setMaximum(this->db->getMaxNumberOfImages());
    this->db->subscribe(this);
}

MainWindow::~MainWindow() {
    delete ui;
    this->db->unsubscribe(this);
}

void MainWindow::update() {
    this->ui->currentUploadingProgress->setValue(this->db->getCurrentUploadingProgress());
    this->ui->totalNumberUploadedProgress->setValue(this->db->getNumberOfImages());
}


void MainWindow::on_uploadFileButton_pressed() {
    this->ui->uploadFileButton->setDisabled(true);

    if (!this->controller->uploadImage(this->getImageWithDialog()))
        QMessageBox::critical(this, "Error", "Selected image already exists");

    if (this->db->getMaxNumberOfImages() != this->db->getNumberOfImages())
        this->ui->uploadFileButton->setDisabled(false);
}

Image MainWindow::getImageWithDialog() {
    QString fileName = QFileDialog::getOpenFileName(this, "Select image", nullptr, tr("Images (*.png *.jpg)"));

    return Image(fileName.toStdString(), this->controller->getFileExtension(fileName.toStdString()));
}
