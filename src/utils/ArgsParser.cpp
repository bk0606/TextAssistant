#include "ArgsParser.h"

namespace text_assistant {

    char *text_assistant::ArgsParser::getArgValue(char **begin, char **end, const string &option) {
        char **itr = find(begin, end, option);
        if (itr != end && ++itr != end) {
            return *itr;
        }
        return 0;
    }

    bool text_assistant::ArgsParser::isArgExists(char **begin, char **end, const string &option) {
        return find(begin, end, option) != end;
    }

}