#include <iostream>
#include <mysql_driver.h>
#include <gtest/gtest.h>
#include "tests/NGramControllerTest.h"
#include "tests/TextParserTests.h"

#include "utils/ArgsParser.h"
#include "utils/TextParser.h"

#include "database/ConnectionSetting.h"
#include "database/MysqlDbController.h"
#include "database/NGramRepo.h"
#include "NGramController.h"

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

    NGramRepo repo(3, settings);

    NGramController nGramController(repo);

    nGramController.learnOnTextFile("/home/albert/Dropbox/Code/Cpp/TextAssistant/resources/learn_input");

//    nGramController.nGrams.push_back(NGram(120, {"саша", "шаша", "шуша", "шутит"}));
//    nGramController.nGrams.push_back(NGram(10, {"саша", "грязно", "лапал", "нюшу"}));
//    nGramController.nGrams.push_back(NGram(10, {"я", "сильно", "люблю", "катю"}));

//    repo.deserializeToDb(nGramController);

//    repo.serializeFromDb(nGramController);

    cout << "\n" << nGramController.toString() << "\n";

    return EXIT_SUCCESS;
}
