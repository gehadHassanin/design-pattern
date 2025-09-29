/**
 * @file chatRoom.h
 * @author 
 * @brief 
 * @version 0.1
 * @date 2025-09-29
 * 
 * @copyright Copyright (c) 2025
 * 
 * 
 */

#ifndef MEDIATOR_CHATROOM_H_
#define MEDIATOR_CHATROOM_H_

#include <string>
#include <memory>
#include <unordered_map>

class ChatRoom {
 public:
    virtual void BroadCast(const std::string& from_name,
    const std::string& msg) = 0;
    virtual void SendMessage(const std::string& from_name,
    const std::string& to_name, const std::string& msg) = 0;
};

class Person {
 public:
    Person(const std::string& name, 
    std::shared_ptr<ChatRoom> chatRoom);
    const std::string& Get_name() const;
    void Say(const std::string& msg);
    void Pm(const std::string& to_name, const std::string& msg);
    void Receive(const std::string& from_name, const std::string& msg);
 private:
    std::string name_;
    std::shared_ptr<ChatRoom> chatRoom_;
};

class GoogleRoom : public ChatRoom {
 public:
    void Join(std::shared_ptr<Person> person);
    void BroadCast(const std::string& from_name,
    const std::string& msg) override;
    void SendMessage(const std::string& from_name,
    const std::string& to_name, const std::string& msg) override;
 private:
    using person_map = std::unordered_map<std::string, 
    std::shared_ptr<Person>>;
    person_map people_;
};

#endif  //  MEDIATOR_CHATROOM_H_