#ifndef STATE_TRAFFICLIGHT_H_
#define STATE_TRAFFICLIGHT_H_

class TrafficLightState {
 public:
    virtual void Handle() = 0;
};

class TrafficLightContext {
 public:
    TrafficLightContext(TrafficLightState* state);
    void Set(TrafficLightState* state);
    void Request();
 private:
    TrafficLightState* state_;
};

class RedState : public TrafficLightState {
 public:
    void Handle() override;
};

class YellowState : public TrafficLightState {
 public:
    void Handle() override;
};

class GreenState : public TrafficLightState {
 public:
    void Handle() override;
};

#endif  //  STATE_TRAFFICLIGHT_H_
