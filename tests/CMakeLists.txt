project(EmployeeTests CXX)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(TEST_SOURCES
    test_employee.cpp
    test_reporter.cpp
)

add_executable(EmployeeTests ${TEST_SOURCES}
    ${CMAKE_SOURCE_DIR}/src/employee.cpp
    ${CMAKE_SOURCE_DIR}/src/employee.h
)

target_include_directories(EmployeeTests PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(EmployeeTests gtest_main)

include(GoogleTest)
gtest_discover_tests(EmployeeTests)
