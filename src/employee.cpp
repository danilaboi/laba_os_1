#include "employee.h"  
#include <iostream>
#include <fstream>


void Employee::print() const {

    std::cout << num << " " << name << " " << hours << std::endl;
}

bool EmployeeManager::saveToBinaryFile(const std::string& filename,
    const std::vector<Employee>& employees)
{
    std::ofstream file(filename.c_str(), std::ios::binary);
    if (!file)
        return false;

    for (std::vector<Employee>::const_iterator it = employees.begin();
        it != employees.end();
        ++it)
    {
        file.write(reinterpret_cast<const char*>(&(*it)), sizeof(Employee));
    }
    return file.good();
}

std::vector<Employee> EmployeeManager::loadFromBinaryFile(const std::string& filename)
{
    std::vector<Employee> employees; 
    std::ifstream file(filename.c_str(), std::ios::binary);
    if (!file)
        return employees;  

    Employee emp;
    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        employees.push_back(emp);
    }

    return employees; 
}
