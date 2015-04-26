#ifndef TEXTASSISTANT_TEXTPARSERTESTS_H
#define TEXTASSISTANT_TEXTPARSERTESTS_H

#include <gtest/gtest.h>
#include "../utils/TextParser.h"

namespace text_assistant {

    TEST (TextParserTest, IsWordsSizeEqual) {
        vector<string> correctWords = {"Саша", "любит", "Машу", ".", "Маша", "любит", "Гришу", "."};
        vector<string> words = TextParser::parseFromFile(
                "/home/albert/Dropbox/Code/Cpp/TextAssistant/resources/testing_input");

        ASSERT_TRUE(correctWords.size() == words.size());
    }

    TEST (TextParserTest, IsCorrectWords) {
        vector<string> correctWords = {"Саша", "любит", "Машу", ".", "Маша", "любит", "Гришу", "."};
        vector<string> words = TextParser::parseFromFile(
                "/home/albert/Dropbox/Code/Cpp/TextAssistant/resources/testing_input");

        for (int i = 0; i < correctWords.size(); ++i) {
            ASSERT_TRUE(correctWords[i] == words[i]);
        }
    }

}

#endif //TEXTASSISTANT_TEXTPARSERTESTS_H
