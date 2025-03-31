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
        std::cerr << "Использование: Reporter <бинарный файл> <файл отчета> <ставка>\n";
        return 1;
    }

    std::string binFile = argv[1];
    std::string reportFile = argv[2];
    double rate = std::atof(argv[3]);

    std::vector<Employee> employees = EmployeeManager::loadFromBinaryFile(binFile);
    if (employees.empty()) {
        std::cerr << "Ошибка загрузки файла или файл пуст.\n";
        return 1;
    }
    std::ofstream report(reportFile.c_str());
    if (!report) {
        std::cerr << "Ошибка создания отчета.\n";
        return 1;
    }

    report << "Отчет по файлу \"" << binFile << "\"\n";
    report << "ID | Имя | Часы | Зарплата\n";

    for (std::vector<Employee>::const_iterator it = employees.begin(); it != employees.end(); ++it) {
        const Employee& emp = *it;
        double salary = emp.hours * rate;
        report << emp.num << " " << emp.name << " " << emp.hours << " " << salary << "\n";
    }

    std::cout << "Отчет успешно создан: " << reportFile << std::endl;
    return 0;
}
