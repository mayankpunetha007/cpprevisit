cmake_minimum_required(VERSION 3.13)
project(CFA_level_2)

set(CFA_level_2_VERSION_MAJOR 1)
set(CFA_level_2_VERSION_MINOR 0)
set(CFA_level_2_VERSION_PATCH 0)

add_compile_options(-lboost_system)
find_package(Boost 1.65.1 REQUIRED)

message(STATUS "---------------------")
message(STATUS "Boost_FOUND: ${Boost_FOUND}")
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "---------------------")

if(Boost_FOUND)
    message("BOOST Found")
    include_directories(${Boost_INCLUDE_DIRS})
    add_library(CFA_level_2 quant/Regression.h quant/Regression.cpp quant/test.cpp ${Boost_LIBRARY_DIRS})
    #enable_testing()
    #include(CTest)
    #add_test(CFA_level_2 test )
    SET_TARGET_PROPERTIES(CFA_level_2 PROPERTIES LINKER_LANGUAGE CXX)
    add_executable(try1 quant/test.cpp)
    add_executable(try2 quant/test.cpp ${Boost_LIBRARY_DIRS})
    target_link_libraries(CFA_level_2 ${Boost_LIBRARIES})

endif()

set(CMAKE_CXX_STANDARD 11)



