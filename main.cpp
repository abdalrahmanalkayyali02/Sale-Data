#include "Interface_sale_data.h"
#include <iostream>
#include <string>
#include <iomanip>

int main(void) {
    sale_data employee[6];
    std::string list[6];
    std::string temp;
    char null_ver = '\0';
    double total_qt[4];
    double max_sale;
    double max_quart = 0;
    unsigned quart = 0;
    int counter = 0; 
    std::string id;

    // This statment for Enteries the Id and cheack the id if isit uniqe or not 
    do {
        bool found = false;
        std::cout << "Enter The employee  ID : " << std::endl;
        std::cin >> temp;
        // for cheack the id is uniqe or not 
        for (int cheack = 0; cheack < counter; cheack++) {
            if (temp == list[cheack]) {
                found = true;
                break;
            }
        }
        if (!found) {
            list[counter] = temp;
            employee[counter].id = list[counter];
            for (int month = 0; month < 12; month++) {
                std::cout << "Enter The Month " << month + 1 << " Salary : " << std::endl;
                std::cin >> employee[counter].month_salary[month];
            }
            counter++;
            std::cout << std::setw(35) << std::left << std::setfill('-') << null_ver << std::endl;
        } else {
            std::cout << "Enter Diffrent ID, The ID must be Uniqe ! " << std::endl;
        }
    } 
    while (counter < 6);

    // this statment for the set the sumation and storge it in the  Quart is the exact 
    // in this case  to the quart and storge it in it 
    for (int index = 0; index < 6; index++) {
        employee[index].QT[0] = QT_Sum (employee[index].month_salary, 1);
        employee[index].QT[1] = QT_Sum (employee[index].month_salary, 2);
        employee[index].QT[2] = QT_Sum (employee[index].month_salary, 3);
        employee[index].QT[3] = QT_Sum (employee[index].month_salary, 4);
    }
    // this statment for sumation the total Quart for each employee 
    for (int index = 0; index < 6; index++) {
        for (int quart = 0; quart < 4; quart++) {
            employee[index].total_salary+= employee[index].QT[quart];
        }
    }
    
    // this statment for sumation the total by coloume for QT
    total_qt[0] = QT_Total (employee, 1); // this for sumation the total for QT[0] 
    total_qt[1] = QT_Total (employee, 2); // this for sumation the total for QT[1]
    total_qt[2] = QT_Total (employee, 3); // this for sumation the total for QT[2]
    total_qt[3] = QT_Total (employee, 4); // this for sumation the total for QT[3]
    
    // this for find the max total for each employee[] 
    Max_Sale_Person(employee, id, max_sale);
    
    // this for find the max total for each quart and return it value
    for (int index = 0; index < 4; index++) {
        for (int large = index + 1; large < 4; large++) {
            if (total_qt[index] <= total_qt[large]) { 
                max_quart = total_qt[large];
                quart = large + 1;
            } else {
                max_quart = total_qt[index];
                quart = index + 1;
            }
        }
    }

    //-----------------This statemnt is show the output as the Report--------------------------------//
    std::cout << std::endl;
    std::cout << std::setw(25) << std::left << std::setfill('-') << null_ver 
        << " Annual Sales Report " 
        << std::setw(25) << std::setfill('-') << null_ver << std::endl;
    
    // now we will show the design
    std::cout << std::fixed << std::showpoint << std::setprecision(2) << std::setfill(' ') << null_ver;
    std::cout << std::setw(10) << std::left << "ID"  << "\t "
        << std::setw(10) << std::left << "QT1" << "\t "
        << std::setw(10) << std::left << "QT2" << "\t "
        << std::setw(10) << std::left << "QT3" << "\t "
        << std::setw(10) << std::left << "QT4" << "\t "
        << std::setw(10) << std::left << "Total" << std::endl;
    std::cout << std::setw(90) << std::setfill('_') << null_ver << std::endl;
    
    // input the data in the output file
    for (int index = 0; index < 6; index++) {
        std::cout << std::setfill(' ')
            << std::setw(10) << std::left << employee[index].id    << "\t"
            << std::setw(10) << std::left << employee[index].QT[0] << "\t"
            << std::setw(10) << std::left << employee[index].QT[1] << "\t"
            << std::setw(10) << std::left << employee[index].QT[2] << "\t"
            << std::setw(10) << std::left << employee[index].QT[3] << "\t"
            << std::setw(10) << std::left << employee[index].total_salary 
            << std::endl;
    }
    
    // This statamenf for calcaulte the total of the quart 
    std::cout << std::setw(10) << std::left << "Total" << "\t"
        << std::setw(10) << std::left << total_qt[0] << "\t"
        << std::setw(10) << std::left << total_qt[1] << "\t"
        << std::setw(10) << std::left << total_qt[2] << "\t"
        << std::setw(10) << std::left << total_qt[3] << std::endl;

    
    // This statment to show the max id saller and the ammount of it are return the id value 
    std::cout << "Max Sale by SalesPerson: ID = " << std::setw(5) << std::left << id
        << ", Amount = " << std::setw(10) << std::left << max_sale << std::endl;
    
    // This statemtn to show the max quart saler and the quart 
    std::cout << "Max Sale by Quarter: Quarter " << std::setw(5) << std::left << quart 
        << ", Amount = " << std::setw(10) << std::left << max_quart << std::endl;


    return 0;
}

