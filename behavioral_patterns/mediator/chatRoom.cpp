/**
 * @file chatRoom.cpp
 * @author 
 * @brief 
 * @version 0.1
 * @date 2025-09-29
 * 
 * @copyright Copyright (c) 2025
 * 
 * 
 */

#include <iostream>
#include "chatRoom.h"

Person::Person(const std::string& name, 
std::shared_ptr<ChatRoom> chatRoom) : name_(name), chatRoom_(chatRoom) {}

const std::string& Person::Get_name() const { return name_; }

void Person::Say(const std::string& msg) {
    chatRoom_->BroadCast(name_, msg);
}

void Person::Pm(const std::string& to_name, const std::string& msg) {
    chatRoom_->SendMessage(name_, to_name, msg);
}

void Person::Receive(const std::string& from_name, const std::string& msg) {
    std::cout << from_name << ": " << msg << std::endl;
}

void GoogleRoom::Join(std::shared_ptr<Person> person) {
    std::string msg = person->Get_name() + " is joining";
    people_[person->Get_name()] = person;
    person->Receive("room", msg);
}

void GoogleRoom::BroadCast(const std::string& from_name,
const std::string& msg)  {
    for (auto& iter : people_) {
        if (iter.first != from_name) {
            iter.second->Receive(from_name, msg);
        } 
    }
}

void GoogleRoom::SendMessage(const std::string& from_name,
const std::string& to_name, const std::string& msg) {
    auto it_fromName = people_.find(from_name);
    auto it_toName = people_.find(to_name);
    if (it_fromName != people_.end() &&
        it_toName != people_.end()) {
            it_toName->second->Receive(from_name, msg); 
    }
}