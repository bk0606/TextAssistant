#ifndef TEXTASSISTANT_NGRAMM_H
#define TEXTASSISTANT_NGRAMM_H

#include <vector>
#include <string>

using namespace std;

namespace text_assistant {

    class NGram {
    public:
        int n;
        int frequency;
        float probability;
        vector<string> words;

        bool    operator == (const NGram &other) const;
        bool    operator != (const NGram &other) const;

                NGram(int frequency, vector<string> words, float probability = 0);
                NGram(int n, int frequency = 1, float probability = 0);
    };

}


#endif //TEXTASSISTANT_NGRAMM_H
