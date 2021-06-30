//
// Created by Simone Carletti on 30/06/2021.
//

#include <memory>
#include "gtest/gtest.h"
#include "../models/ImagesDatabase.h"
#include "../controllers/ImageUploader.h"


class MvcPatternSuite : public ::testing::Test, public Observer {
public:
    ~MvcPatternSuite() override = default;

    void update() override {
        this->wasUpdateCalled = true;
    }


protected:
    void SetUp() override {
        this->db = std::unique_ptr<ImagesDatabase>(new ImagesDatabase());
        this->controller = std::unique_ptr<ImageUploader>(new ImageUploader(db.get()));
        this->db->subscribe(this);

        // Add test images
        db->addImage({"test", "png"});
        db->addImage({"test2", "png"});
        db->addImage({"test3", "png"});
    }

    void TearDown() override {
        this->db->unsubscribe(this);
    }


    std::unique_ptr<ImagesDatabase> db;
    std::unique_ptr<ImageUploader> controller;
    bool wasUpdateCalled = false;
};


TEST_F(MvcPatternSuite, UploadImages) {
    ASSERT_FALSE(this->wasUpdateCalled);
    ASSERT_EQ(this->db->getCurrentNumberOfUploadedImages(), 0);
    ASSERT_EQ(this->db->getCurrentUploadingProgress(), 0);
    ASSERT_EQ(this->db->getNumberOfImagesToUpload(), 3);

    this->controller->uploadImages();

    ASSERT_TRUE(this->wasUpdateCalled);
    ASSERT_EQ(this->db->getCurrentNumberOfUploadedImages(), 3);
    ASSERT_EQ(this->db->getCurrentUploadingProgress(), 100);
    ASSERT_EQ(this->db->getNumberOfImagesToUpload(), 0);
}
