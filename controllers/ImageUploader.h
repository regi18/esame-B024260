//
// Created by Simone Carletti on 26/06/2021.
//

#ifndef CARLETTI_ESAME_B024260_IMAGEUPLOADER_H
#define CARLETTI_ESAME_B024260_IMAGEUPLOADER_H

#include <regex>
#include "../models/ImagesDatabase.h"


class ImageUploader {
public:
    explicit ImageUploader(ImagesDatabase* const db) : db(db) {};

    /**
     * Extrapolates the file's extension from the full name
     *
     * @param fileName The file name (e.g. "example.txt")
     * @return The file's extension (e.g. "txt")
     */
    std::string getFileExtension(const std::string& fileName) const;
    /**
     * Uploads the given image to the database
     *
     * @param image The image to upload
     * @return true if the image was successfully uploaded, false otherwise
     */
    bool uploadImage(const Image& image);

private:
    ImagesDatabase* const db;
};


#endif //CARLETTI_ESAME_B024260_IMAGEUPLOADER_H
