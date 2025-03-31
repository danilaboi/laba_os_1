#include <gtest/gtest.h>
#include "../src/employee.h"

TEST(EmployeeTest, SaveAndLoad) {
    std::vector<Employee> employees;

    Employee e1 = { 1, "Alice", 35.5 };
    Employee e2 = { 2, "Bob", 42.0 };
    employees.push_back(e1);
    employees.push_back(e2);

    ASSERT_TRUE(EmployeeManager::saveToBinaryFile("test_employees.dat", employees));

    std::vector<Employee> loaded = EmployeeManager::loadFromBinaryFile("test_employees.dat");


    ASSERT_EQ(loaded.size(), 2U);
    EXPECT_EQ(loaded[0].num, 1);
    EXPECT_STREQ(loaded[0].name, "Alice");
    EXPECT_DOUBLE_EQ(loaded[0].hours, 35.5);

    EXPECT_EQ(loaded[1].num, 2);
    EXPECT_STREQ(loaded[1].name, "Bob");
    EXPECT_DOUBLE_EQ(loaded[1].hours, 42.0);
}
