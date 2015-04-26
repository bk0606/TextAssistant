#include "NGramRepo.h"

namespace text_assistant {

    void NGramRepo::serializeFromDb(NGramController &controller) const {
        string query = "SELECT * FROM `" + tableName +"`;";
        MYSQL_RES* result = dbController.performQuery(query.c_str());

        dbController.iterateResult(result, [&](MYSQL_ROW row) {
            vector<string> words;
            words.reserve((unsigned long) (n));
            for (int i = 2; i < n+2; ++i) {
                words.push_back(string(row[i]));
            }
            controller.nGrams.push_back(NGram(atoi(row[1]), words));
        });

        mysql_free_result(result);
    }

    void NGramRepo::deserializeToDb(const NGramController &controller) const {
        createTableIfNotExists();
        string query = "INSERT INTO `" + tableName + "` (frequency, ";
        for (int i = 1; i < n; ++i) {
            query += "`" + intToString(i) + "gram`" + ", ";
        }
        query += "`" + intToString(n) + "gram`" + ") VALUES ";

        unsigned long len = controller.nGrams.size();
        for (unsigned long ind = 0 ; ind < len; ++ind) {
            NGram nGram = controller.nGrams[ind];
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

    void NGramRepo::createTableIfNotExists() const {
        string query = "CREATE TABLE IF NOT EXISTS `" + tableName + "` (";
        query += "`id` INT NOT NULL AUTO_INCREMENT, `frequency` INT NULL, ";
        for (int i = 1; i <= n; ++i) {
            query += "`" + intToString(i) + "gram`" + " VARCHAR(50) NULL, ";
        }
        query += " PRIMARY KEY (`id`));";

        auto result = dbController.performQuery(query.c_str());
        mysql_free_result(result);
    }

    string NGramRepo::intToString(int num) const {
        char str[20]; // TODO: Care, may be not enough
        sprintf(str, "%d", num);
        return string(str);
    }

    NGramRepo::NGramRepo(int n, ConnectionSettings settings, string tableName) {
        this->n = n;
        dbController.setupConnection(settings);
        this->tableName = tableName;

    }
}
