//
// Created by Simone Carletti on 26/06/2021.
//

#include "ImagesDatabase.h"
bool ImagesDatabase::addImage(const Image &newImage) {
    // If an image with the same name already exists, exit and return false
    if (this->images.find(newImage.getName()) != this->images.end()) return false;

    this->images.insert({ newImage.getName(), newImage });
    return true;
}

bool ImagesDatabase::removeImage(const std::string& name) {
    return this->images.erase(name) == 1;
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
