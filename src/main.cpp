#include <iostream>
#include <mysql_driver.h>
#include <gtest/gtest.h>
#include "database/ConnectionSetting.h"
#include "database/MysqlDbController.h"
#include "NGramController.h"
#include "utils/ArgsParser.h"
//#include "utils/TextParser.h"
#include "tests/NGramControllerTest.h"

string PROJECT_HOME("/home/albert/Dropbox/Code/Cpp/TextAssistant");
string RESOURCES (PROJECT_HOME + "/resources");

using namespace std;
using namespace text_assistant;

int main(int argc, char** argv)
{
    if (ArgsParser::isArgExists(argv, argv + argc, "-run_tests")) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }

    ConnectionSettings settings;
    settings.server = "localhost";
    settings.user = "root";
    settings.password = "defenderkella";
    settings.database = "text_assistant1";

    NGramController nGramController(4, settings);

//    nGramController.nGrams.push_back(NGram(120, {"саша", "шаша", "шуша", "шутит"}));
//    nGramController.nGrams.push_back(NGram(10, {"саша", "грязно", "лапал", "нюшу"}));
//    nGramController.nGrams.push_back(NGram(10, {"я", "сильно", "люблю", "катю"}));
//    nGramController.deserializeToDb();

//     nGramController.serializeFromDb();

//    TextParser::parseFromFile(RESOURCES + "/test_input");

    cout << "\n" << nGramController.toString();

    return EXIT_SUCCESS;
}
