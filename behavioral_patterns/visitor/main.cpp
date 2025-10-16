/**
 * @file main.cpp
 * @author 
 * @brief 
 * @version 0.1
 * @date 2025-10-16
 * 
 * @copyright Copyright (c) 2025
 * 
 * 
 */

#include <iostream>

#include "shape_operations.h"

int main() {
    Circule circule(2);
    Square square(4);
    Triangle traingle(3, 2);

    CalculateArea visitor;
    circule.Accept(visitor);
    square.Accept(visitor);
    traingle.Accept(visitor);

    std::cout << "total area = " << visitor.GetTotalArea() 
        << std::endl;
}