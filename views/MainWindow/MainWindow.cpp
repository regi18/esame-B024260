#include "MainWindow.h"
#include "./ui_MainWindow.h"


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
    // Updates the two progress bars
    this->ui->currentUploadingProgress->setValue(this->db->getCurrentUploadingProgress());
    this->ui->totalNumberUploadedProgress->setValue(this->db->getNumberOfImages());
}


void MainWindow::on_uploadFileButton_pressed() {
    // Disable the button to avoid restarting this process before the current one terminated
    this->ui->uploadFileButton->setDisabled(true);

    try {
        // Upload the selected image, if already uploaded show error
        if (!this->controller->uploadImage(this->getImageWithDialog()))
            QMessageBox::critical(this, "Error", "Selected image already exists");
    }
    catch (const std::runtime_error& e) {}

    // If maximum number of images reached, permanently disable "upload" button
    if (this->db->getMaxNumberOfImages() != this->db->getNumberOfImages())
        this->ui->uploadFileButton->setDisabled(false);
    else
        QMessageBox::information(this, "Upload finished", "All the needed images have been uploaded");
}

Image MainWindow::getImageWithDialog() {
    QString fileName = QFileDialog::getOpenFileName(this, "Select image", nullptr, tr("Images (*.png *.jpg)"));

    // Check if an image was actually selected from the dialog
    if (!fileName.isNull())
        return Image(fileName.toStdString(), this->controller->getFileExtension(fileName.toStdString()));
    else
        throw std::runtime_error("No image selected");
}
