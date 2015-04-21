#include "NGram.h"

namespace text_assistant {

    // TODO: Care with cast
    text_assistant::NGram::NGram(int frequency, vector<string> words, float probability) :
            n((int) words.size()), frequency(frequency), words(words), probability(probability) { }

}