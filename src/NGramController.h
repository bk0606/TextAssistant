#ifndef TEXTASSISTANT_NGRAMCONTROLLER_H
#define TEXTASSISTANT_NGRAMCONTROLLER_H

#include "NGram.h"
#include "database/MysqlDbController.h"

namespace text_assistant {

    class NGramController {
    public:
        vector<NGram> nGrams;
        int n;

        MysqlDbController dbController;
        string tableName;

        vector<NGram>   serializeFromDb();
        void            deserializeToDb();
        void            createTableIfNotExists();

        string          toString();
        string          intToString(int num);

                        NGramController(int n, ConnectionSettings settings, string tableName = "ngrams");

    };

}

#endif //TEXTASSISTANT_NGRAMCONTROLLER_H
