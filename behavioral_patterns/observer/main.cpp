#include "weather-station.h"

int main() {

    WeatherStation station;

    Disblay disblay1("disblay1");
    Disblay disblay2("disblay2");

    station.attach(&disblay1);
    station.attach(&disblay2);

    // First update
    station.SetMeasurements(25.5, 60.0, 1013.2);

    // Second update
    station.SetMeasurements(24.8, 58.0, 1014.5);
}