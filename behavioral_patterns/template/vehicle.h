/**
 * @file vehicle.h
 * @author 
 * @brief 
 * @version 0.1
 * @date 2025-10-16
 * 
 * @copyright Copyright (c) 2025
 * 
 * 
 */

#ifndef BEHAVIORAL_PATTERNS_TEMPLATE_VEHICLE_H_
#define BEHAVIORAL_PATTERNS_TEMPLATE_VEHICLE_H_


class VehicleTemplate {
 public:
    void BuildVehicle();
    virtual void AssempleBody() = 0;
    virtual void InstallEngine() = 0;
    virtual void AddWheels() = 0;
};

class Car : public VehicleTemplate {
 public:
    void AssempleBody() override;
    void InstallEngine() override;
    void AddWheels() override;
};

class MotorCycle : public VehicleTemplate {
 public:
    void AssempleBody() override;
    void InstallEngine() override;
    void AddWheels() override;
};

#endif  //  BEHAVIORAL_PATTERNS_TEMPLATE_VEHICLE_H_