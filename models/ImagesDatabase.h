//
// Created by Simone Carletti on 26/06/2021.
//

#ifndef CARLETTI_ESAME_B024260_IMAGESDATABASE_H
#define CARLETTI_ESAME_B024260_IMAGESDATABASE_H

#include <iostream>
#include <map>
#include <chrono>
#include <random>
#include <thread>
#include <algorithm>
#include "../interfaces/Subject.h"
#include "Image.h"


/**
 * A database of images
 */
class ImagesDatabase : public Subject {
public:
    explicit ImagesDatabase() {
        // Setup the pseudo-random number generator
        std::random_device rd;
        this->mt = std::mt19937(rd());
        this->dist = std::uniform_real_distribution<double>(1.0, 400.0);
    };

    ~ImagesDatabase() override = default;

    /**
     * Adds a new image to the upload queue.
     * N.B. Each image has to have a unique name.
     *
     * @param newImage The image to add
     * @return true if added successfully, false otherwise
     */
    bool addImage(const Image& newImage);
    /**
     * Removes an image, given its name.
     *
     * @param name The name of the image to remove
     * @return true if removed successfully, false otherwise
     */
    bool removeImage(const std::string& name);
    /**
     * Returns an image given its name.
     * If the given name does not exist, it throws std::out_of_range.
     *
     * @param name The name of the image
     * @return A reference to the image
     */
    Image& getImage(const std::string& name);

    /**
     *  Simulates the upload of the images to a remote server
     */
     void upload();

    /**
     * Prints the database to console
     */
    void dump() const;

    int getNumberOfImagesToUpload() const {
        return this->images.size() - this->uploadedImages.size();
    }
    int getCurrentUploadingProgress() const {
        return currentUploadingProgress;
    }
    int getCurrentNumberOfUploadedImages() const {
        return currentNumberOfUploadedImages;
    }


private:
    std::map<std::string, Image> images{};
    std::map<std::string, Image> uploadedImages{};

    int currentUploadingProgress{0};
    int currentNumberOfUploadedImages{0};

    std::uniform_real_distribution<double> dist;
    std::mt19937 mt;
};


#endif //CARLETTI_ESAME_B024260_IMAGESDATABASE_H
