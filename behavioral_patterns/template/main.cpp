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

#include "vehicle.h"

int main() {
    std::cout << "Building a Car:\n";
    Car car;
    car.BuildVehicle();

    std::cout << "\nBuilding a Motorcycle:\n";
    MotorCycle motorCycle;
    motorCycle.BuildVehicle();
    return 0;
}