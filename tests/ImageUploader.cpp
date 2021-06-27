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
        this->db = std::unique_ptr<ImagesDatabase>(new ImagesDatabase(3));
        this->db->setIsSimulateSlowerUpload(false);
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

TEST_F(ImageUploaderSuite, UploadImage) {
    ASSERT_TRUE(this->controller->uploadImage({"test", "jpg"}));
    ASSERT_FALSE(this->controller->uploadImage({"test", "jpg"}));       // Uploading already existing image
    ASSERT_TRUE(this->controller->uploadImage({"test2", "jpg"}));
    ASSERT_TRUE(this->controller->uploadImage({"test3", "jpg"}));
    ASSERT_FALSE(this->controller->uploadImage({"test4", "jpg"}));      // Uploading in full database
}
