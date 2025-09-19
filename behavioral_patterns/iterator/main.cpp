#include <iostream>
#include "company_employees.h"

int main() {
    std::vector<Employee*> employees;
    employees.push_back(new Employee("gehad", 2000));
    employees.push_back(new Employee("mohamed", 1000));
    employees.push_back(new Employee("wafaa", 500));
    employees.push_back(new Employee("nouh", 200));

    Company company(employees);
    Iterator<Employee*>* iterator = company.CreateIterator();

    while (iterator->Has_next()) {
        std::cout << "name: " << iterator->Get_next()->Get_name() << ", ";
        std::cout << "salary: " << iterator->Get_next()->Get_salary() 
            << std::endl;
    }

}