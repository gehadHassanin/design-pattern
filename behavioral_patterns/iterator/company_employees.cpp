#include "company_employees.h"

Employee::Employee(std::string name, double salary) 
    : name_(name), salary_(salary) {}

std::string Employee::Get_name() const { return name_; }

double Employee::Get_salary() const { return salary_; }

EmployeeIterator::EmployeeIterator(Employee_List employees) 
    : employees_(employees) { current_pos_ = 0;}

bool EmployeeIterator::Has_next() { 
    return (current_pos_)++ < employees_.size();
}

Employee* EmployeeIterator::Get_next() { 
    return employees_[current_pos_ - 1];
}

template<typename T>
Company<T>::Company(List employees) 
    : employees_(employees) {}

template<typename T>
Iterator<T>* Company<T>::CreateIterator() {
    return new EmployeeIterator(employees_);
}

template class Company<Employee*>;