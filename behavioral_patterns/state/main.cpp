#include <memory>
#include "trafficLight.h"

int main() {
    std::unique_ptr<TrafficLightState> state = 
    std::make_unique<RedState>();
    TrafficLightContext trafficLight(state.get());
    
    trafficLight.Request();

    state = std::make_unique<GreenState>();
    trafficLight.Set(state.get());
    trafficLight.Request();

    state = std::make_unique<YellowState>();
    trafficLight.Set(state.get());
    trafficLight.Request();
    return 0;
}