cmake_minimum_required(VERSION 3.10)
project(EmployeeProject CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-DBUILD_LIBRARY)

include(CTest)
enable_testing()

set(EMPLOYEE_SRC
    src/employee.cpp
    src/employee.h
)

add_executable(Creator src/creator.cpp ${EMPLOYEE_SRC})

add_executable(Reporter src/reporter.cpp ${EMPLOYEE_SRC})

add_executable(Main src/main.cpp ${EMPLOYEE_SRC})


option(BUILD_TESTS "Build all tests" ON)
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
