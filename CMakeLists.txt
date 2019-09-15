cmake_minimum_required(VERSION 3.13)
project(CFA_level_2)

set(CFA_level_2_VERSION_MAJOR 1)
set(CFA_level_2_VERSION_MINOR 0)
set(CFA_level_2_VERSION_PATCH 0)



set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(Boost_INCLUDE_DIRS ON)
find_package(Boost 1.71.0)


if(Boost_FOUND)
    message("BOOST Found")
    include_directories(${Boost_INCLUDE_DIRS})
    add_library(CFA_level_2 quant/Regression.h quant/Regression.cpp quant/test.cpp)
    #enable_testing()
    #include(CTest)
    #add_test(CFA_level_2 test )
    target_link_libraries(CFA_level_2 ${Boost_LIBRARIES})
    SET_TARGET_PROPERTIES(CFA_level_2 PROPERTIES LINKER_LANGUAGE CXX)
    add_executable(test quant/test.cpp)

endif()

set(CMAKE_CXX_STANDARD 14)



