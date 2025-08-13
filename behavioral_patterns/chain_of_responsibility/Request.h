
#pragma once
#include <iostream>

class RequestType {
 public:
    RequestType(double mount);
    double GetAmount() const;
 private:
    double amount_;
};

// Abstract Handler class
class Approver {
 public:
    void SetNext(Approver* next);
    virtual void ProcessRequest(const RequestType& typeOfRequest) = 0;
 protected:
    Approver* next_;
};

// Concrete Handler 1: JuniorManager
class JuniorManager : public Approver {
  public:
    void ProcessRequest(const RequestType& typeOfRequest) override;
};

// Concrete Handler 2: SeniorManager
class SeniorManager : public Approver {
  public:
    void ProcessRequest(const RequestType& typeOfRequest) override;
};

// Concrete Handler 3: Director
class Director : public Approver {
  public:
    void ProcessRequest(const RequestType& typeOfRequest) override;
};