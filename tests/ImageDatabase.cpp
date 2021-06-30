//
// Created by Simone Carletti on 27/06/2021.
//

#include "gtest/gtest.h"
#include "../models/ImagesDatabase.h"


TEST(ImagesDatabase, AddImage) {
    ImagesDatabase db;

    ASSERT_TRUE(db.addImage({"test", "png"}));
    ASSERT_FALSE(db.addImage({"test", "png"}));       // Insert image with same name
    ASSERT_TRUE(db.addImage({"test2", "png"}));
    ASSERT_TRUE(db.addImage({"test3", "png"}));
}

TEST(ImagesDatabase, RemoveImage) {
    ImagesDatabase db;

    ASSERT_TRUE(db.addImage({"test", "png"}));
    ASSERT_TRUE(db.addImage({"test2", "png"}));
    ASSERT_TRUE(db.addImage({"test3", "png"}));

    ASSERT_TRUE(db.removeImage("test"));
    ASSERT_TRUE(db.removeImage("test3"));
    ASSERT_FALSE(db.removeImage("nonExistingName"));    // Removing non existing image
    ASSERT_TRUE(db.removeImage("test2"));
    ASSERT_FALSE(db.removeImage("test2"));              // Removing image on empty database
}

TEST(ImagesDatabase, GetImage) {
    ImagesDatabase db;

    ASSERT_TRUE(db.addImage({"test", "png"}));
    ASSERT_TRUE(db.addImage({"test2", "png"}));
    ASSERT_TRUE(db.addImage({"test3", "png"}));

    EXPECT_NO_THROW(db.getImage("test"));
    Image i = db.getImage("test");
    ASSERT_EQ(i.getName(), "test");
    ASSERT_EQ(i.getExtension(), "png");

    EXPECT_THROW(db.getImage("nonExistingName"), std::out_of_range);
}
