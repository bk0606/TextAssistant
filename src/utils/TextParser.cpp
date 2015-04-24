#include "TextParser.h"

namespace text_assistant {

    vector<string> TextParser::parseFromFile(const char *fullPath) {
        ifstream file;
        file.open (fullPath);
        assert(file.is_open());

        regex punctuationRegexp;
        punctuationRegexp.imbue(std::locale("ru_RU.utf8"));
        punctuationRegexp.assign("[,:-]");
        const string replaceable = "";

        vector<string> words;
        string word;
        while (file >> word)
        {
            words.push_back(
                    regex_replace(word, punctuationRegexp, replaceable)
            );
             cout << words.back() << '\n'; // TODO: Delete
        }
        return words;
    }

    vector<string> TextParser::parseFromFile(string fullPath) {
        return parseFromFile(fullPath.c_str());
    }
}