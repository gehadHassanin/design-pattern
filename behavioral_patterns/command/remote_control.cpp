
#include <iostream>
#include "remote_control.h"

ElectronicDevice::ElectronicDevice(std::string name) : name_(name) {}

void ElectronicDevice::TurnOn() {
    std::cout << name_ << " is ON now" << std::endl;
}

void ElectronicDevice::TurnOff() {
    std::cout << name_ << " is OFF now" << std::endl;
}

TurnOnCommand::TurnOnCommand(ElectronicDevice& elecDev) : electronicDevice_(elecDev) {}

void TurnOnCommand::Execute() {
    electronicDevice_.TurnOn();
}

TurnOffCommand::TurnOffCommand(ElectronicDevice& elecDev) : electronicDevice_(elecDev) {}

void TurnOffCommand::Execute() {
    electronicDevice_.TurnOff();
}

void RemoteControl::AddCmd(Command* cmd) {
    cmds_.push_back(cmd);    
}

void RemoteControl::PressButton(int slot) {
    if(slot >=  0 && slot < cmds_.size()) {
        cmds_[slot]->Execute();
    }
}