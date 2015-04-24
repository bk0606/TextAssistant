#include <iostream>
#include "NGramController.h"

namespace text_assistant {

    vector<NGram> NGramController::serializeFromDb() {
        string query = "SELECT * FROM `" + tableName +"`;";
        MYSQL_RES* result = dbController.performQuery(query.c_str());

        dbController.iterateResult(result, [this](MYSQL_ROW row) {
            vector<string> words;
            words.reserve((unsigned long) (n));
            for (int i = 2; i < n+2; ++i) {
                words.push_back(string(row[i]));
            }
            nGrams.push_back(NGram(atoi(row[1]), words));
        });

        mysql_free_result(result);
        return nGrams;
    }

    void NGramController::deserializeToDb() {
        createTableIfNotExists();
        string query = "INSERT INTO `" + tableName + "` (frequency, ";
        for (int i = 1; i < n; ++i) {
            query += "`" + intToString(i) + "gram`" + ", ";
        }
        query += "`" + intToString(n) + "gram`" + ") VALUES ";

        unsigned long len = nGrams.size();
        for (unsigned long ind = 0 ; ind < len; ++ind) {
            NGram nGram = nGrams[ind];
            query += "(" + intToString(nGram.frequency) + ", ";
            for (int k = 0; k < n-1; ++k) {
                query += "\"" + nGram.words[k] + "\", ";
            }
            query += "\"" + nGram.words[n-1] + "\"";
            query += ind == (len-1) ?  "); " :  "), ";
        }

        auto result = dbController.performQuery(query.c_str());
        mysql_free_result(result);
    }

    void NGramController::createTableIfNotExists() {
        string query = "CREATE TABLE IF NOT EXISTS `" + tableName + "` (";
        query += "`id` INT NOT NULL AUTO_INCREMENT, `frequency` INT NULL, ";
        for (int i = 1; i <= n; ++i) {
            query += "`" + intToString(i) + "gram`" + " VARCHAR(50) NULL, ";
        }
        query += " PRIMARY KEY (`id`));";

        auto result = dbController.performQuery(query.c_str());
        mysql_free_result(result);
    }

    NGramController::NGramController(int n, ConnectionSettings settings, string tableName) {
        this->n = n;
        dbController.setupConnection(settings);
        this->tableName = tableName;
    }

    string NGramController::toString() {
        string str = "Ngrams in controller:";
        unsigned long len = nGrams.size();
        for (unsigned long i = 0; i < len; ++i) {
            NGram nGram = nGrams[i];
            str += "\n" + intToString(nGram.frequency) + ", ";
            for (int j = 0; j < n; ++j) {
                str += nGram.words[j] + ", ";
            }
        }
        return str;
    }

    string NGramController::intToString(int num) {
        char str[20]; // TODO: Care, may be not enough
        sprintf(str, "%d", num);
        return string(str);
    }
}