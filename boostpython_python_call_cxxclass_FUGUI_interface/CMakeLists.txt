cmake_minimum_required(VERSION 2.8.11)
project(helloworld)

set(CMAKE_CXX_STANDARD 11)

find_package(PythonInterp)
find_package(PythonLibs)
find_package(Boost COMPONENTS python)

#include_directories(/usr/include /usr/include/python2.7)
include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
link_libraries(${BOOST_LIBRARIES} ${PYTHON_LIBRARIES})

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
add_library(CalculateSkuidNum SHARED
            CalculateSkuidNum.h CalculateSkuidNum.cpp
            interface.cpp)
set_target_properties(CalculateSkuidNum PROPERTIES PREFIX "")

#target_link_libraries(hello python2.7 boost_python)
target_link_libraries(CalculateSkuidNum boost_python ${BOOST_LIBRARIES} ${PYTHON_LIBRARIES})
