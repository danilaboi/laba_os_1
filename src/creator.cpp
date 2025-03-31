#include "employee.h"  
#include <iostream> 
#include <vector>     
#include <cstdlib>  
#include <iomanip> 
#include <windows.h>  

int main(int argc, char* argv[]) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (argc != 3) {
        std::cerr << "�������������: Creator <��� �����> <���������� �����������>\n";
        return 1;
    }

    std::string filename = argv[1];
    int count = std::atoi(argv[2]);
    if (count <= 0) {
        std::cerr << "������: ������������ ���������� �����������\n";
        return 1;
    }

    std::vector<Employee> employees;
    employees.reserve(count);


    for (int i = 0; i < count; ++i) {
        Employee emp;
        std::cout << "������� ID, ���, ���� ������ (����� ������): ";
 
        std::cin >> emp.num >> std::setw(10) >> emp.name >> emp.hours;
        if (!std::cin) {  
            std::cerr << "������ ����� ������.\n";
            return 1;
        }
        employees.push_back(emp);  
    }

    if (!EmployeeManager::saveToBinaryFile(filename, employees)) {
        std::cerr << "������ ������ � ����.\n";
        return 1;
    }

    std::cout << "���� ������� ������: " << filename << std::endl;
    return 0;
}
