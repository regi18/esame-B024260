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

    std::string getFileExtension(const std::string& fileName) const;
    bool uploadImage(const Image& image);

private:
    ImagesDatabase* const db;
};


#endif //CARLETTI_ESAME_B024260_IMAGEUPLOADER_H
