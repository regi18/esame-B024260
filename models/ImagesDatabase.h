//
// Created by Simone Carletti on 26/06/2021.
//

#ifndef CARLETTI_ESAME_B024260_IMAGESDATABASE_H
#define CARLETTI_ESAME_B024260_IMAGESDATABASE_H

#include "../interfaces/Subject.h"
#include "Image.h"


class ImagesDatabase : public Subject {
public:


private:
    std::list<Image> images;
};


#endif //CARLETTI_ESAME_B024260_IMAGESDATABASE_H
