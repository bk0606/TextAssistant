//
// Created by albert on 21.04.15.
//

#include <iostream>
#include "NGramController.h"

namespace text_assistant {

    string NGramController::getGramLiteral(int ind) {
        char indStr[n]; // TODO: Optimize
        sprintf (indStr, "%d", ind);
        string literal = "`";
        literal += indStr;
        literal += "gram`";
        return literal;
    }

    vector<NGram> NGramController::serializeFromDb() {
        string query = "SELECT * FROM `" + tableName +"`;"; // TODO: Try to move init in field
        auto result = dbController.performQuery(query.c_str()); // TODO: Del result

        // TODO: Reserve memory to nGrams // .reserve((unsigned long) (Count));
        cout << endl << "Length of set" << result->lengths << endl;

        dbController.iterateResult(result, [this](MYSQL_ROW row) {
            vector<string> words;
            words.reserve((unsigned long) (n));

            for (int i = 2; i < n+2; ++i) {
                words.push_back(string(row[i]));
            }
            nGrams.push_back(NGram(atoi(row[0]), atoi(row[1]), words));
        });

        return nGrams;
    }

    void NGramController::deserializeToDb() {
        string query = "INSERT INTO `" + tableName + "` (id, frequency, ";
        for (int i = 1; i < n; ++i) {
            query += getGramLiteral(i) + ", ";
        }
        query += getGramLiteral(n) + ") VALUES ";

        unsigned long len = nGrams.size();
        for (unsigned long j = 0 ; j < len; ++j) {
            NGram nGram = nGrams[j];
            query += "(";
            char idStr[n]; // TODO: Optimize
            sprintf (idStr, "%d", j);
            query += idStr;
            query += ", ";
            char freqStr[n]; // TODO: Optimize
            sprintf (idStr, "%d", nGram.frequency);
            query += idStr;
            query += ", ";
            for (int k = 0; k < n-1; ++k) {
                query += "\"";
                query += nGram.words[k] + "\", ";
            }
            query += "\"";
            query += nGram.words[n-1] + "\"";
            query += j == (len-1) ?  "); " :  "), ";
        }

        cout << query << "\n" ;

        auto result = dbController.performQuery(query.c_str());
        // TODO: Del result
        // mysql_free_result(result);
    }

    string NGramController::generateRows() {
        string rows = "";
        for (int i = 1; i <= n; ++i) {
            rows += getGramLiteral(i) + " VARCHAR(50) NULL, ";
        }
        return rows;
    }

    void NGramController::createTable() {
        string query = "CREATE TABLE IF NOT EXISTS `" + tableName + "` (";
        query += "`id` INT NOT NULL, `frequency` INT NULL, ";
        query += generateRows();
        query += " PRIMARY KEY (`id`));";

        auto result = dbController.performQuery(query.c_str());

        // TODO: Del result
        // mysql_free_result(result);
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
            str += "\n";
            char freqStr[n]; // TODO: Optimize
            sprintf (freqStr, "%d", nGram.frequency);
            str += freqStr;
            str += ", ";
            for (int j = 0; j < n; ++j) {
                str += nGram.words[j] + ", ";
            }
        }
        return str;
    }
}