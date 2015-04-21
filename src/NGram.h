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


        NGram(int n, int frequency, vector<string> words, float probability = 0) :
            n(n), frequency(frequency), words(words), probability(probability) { }
    };

}


#endif //TEXTASSISTANT_NGRAMM_H
