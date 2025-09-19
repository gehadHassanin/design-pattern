#pragma once
#include <string>
#include<vector>


class Employee {
 public:
    Employee(std::string name, double salary);
    std::string Get_name() const;
    double Get_salary() const;
 private:
    std::string name_;
    double salary_;
};

template <typename T>
class Iterator {
 public:
    virtual bool Has_next() = 0;
    virtual T Get_next() = 0;
};

class EmployeeIterator : public Iterator<Employee*> {
 public:
    using Employee_List = std::vector<Employee*>&;
    EmployeeIterator(Employee_List employees);
    bool Has_next();
    Employee* Get_next();
 private:
    Employee_List employees_;
    int current_pos_;
};

template <typename T>
class Aggregate {
 public:
    virtual Iterator<T>* CreateIterator() = 0;
};

template<typename T>
class Company : public Aggregate<T> {
 public:
    using List = std::vector<T>&;
    Company(List employees);
    Iterator<T>* CreateIterator();
    ~Company() {};
 private:
    List employees_;
};