#ifndef TEXTASSISTANT_INPUTARGSPARSER_H
#define TEXTASSISTANT_INPUTARGSPARSER_H

#include <algorithm>

using namespace std;

namespace text_assistant {

    class ArgsParser {
    public:

        static char*    getArgValue(char **begin, char **end, const string &option);
        static bool     isArgExists(char **begin, char **end, const string &option);
    };
}


#endif //TEXTASSISTANT_INPUTARGSPARSER_H
