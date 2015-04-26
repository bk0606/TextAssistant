#include "TextParser.h"

namespace text_assistant {

    vector<string> TextParser::parseFromFile(const char *fullPath) {
        ifstream file;
        file.open (fullPath);
        assert(file.is_open());

        regex punctuationRegex;
        punctuationRegex.imbue(std::locale("ru_RU.utf8"));
        punctuationRegex.assign("[,:-]");
        const string replaceable = "";

        regex dotRegex;
        dotRegex.imbue(std::locale("ru_RU.utf8"));
        dotRegex.assign("[.!?]");

        vector<string> words;
        string word;
        string dot = ".";
        while (file >> word)
        {
            word = regex_replace(word, punctuationRegex, replaceable);
            if (regex_search(word, dotRegex)) {
                word = regex_replace(word, dotRegex, replaceable);
                words.push_back(word);
                words.push_back(dot);
            } else {
                words.push_back(word);
            }
        }
        return words;
    }

}