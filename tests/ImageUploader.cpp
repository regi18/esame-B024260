//
// Created by Simone Carletti on 27/06/2021.
//

#include <memory>
#include "gtest/gtest.h"
#include "../models/ImagesDatabase.h"
#include "../controllers/ImageUploader.h"


class ImageUploaderSuite : public ::testing::Test {

protected:
    void SetUp() override {
        this->db = std::unique_ptr<ImagesDatabase>(new ImagesDatabase());
        this->controller = std::unique_ptr<ImageUploader>(new ImageUploader(db.get()));
    }

    std::unique_ptr<ImagesDatabase> db;
    std::unique_ptr<ImageUploader> controller;
};


TEST_F(ImageUploaderSuite, GetFileExtension) {
    ASSERT_EQ(this->controller->getFileExtension("hello.jpg"), "jpg");
    ASSERT_EQ(this->controller->getFileExtension("hel.lo.png.txt"), "txt");
    ASSERT_EQ(this->controller->getFileExtension("hello."), "");
    ASSERT_EQ(this->controller->getFileExtension("hello"), "");
}

TEST_F(ImageUploaderSuite, AddImage) {
    ASSERT_TRUE(this->controller->addImage({"test", "jpg"}));
    ASSERT_FALSE(this->controller->addImage({"test", "jpg"}));       // Adding already existing image
    ASSERT_TRUE(this->controller->addImage({"test2", "jpg"}));
    ASSERT_TRUE(this->controller->addImage({"test3", "jpg"}));
}
