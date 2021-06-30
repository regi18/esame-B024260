//
// Created by Simone Carletti on 26/06/2021.
//

#include "ImagesDatabase.h"

bool ImagesDatabase::addImage(const Image& newImage) {
    // If an image with the same name already exists, exit and return false
    if (this->images.find(newImage.getName()) != this->images.end()) return false;

    this->images.insert({newImage.getName(), newImage});
    return true;
}

bool ImagesDatabase::removeImage(const std::string& name) {
    if (this->images.erase(name) == 1) {
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

void ImagesDatabase::upload() {
    this->currentNumberOfUploadedImages = 0;

    // Get the images that still need to be uploaded (i.e. the difference between uploadedImages and images)
    std::map<std::string, const Image&> imagesToUpload{};
    std::set_difference(
            this->images.begin(), this->images.end(),
            this->uploadedImages.begin(), this->uploadedImages.end(),
            std::inserter(imagesToUpload, imagesToUpload.end()));

    // Upload all images
    for (const auto& image : imagesToUpload) {
        this->currentUploadingProgress = 0;
        this->notifyAll();

        // Simulate uploading progress for the current image
        for (int i = 0; i < static_cast<int>(dist(mt)) % 5 + 5; i++) {
            // Sleep for a random amount of ms (from 800ms to 1200ms)
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(dist(mt)) + 800));

            // Increment the uploading progress of a random number
            this->currentUploadingProgress += static_cast<int>(dist(mt)) % 30;

            if (this->currentUploadingProgress > 100) this->currentUploadingProgress = 100;
            this->notifyAll();
            if (this->currentUploadingProgress == 100) break;
        }

        this->uploadedImages.insert(image);

        this->currentUploadingProgress = 100;
        this->currentNumberOfUploadedImages++;
        this->notifyAll();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}
