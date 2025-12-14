find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(text_editor_gtest main.cpp TextEditor.h)

target_link_libraries(text_editor_gtest 
    ${GTEST_LIBRARIES}
    pthread
)
