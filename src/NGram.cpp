#include "NGram.h"

namespace text_assistant {

    bool NGram::operator == (const NGram &other) const {
        vector<string> otherWords = other.words;
        vector<string> currentWords = words;
        for (int i = 0; i < n; ++i) {
            if (currentWords[i] != otherWords[i]) {
                return false;
            }
        }
        return true;
    }

    bool NGram::operator != (const NGram &other) const {
        return !(*this == other);
    }

    // TODO: Care with cast
    text_assistant::NGram::NGram(int frequency, vector<string> words, float probability) :
            n((int) words.size()), frequency(frequency), words(words), probability(probability) { }

    NGram::NGram(int n, int frequency, float probability) :
            n(n), frequency(frequency), probability(probability) {}
}