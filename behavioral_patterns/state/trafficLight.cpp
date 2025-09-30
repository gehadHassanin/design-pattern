
#include <iostream>
#include "trafficLight.h"

TrafficLightContext::TrafficLightContext(TrafficLightState* state)
    : state_(state) {} 

void TrafficLightContext::Set(TrafficLightState* state) {
    state_ = state;
}

void TrafficLightContext::Request() {
    state_->Handle();
}

void RedState::Handle() {
    std::cout << "Traffic Light is Red\n";
}

void YellowState::Handle() {
    std::cout << "Traffic Light is Yellow\n";
}

void GreenState::Handle() {
    std::cout << "Traffic Light is Green\n";
}
