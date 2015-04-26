#include <stdlib.h>
#include <stdio.h>
#include "MysqlDbController.h"

namespace text_assistant {

    MYSQL* MysqlDbController::setupConnection(ConnectionSettings settings) {
        // create a mysql instance and initialize the variables within
        _connection = mysql_init(NULL);

        // connect to the database with the details attached.
        if (!mysql_real_connect(_connection, settings.server, settings.user,
                                settings.password, settings.database, 0, NULL, 0)) {
            printf("MYSQL Conection error : %s\n", mysql_error(_connection));
            exit(1);
        }

        return _connection;
    }

    MYSQL_RES* MysqlDbController::performQuery(const char *sqlQuery) const {
        // send the sqlQuery to the database
        if (mysql_query(_connection, sqlQuery))
        {
            printf("MySQL sqlQuery error : %s\n", mysql_error(_connection));
            exit(1);
        }

        return mysql_use_result(_connection);
    }

    void MysqlDbController::iterateResult(MYSQL_RES *queryResult, function<void(MYSQL_ROW resultRow)> lambda) const {
        MYSQL_ROW resultRow = mysql_fetch_row(queryResult);

        while (resultRow != NULL) {
            lambda(resultRow);
            resultRow = mysql_fetch_row(queryResult);
        }
    }

    MysqlDbController::~MysqlDbController() {
        mysql_close(_connection);
    }
}
