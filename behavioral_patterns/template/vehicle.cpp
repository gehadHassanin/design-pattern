/**
 * @file vehicle.cpp
 * @author 
 * @brief 
 * @version 0.1
 * @date 2025-10-16
 * 
 * @copyright Copyright (c) 2025
 * 
 * 
 */

#include "vehicle.h"

#include <iostream>

void VehicleTemplate::BuildVehicle() {
    AssempleBody();
    InstallEngine();
    AddWheels();
}

void Car::AssempleBody() {
    std::cout << "Assembling car body" << std::endl;
}

void Car::InstallEngine() {
    std::cout << "Installing car engine" << std::endl;    
}

void Car::AddWheels() {
    std::cout << "Add 4 wheels to the  car" << std::endl; 
}

void MotorCycle ::AssempleBody() {
    std::cout << "Assembling motorCycle body" << std::endl;
}

void MotorCycle ::InstallEngine() {
    std::cout << "Installing motorCycle engine" << std::endl;    
}

void MotorCycle ::AddWheels() {
    std::cout << "Add 2 wheels to the motorCycle" << std::endl; 
}