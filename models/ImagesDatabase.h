//
// Created by Simone Carletti on 26/06/2021.
//

#ifndef CARLETTI_ESAME_B024260_IMAGESDATABASE_H
#define CARLETTI_ESAME_B024260_IMAGESDATABASE_H

#include <iostream>
#include <map>
#include <chrono>
#include <thread>
#include<QDebug>
#include "../interfaces/Subject.h"
#include "Image.h"


class ImagesDatabase : public Subject {
public:
    ImagesDatabase() = default;
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


private:
    void simulateUploadingTime();

    std::map<std::string, Image> images{};
    int currentUploadingProgress{0};
};


#endif //CARLETTI_ESAME_B024260_IMAGESDATABASE_H
