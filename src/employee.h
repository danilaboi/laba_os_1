#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


struct  Employee {
    int num;           
    char name[10]; 
    double hours; 
    void print() const;
};

class  EmployeeManager {
public:
    static bool saveToBinaryFile(const std::string& filename, const std::vector<Employee>& employees);

    static std::vector<Employee> loadFromBinaryFile(const std::string& filename);
};

#endif 
