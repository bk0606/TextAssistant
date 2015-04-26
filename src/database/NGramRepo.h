#ifndef TEXTASSISTANT_NGRAMREPO_H
#define TEXTASSISTANT_NGRAMREPO_H

#include <string>
#include "../NGram.h"
#include "../NGramController.h"

namespace text_assistant {

    class NGramRepo {
    private:
        MysqlDbController dbController;
        string tableName;
    public:
        int n;

        void        serializeFromDb(NGramController &controller);
        void        deserializeToDb(const NGramController &controller);
        void        createTableIfNotExists();
        string      intToString(int num);

                    NGramRepo(int n, ConnectionSettings settings, string tableName = "ngrams");
    };

}

#endif //TEXTASSISTANT_NGRAMREPO_H
