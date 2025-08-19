#pragma once 
#include <string>
#include <vector>

// Receiver 
class ElectronicDevice {
 public:
   ElectronicDevice(std::string name);
   void TurnOn();
   void TurnOff();
 private:
   std::string name_;
};

// Command 
class Command {
 public:
   virtual void Execute() = 0;
};

// Concrete Commands

// 1- Turn on command
class TurnOnCommand : public Command {
 public:
   TurnOnCommand(ElectronicDevice& elecDev);
   void Execute() override;
 private:
   ElectronicDevice& electronicDevice_;
};

// 2- Turn off command
class TurnOffCommand : public Command {
 public:
   TurnOffCommand(ElectronicDevice& elecDev);
   void Execute() override;
 private:
   ElectronicDevice& electronicDevice_;  
};

// Invoker
class RemoteControl {
 public:
   void AddCmd(Command* cmd);
   void PressButton(int slot);
 private:
   std::vector<Command*> cmds_;
};

