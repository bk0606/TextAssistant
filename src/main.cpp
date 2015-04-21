#include <iostream>
#include <mysql_driver.h>
#include "database/ConnectionSetting.h"
#include "database/MysqlDbController.h"
#include "NGramController.h"

using namespace std;
using namespace text_assistant;

int main() {
    ConnectionSettings settings;
    settings.server = "localhost";
    settings.user = "root";
    settings.password = "defenderkella";
    settings.database = "text_assistant1";

    NGramController nGramController(3, settings);

//    nGramController.nGrams.push_back(NGram(3, 120, {"Саша", "Шаша", "Шуша"}));
//    nGramController.nGrams.push_back(NGram(3, 10, {"Саша", "Лапал", "Нюшу"}));
//    nGramController.nGrams.push_back(NGram(3, 10, {"Я", "Люблю", "Катю"}));
//    nGramController.deserializeToDb();

    nGramController.serializeFromDb();

    cout << "\n" << nGramController.toString();

    return 0;
}
