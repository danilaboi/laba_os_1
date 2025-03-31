#include "employee.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <windows.h>

int main(int argc, char* argv[]) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (argc != 4) {
        std::cerr << "�������������: Reporter <�������� ����> <���� ������> <������>\n";
        return 1;
    }

    std::string binFile = argv[1];
    std::string reportFile = argv[2];
    double rate = std::atof(argv[3]);

    std::vector<Employee> employees = EmployeeManager::loadFromBinaryFile(binFile);
    if (employees.empty()) {
        std::cerr << "������ �������� ����� ��� ���� ����.\n";
        return 1;
    }
    std::ofstream report(reportFile.c_str());
    if (!report) {
        std::cerr << "������ �������� ������.\n";
        return 1;
    }

    report << "����� �� ����� \"" << binFile << "\"\n";
    report << "ID | ��� | ���� | ��������\n";

    for (std::vector<Employee>::const_iterator it = employees.begin(); it != employees.end(); ++it) {
        const Employee& emp = *it;
        double salary = emp.hours * rate;
        report << emp.num << " " << emp.name << " " << emp.hours << " " << salary << "\n";
    }

    std::cout << "����� ������� ������: " << reportFile << std::endl;
    return 0;
}
