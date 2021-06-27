//
// Created by Simone Carletti on 26/06/2021.
//

#include "ImagesDatabase.h"
bool ImagesDatabase::addImage(const Image& newImage) {
    // If an image with the same name already exists, exit and return false
    if (this->images.find(newImage.getName()) != this->images.end()) return false;
    // Maximum number of images reached
    if (this->getNumberOfImages() == this->getMaxNumberOfImages()) return false;

    this->currentUploadingProgress = 0;
    if (isSimulateSlowerUpload) this->simulateUploadingTime();

    this->images.insert({newImage.getName(), newImage});
    this->currentUploadingProgress = 100;
    this->notifyAll();
    return true;
}

bool ImagesDatabase::removeImage(const std::string& name) {
    if (this->images.erase(name) == 1) {
        this->notifyAll();
        return true;
    }
    else return false;
}

Image& ImagesDatabase::getImage(const std::string& name) {
    try {
        return this->images.at(name);
    }
    catch (const std::out_of_range& e) {
        throw std::out_of_range("Invalid image name");
    }
}

void ImagesDatabase::dump() const {
    for (const auto& image : this->images) {
        std::cout << image.second << std::endl;
    }
}


void ImagesDatabase::simulateUploadingTime() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    this->currentUploadingProgress = 10;
    this->notifyAll();

    std::this_thread::sleep_for(std::chrono::milliseconds(800));
    this->currentUploadingProgress = 23;
    this->notifyAll();

    std::this_thread::sleep_for(std::chrono::milliseconds(900));
    this->currentUploadingProgress = 43;
    this->notifyAll();

    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    this->currentUploadingProgress = 66;
    this->notifyAll();

    std::this_thread::sleep_for(std::chrono::milliseconds(800));
}
