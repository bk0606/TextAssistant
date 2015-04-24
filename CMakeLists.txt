cmake_minimum_required(VERSION 3.1)
project(TextAssistant)
set (APP_NAME TextAssistant)

### C++ Standart
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

### Sources directory
set (SRC_DIR ${PROJECT_SOURCE_DIR}/src)

### Build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/builds)

### Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

### Adding source
set(SOURCE_FILES src/main.cpp)
add_executable(${APP_NAME} ${SOURCE_FILES} src/NGram.cpp src/NGram.h src/database/MysqlDbController.cpp src/database/MysqlDbController.h src/database/ConnectionSetting.h src/NGramController.cpp src/NGramController.h src/utils/ArgsParser.cpp src/utils/ArgsParser.h src/tests/NGramControllerTest.h src/utils/TextParser.cpp src/utils/TextParser.h)

### Mysql
include_directories(/usr/include/mysql/)

### Libs
target_link_libraries( ${APP_NAME} mysqlclient )
target_link_libraries( ${APP_NAME} mysqlcppconn )
target_link_libraries( ${APP_NAME} ${GTEST_LIBRARIES} pthread )
# target_link_libraries( ${APP_NAME} boost_regex )
# target_link_libraries( ${APP_NAME} mysqlpp )

