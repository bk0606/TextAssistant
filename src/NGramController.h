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
        string grammRow;

        vector<NGram>   serializeFromDb();
        void            deserializeToDb();
        void            createTableIfNotExists();

        string          toString();

                        NGramController(int n, ConnectionSettings settings, string tableName = "ngrams");
        string          intToString(int num);

    };

}

#endif //TEXTASSISTANT_NGRAMCONTROLLER_H
