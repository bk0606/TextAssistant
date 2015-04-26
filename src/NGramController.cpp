#include <iostream>
#include "NGramController.h"

namespace text_assistant {

    void NGramController::learnOnTextFile(char const *fullPath) {
        vector<string> words = TextParser::parseFromFile(fullPath);
        string dot = ".";
        for (size_t i = 0, len = words.size(); i < len; ++i) {
            NGram nGram(n);
            for (size_t j = i; j < (i+n); ++j) {
                string word = words[j];
                if (word != dot) {
                    nGram.words.push_back(word);
                } else {
                    break;
                }
                if (nGram.words.size() == n) {
                    long long ind = getIndex(nGram);
                    if (ind == NOT_FOUND_IND) {
                        nGrams.push_back(nGram);
                    } else {
                        nGrams[ind].frequency += 1;
                    }
                }
            }
        }
    }

    string NGramController::toString() {
        string str = "Ngrams in controller:";
        size_t len = nGrams.size();
        for (size_t i = 0; i < len; ++i) {
            NGram nGram = nGrams[i];
            str += "\n" + repo.intToString(nGram.frequency) + ", ";
            for (int j = 0; j < n; ++j) {
                str += nGram.words[j] + ", ";
            }
        }
        return str;
    }

    long long NGramController::getIndex(NGram nGram) {
        for (size_t i = 0, len = nGrams.size(); i < len; ++i) {
            if (nGram == nGrams[i]) {
                // long long bcs size_t is unsigned long but we need special value: NOT_FOUND_IND = -1
                return (long long int) i;
            }
        }
        return NOT_FOUND_IND;
    }

    NGramController::NGramController(const NGramRepo &nGramRepo)
        : n(nGramRepo.n), repo(nGramRepo) {}
}