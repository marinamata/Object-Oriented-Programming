cmake_minimum_required(VERSION 3.5)
project(SortingTesting)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads REQUIRED) #needed to build google test
if(NOT IS_DIRECTORY ${PROJECT_SOURCE_DIR}/googletest) # if googletest is not a part of the project
    #go and download it
    include(FetchContent) #so we can pull in google test
    FetchContent_Declare( #declare information about google test
            googletest #its variable name
            #its location on the internet
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG main #what branch we want
            )

    #download google test if we don't have it
    FetchContent_GetProperties(googletest)
    if (NOT googletest_POPULATED)
        FetchContent_Populate(googletest)
    endif ()
    #add this to the cmake command line -DINSTALL_GTEST=OFF
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
else()
    add_subdirectory(googletest)
endif()

add_executable(SortingTesting
        test_swap.cpp
        test_min_index_of_array.cpp
        test_copy_array.cpp test_make_sorted.cpp test_get_sorted.cpp test_parse_agrs.cpp test_helpers.cpp test_helpers.h)


target_link_libraries(SortingTesting
        PRIVATE
        SortingSrc # our src code we want to test
        gtest #link in google test
        gmock #link in google mock
        gtest_main #add this one if you want to use google's basic main
        )

target_compile_options(SortingTesting PRIVATE -Wall -Werror -Wextra)
