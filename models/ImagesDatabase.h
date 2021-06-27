//
// Created by Simone Carletti on 26/06/2021.
//

#ifndef CARLETTI_ESAME_B024260_IMAGESDATABASE_H
#define CARLETTI_ESAME_B024260_IMAGESDATABASE_H

#include <iostream>
#include <map>
#include <chrono>
#include <thread>
#include "../interfaces/Subject.h"
#include "Image.h"


/**
 * A database of images
 */
class ImagesDatabase : public Subject {
public:
    explicit ImagesDatabase(int maxNumberOfImages) : maxNumberOfImages(maxNumberOfImages) {};
    ~ImagesDatabase() override = default;

    /**
     * Adds a new image.
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
     * Prints the database to console
     */
    void dump() const;

    int getNumberOfImages() const {
        return this->images.size();
    }
    int getCurrentUploadingProgress() const {
        return currentUploadingProgress;
    }
    int getMaxNumberOfImages() const {
        return maxNumberOfImages;
    }
    void setIsSimulateSlowerUpload(bool isSimulateSlowerUpload) {
        ImagesDatabase::isSimulateSlowerUpload = isSimulateSlowerUpload;
    }


private:
    /**
     * Simulates an image upload by sleeping for some time.
     * N.B. Since this program is not multi-threaded this simulation
     * will freeze the entire window while in progress.
     */
    void simulateUploadingTime();
    // If set to false disables the slower uploading time
    bool isSimulateSlowerUpload = true;

    std::map<std::string, Image> images{};

    int currentUploadingProgress{0};
    int maxNumberOfImages;
};


#endif //CARLETTI_ESAME_B024260_IMAGESDATABASE_H
