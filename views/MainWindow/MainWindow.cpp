#include "MainWindow.h"
#include "./ui_MainWindow.h"


MainWindow::MainWindow(ImagesDatabase* db, ImageUploader* controller, QWidget* parent) : QMainWindow(parent),
                                                                                         ui(new Ui::MainWindow),
                                                                                         db(db),
                                                                                         controller(controller) {
    this->ui->setupUi(this);
    this->ui->uploadFileButton->setDisabled(true);
    this->db->subscribe(this);
}

MainWindow::~MainWindow() {
    delete ui;
    this->db->unsubscribe(this);
}

void MainWindow::update() {
    // Updates the two progress bars
    this->ui->currentUploadingProgress->setValue(this->db->getCurrentUploadingProgress());
    this->ui->totalNumberUploadedProgress->setValue(this->db->getCurrentNumberOfUploadedImages());
}

void MainWindow::on_addNewFileButton_pressed() {
    try {
        this->addImagesWithDialog();
        // Enable the upload button, since now there are images
        this->ui->uploadFileButton->setDisabled(false);
        // Set the number of files to upload in the upload button
        this->ui->uploadFileButton->setText(
                std::string("Upload " + std::to_string(this->db->getNumberOfImagesToUpload()) + " files").c_str());
    }
    // Catch needed in case the dialog is closed without any selection
    catch (const std::runtime_error& e) {}
}

void MainWindow::on_uploadFileButton_pressed() {
    // Setup the total progress bar
    this->ui->totalNumberUploadedProgress->setMaximum(this->db->getNumberOfImagesToUpload());
    this->ui->totalNumberUploadedProgress->setFormat("%v/%m");

    // Disable the button to avoid restarting this process before the current one terminated
    this->ui->uploadFileButton->setDisabled(true);
    this->ui->addNewFileButton->setDisabled(true);

    this->controller->uploadImages();

    QMessageBox::information(this, "Upload finished", "All the needed images have been uploaded");

    // Re-enable the add new images button, so the user can upload more files
    this->ui->addNewFileButton->setDisabled(false);
}

void MainWindow::addImagesWithDialog() {
    QStringList fileNameList = QFileDialog::getOpenFileNames(this, "Select one ore more images", nullptr,
                                                             tr("Images (*.png *.jpg *.jpeg)"));

    for (const auto& fileName : fileNameList) {
        Image newImage(fileName.toStdString(), this->controller->getFileExtension(fileName.toStdString()));

        // Adds the selected image, if already present show error
        if (!this->controller->addImage(newImage)) {
            std::string msg = newImage.getName() + "\nSelected image already exists";
            QMessageBox::critical(this, "Error", msg.c_str());
        }
    }
}
