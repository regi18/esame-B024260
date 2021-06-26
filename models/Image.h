//
// Created by Simone Carletti on 26/06/2021.
//

#ifndef CARLETTI_ESAME_B024260_IMAGE_H
#define CARLETTI_ESAME_B024260_IMAGE_H

#include <string>


class Image {
public:
    Image(const std::string &name, const std::string &extension) : name(name), extension(extension) {}

    const std::string getName() const {
        return name;
    }

    const std::string getExtension() const {
        return extension;
    }

private:
    std::string name;
    std::string extension;
};


#endif //CARLETTI_ESAME_B024260_IMAGE_H
