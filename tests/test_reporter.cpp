#include <gtest/gtest.h>
#include "../src/employee.h"
#include <gtest/gtest.h>
TEST(ReporterTest, SalaryCalculation) {
    Employee emp = { 3, "Charlie", 50.0 };
    double rate = 20.0;
    double expectedSalary = emp.hours * rate;

    EXPECT_DOUBLE_EQ(expectedSalary, 1000.0);
}
