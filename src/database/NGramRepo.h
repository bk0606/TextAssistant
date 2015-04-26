#ifndef TEXTASSISTANT_NGRAMREPO_H
#define TEXTASSISTANT_NGRAMREPO_H

#include <string>
#include "../NGram.h"
#include "../NGramController.h"

namespace text_assistant {

    class NGramController;

    class NGramRepo {
    private:
        MysqlDbController dbController;
        string tableName;
    public:
        int n;



        void        serializeFromDb(NGramController &controller) const;
        void        deserializeToDb(const NGramController &controller) const;
        void        createTableIfNotExists() const;

        string      intToString(int num) const; // TODO: Move in separate class

                    NGramRepo(int n, ConnectionSettings settings, string tableName = "ngrams");
    };

}

#endif //TEXTASSISTANT_NGRAMREPO_H
