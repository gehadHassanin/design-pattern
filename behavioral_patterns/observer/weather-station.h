#pragma once 
#include <vector>
#include <string>

class Observer {
 public:
    virtual void Update(float temp, float hum, float pres) = 0;
};

class Subject {
  public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
};

class WeatherStation : public Subject {
  public:
    void attach(Observer* observer) override;
    void detach(Observer* observer) override;
    void notifyObservers() override;    
    void SetMeasurements(float temp, float hum, float pres);
  private:
    std::vector<Observer*> observers;
    float temp_;
    float hum_;
    float pres_;
};

class Disblay : public Observer {
  public:
    Disblay(std::string name);
    void Update(float temp, float hum, float pres) override;
  private:
    std::string name_;
};