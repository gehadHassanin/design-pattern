#include <iostream>
#include <algorithm>
#include "weather-station.h"


void WeatherStation::attach(Observer* observer) {
    observers.push_back(observer);
}

void WeatherStation::detach(Observer* observer) {
    observers.erase(find(observers.begin(), observers.end(), observer));
}

void WeatherStation::notifyObservers() {
  	for (auto observer : observers) {
      	observer->Update(temp_, hum_, pres_);
    }
}

void WeatherStation::SetMeasurements(float temp, float hum, float pres) {
    temp_ = temp;
    hum_ = hum;
    pres_ = pres;
    WeatherStation::notifyObservers();
}

Disblay::Disblay(std::string name) : name_(name) {}

void Disblay::Update(float temp, float hum, float pres) {
    std::cout << name_ << ": Temperature = " << temp
              << "°C, Humidity = " << hum
              << "%, Pressure = " << pres << " hPa\n";
}


