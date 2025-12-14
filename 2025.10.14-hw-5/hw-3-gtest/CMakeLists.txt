find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(bank_class_gtest main.cpp BankAccount.h)

target_link_libraries(bank_class_gtest
    ${GTEST_LIBRARIES}
    pthread
)
