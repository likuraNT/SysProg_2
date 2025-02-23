cmake_minimum_required(VERSION 3.17.0)

project(utility VERSION 1.0)

set(DIR_INCLUDE headers)

add_library(${PROJECT_NAME}_objects OBJECT
    functions/usr.c
    functions/prcs.c
    functions/help.c
)

target_include_directories(${PROJECT_NAME}_objects PRIVATE ${DIR_INCLUDE})

add_executable(${PROJECT_NAME} functions/main.c)
target_include_directories(${PROJECT_NAME} PRIVATE ${DIR_INCLUDE})

target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_objects)
