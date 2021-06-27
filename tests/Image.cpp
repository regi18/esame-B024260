//
// Created by Simone Carletti on 27/06/2021.
//

#include "gtest/gtest.h"
#include "../models/ImagesDatabase.h"


TEST(Image, Constructor) {
    Image img("hello.png", "png");

    ASSERT_EQ(img.getName(), "hello.png");
    ASSERT_EQ(img.getExtension(), "png");
}

