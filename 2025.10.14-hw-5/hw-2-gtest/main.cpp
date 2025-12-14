#include <gtest/gtest.h>
#include "TextEditor.h"

class TextEditorTest : public ::testing::Test {
protected:
    TextEditor te;
};

TEST_F(TextEditorTest, AddTextBasic) {
    te.addText("hello");
    EXPECT_EQ(te.cursorLeft(5), "hello");
}

TEST_F(TextEditorTest, CursorLeftBasic) {
    te.addText("andryusha");
    std::string result = te.cursorLeft(3);
    EXPECT_EQ(result, "andry");
}

TEST_F(TextEditorTest, CursorRightBasic) {
    te.addText("andryusha");
    te.cursorLeft(3);
    std::string result = te.cursorRight(2);
    EXPECT_EQ(result, "sha");
}

TEST_F(TextEditorTest, DeleteTextPartial) {
    te.addText("hello world");
    int deleted = te.deleteText(5);
    EXPECT_EQ(deleted, 5);
    EXPECT_EQ(te.cursorLeft(10), "world");
}

TEST_F(TextEditorTest, DeleteTextExceedLength) {
    te.addText("short");
    int deleted = te.deleteText(10);
    EXPECT_EQ(deleted, 5);
    EXPECT_TRUE(te.cursorLeft(5).empty());
}
