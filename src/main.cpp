#include <windows.h> 
#include "employee.h"
#include <iostream> 
#include <string>
#include <fstream>  
#include <sstream> 

void runProcess(const std::string& command) {
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));   
    si.cb = sizeof(si);          
    ZeroMemory(&pi, sizeof(pi));  

    if (!CreateProcessA(NULL, (LPSTR)command.c_str(), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        std::cerr << "Ошибка запуска " << command << "\n";
        exit(1);  
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    DWORD exitCode;
    GetExitCodeProcess(pi.hProcess, &exitCode);
    if (exitCode != 0) {
        std::cerr << "Ошибка: процесс " << command << " завершился с кодом " << exitCode << "\n";
        exit(exitCode);
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

std::string intToStr(int num) {
    std::stringstream ss;
    ss << num;
    return ss.str();
}

std::string doubleToStr(double d) {
    std::stringstream ss;
    ss << d;
    return ss.str();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string binFile, reportFile;
    int count;
    double rate;

    std::cout << "Введите имя бинарного файла: ";
    std::cin >> binFile;

    std::cout << "Введите количество сотрудников: ";
    std::cin >> count;


    std::string creatorCmd = "Creator.exe " + binFile + " " + intToStr(count);
    runProcess(creatorCmd); 

    std::cout << "Введите имя отчёта: ";
    std::cin >> reportFile;
    std::cout << "Введите оплату за час: ";
    std::cin >> rate;
 
    std::string reporterCmd = "Reporter.exe " + binFile + " " + reportFile + " " + doubleToStr(rate);
    runProcess(reporterCmd); 
    std::vector<Employee> employees = EmployeeManager::loadFromBinaryFile(binFile);
    std::cout << "\nСодержимое бинарного файла:\n";
    for (const auto& emp : employees) {
        emp.print();
    }

    std::cout << "Готово! Содержимое отчёта:\n";
    std::ifstream report(reportFile.c_str());
    if (report) {
        std::cout << report.rdbuf();
    }
    else {
        std::cerr << "Ошибка чтения отчёта\n";
    }

    return 0;  
}
