#include "Interface_sale_data.h"
#include <iostream>
#include <string>

double QT_Sum(double salary[], int choice) {
    double sum = 0;
    switch (choice) {
        case 1:
            for (int month = 0; month < 3; month++) {
                sum+= salary[month];
            }
            break;
        case 2:
            for (int month = 3; month < 6; month++) {
                sum+= salary[month];
            }
            break;
        case 3:
            for (int month = 6; month < 9; month++) {
                sum+= salary[month];
            }
            break;
        case 4:
            for (int month = 9; month < 12; month++) {
                sum+= salary[month];
            }
            break;
deafult:
            std::cout << "illegal Choice !!" << std::endl;
    }
    return sum;
}

double QT_Total (sale_data employee[], int choice) {
    double sum = 0;
    switch (choice) {
        case 1:
            for (int index = 0; index < 6; index++) {
                sum+= employee[index].QT[0];
            }
            break;
        case 2:
            for (int index = 0; index < 6; index++) {
                sum+= employee[index].QT[1];
            }
            break;
        case 3:
            for (int index = 0; index < 6; index++) {
                sum+= employee[index].QT[2];
            }
            break;
        case 4:
            for (int index = 0; index < 6; index++) {
                sum+= employee[index].QT[3];
            }
            break;
deafult:
            std::cout << "illegal Choice" << std::endl;
    }
    return sum;
}

void Max_Sale_Person(sale_data employee[], std::string& id, double& max) {
    for (int index = 0; index < 6; index++) {
        for (int largeIndex = index + 1; largeIndex < 6; largeIndex++) {
            if (employee[index].total_salary < employee[largeIndex].total_salary) {
                max = employee[largeIndex].total_salary;
                id  = employee[largeIndex].id;
            }
        }
    }
}


