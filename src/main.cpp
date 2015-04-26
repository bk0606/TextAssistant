#include <iostream>
#include <mysql_driver.h>
#include <gtest/gtest.h>
#include "database/ConnectionSetting.h"
#include "database/MysqlDbController.h"
#include "NGramController.h"
#include "utils/ArgsParser.h"
#include "utils/TextParser.h"
#include "tests/NGramControllerTest.h"

#include <tbb/tbb.h>
#include <vector>

using namespace std;
using namespace text_assistant;

tbb::concurrent_vector<int> my_list;

void addToVect(int i) {
    my_list.push_back(i);
}

int main(int argc, char** argv)
{
    if (ArgsParser::isArgExists(argv, argv + argc, "-run_tests")) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }

//    ConnectionSettings settings;
//    settings.server = "localhost";
//    settings.user = "root";
//    settings.password = "defenderkella";
//    settings.database = "text_assistant1";
//
//    NGramController nGramController(4, settings);

//    nGramController.nGrams.push_back(NGram(120, {"саша", "шаша", "шуша", "шутит"}));
//    nGramController.nGrams.push_back(NGram(10, {"саша", "грязно", "лапал", "нюшу"}));
//    nGramController.nGrams.push_back(NGram(10, {"я", "сильно", "люблю", "катю"}));
//    nGramController.deserializeToDb();

//     nGramController.serializeFromDb();

//    cout << "\n" << nGramController.toString();

//    TextParser::parseFromFile("/home/albert/Dropbox/Code/Cpp/TextAssistant/resources/test_input");

    const int size = 10000000;

    auto start = std::clock();

    tbb::parallel_for(0, size, [=](int i) {
        addToVect(i);
    });

    std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

    return EXIT_SUCCESS;
}
