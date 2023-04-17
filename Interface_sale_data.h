#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

struct sale_data {
    std::string id;
    double QT[4];
    double month_salary[12];
    double total_salary;
};

double QT_Sum(double salary_month[], int choice); // for sumation the QT salary
double QT_Total(sale_data[], int choice); // for caclualte the total QT
void Max_Sale_Person(sale_data[], std::string& id, double& max); // this for find the max salary for the all id 
void Max_Quart_Salary(sale_data[], int& quart); // this for find the max quart for the max quart










