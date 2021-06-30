//
// Created by Simone Carletti on 26/06/2021.
//

#include "ImageUploader.h"
bool ImageUploader::addImage(const Image& image) {
    return this->db->addImage(image);
}

void ImageUploader::uploadImages() {
    this->db->upload();
}

std::string ImageUploader::getFileExtension(const std::string& fileName) const {
    // Matches the extension from the filename
    std::smatch match;
    std::regex_search(fileName, match, std::regex("\\.[0-9a-z]+$", std::regex::icase));

    if (!match.empty()) {
        // Removes the '.' from the begin of the string
        std::string extension = match[0].str();
        extension.erase(extension.begin());

        return extension;
    }
    else return "";
}
