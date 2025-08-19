#include "remote_control.h"

int main() {
    ElectronicDevice tv("TV");
    ElectronicDevice lights("Lights");

    TurnOnCommand tvOn(tv);
    TurnOnCommand lightsOn(lights);
    TurnOffCommand tvOff(tv);
    TurnOffCommand lightsOff(lights);

    RemoteControl remote;

    // Button 0: Turn on TV
    remote.AddCmd(&tvOn); 
    // Button 1: Turn off TV
    remote.AddCmd(&tvOff); 
    // Button 2: Turn on Lights
    remote.AddCmd(&lightsOn); 
    // Button 3: Turn off Lights
    remote.AddCmd(&lightsOff); 


    remote.PressButton(0);
    remote.PressButton(3);
    remote.PressButton(1);
    remote.PressButton(2);
}