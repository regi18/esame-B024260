//
// Created by Simone Carletti on 26/06/2021.
//

#ifndef CARLETTI_ESAME_B024260_IMAGE_H
#define CARLETTI_ESAME_B024260_IMAGE_H

#include <string>
#include <utility>
#include <ostream>


class Image {
public:
    Image(std::string name, std::string extension) : name(std::move(name)), extension(std::move(extension)) {}

    std::string getName() const {
        return name;
    }

    std::string getExtension() const {
        return extension;
    }

    friend std::ostream& operator<<(std::ostream& os, const Image& image) {
        os << "Image: " << image.name << " (." << image.extension << ")";
        return os;
    }

    // Needed for std::set_difference
    bool operator<(const Image& rhs) const {
        return name < rhs.name;
    }


private:
    std::string name;
    std::string extension;
};


#endif //CARLETTI_ESAME_B024260_IMAGE_H
