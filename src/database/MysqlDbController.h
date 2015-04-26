#ifndef TEXTASSISTANT_DATABASECONTROLLER_H
#define TEXTASSISTANT_DATABASECONTROLLER_H

#include <mysql.h>
#include <functional>
#include "ConnectionSetting.h"

using namespace std;

namespace text_assistant {

    class MysqlDbController {
    private:
        MYSQL* _connection;

    public:
        MYSQL*      setupConnection(ConnectionSettings settings);

        MYSQL_RES*  performQuery(const char *sqlQuery) const;

        void        iterateResult(MYSQL_RES *queryResult, function<void(MYSQL_ROW resultRow)> lambda) const;

                    ~MysqlDbController();
    };
}


#endif //TEXTASSISTANT_DATABASECONTROLLER_H
