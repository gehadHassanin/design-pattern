#include "Request.h"

RequestType::RequestType(double amount) : 
    amount_(amount) {}

double RequestType::GetAmount() const {
    return amount_;
}

// Abstract Handler class
void Approver::SetNext(Approver* next) {
    next_ = next;
}

// Concrete Handler 1: JuniorManager
void JuniorManager::ProcessRequest(const RequestType& request) {
    if (request.GetAmount() <= 500) {
        std::cout << "JuniorManager" << " approved request for $" 
            << request.GetAmount() << std::endl;
    }else if (next_) {
        std::cout << "JuniorManager"  << " cannot approve, forwarding to next approver\n";
        next_->ProcessRequest(request);
    }else {
         std::cout << "Request for $" << request.GetAmount() 
            <<  " cannot be approved by anyone." << std::endl;
    }
}

// Concrete Handler 2: SeniorManager
void SeniorManager::ProcessRequest(const RequestType& request) {
    if (request.GetAmount() <= 2000) {
        std::cout << "SeniorManager" << " approved request for $" 
            << request.GetAmount() << std::endl;
    }else if (next_) {
        std::cout << "SeniorManager"  << " cannot approve, forwarding to next approver\n";
        next_->ProcessRequest(request);
    }else {
         std::cout << "Request for $" << request.GetAmount() 
            <<  " cannot be approved by anyone." << std::endl;
    }
}

// Concrete Handler 3: Director
void Director::ProcessRequest(const RequestType& request) {
    if (request.GetAmount() <= 5000) {
        std::cout << "Director" << " approved request for $" 
            << request.GetAmount() << std::endl;
    }else {
         std::cout << "Request for $" << request.GetAmount() 
            <<  " cannot be approved by anyone." << std::endl;
    }
}
