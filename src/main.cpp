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
    settings.password = "";
    settings.database = "text_assistant1";

    NGramController nGramController(4, settings);

    nGramController.nGrams.push_back(NGram(120, {"саша", "шаша", "шуша", "шутит"}));
    nGramController.nGrams.push_back(NGram(10, {"саша", "грязно", "лапал", "нюшу"}));
    nGramController.nGrams.push_back(NGram(10, {"я", "сильно", "люблю", "катю"}));
    nGramController.deserializeToDb();

//    nGramController.serializeFromDb();

    cout << "\n" << nGramController.toString();

    return 0;
}
