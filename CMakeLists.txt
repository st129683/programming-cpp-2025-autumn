cmake_minimum_required(VERSION 3.10)
project(Homeworks)

set(CMAKE_CXX_STANDARD 14)

file(GLOB HOMEWORK_DIRS "*-hw-*")
foreach(HOMEWORK_DIR ${HOMEWORK_DIRS})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${HOMEWORK_DIR})
        add_subdirectory(${HOMEWORK_DIR})
    endif()
endforeach()
