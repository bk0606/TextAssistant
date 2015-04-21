cmake_minimum_required(VERSION 3.1)
project(TextAssistant)
set (APP_NAME TextAssistant)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCE_FILES src/main.cpp)
add_executable(${APP_NAME} ${SOURCE_FILES} src/NGram.cpp src/NGram.h src/database/MysqlDbController.cpp src/database/MysqlDbController.h src/database/ConnectionSetting.h src/NGramController.cpp src/NGramController.h)

include_directories(/usr/include/mysql/)

target_link_libraries( ${APP_NAME} mysqlclient )
target_link_libraries( ${APP_NAME} mysqlcppconn )
# target_link_libraries( ${APP_NAME} mysqlpp )
