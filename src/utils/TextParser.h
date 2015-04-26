#ifndef TEXTASSISTANT_TEXTPARSER_H
#define TEXTASSISTANT_TEXTPARSER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <assert.h>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

namespace text_assistant {

    class TextParser {
    public:
        static vector<string>  parseFromFile(const char* fullPath);
    };

}


#endif //TEXTASSISTANT_TEXTPARSER_H
