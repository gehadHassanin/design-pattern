/**
 * @file textEditor.h
 * @author 
 * @brief 
 * @version 0.1
 * @date 2025-09-29
 * 
 * @copyright Copyright (c) 2025
 * 
 * 
 */

#ifndef MEMENTO_TEXTEDITOR_H_
#define MEMENTO_TEXTEDITOR_H_

#include <memory>
#include <string>
#include <stack>

class Memento {
 public:
    Memento(std::string content);
    void SetState(const std::string& content);
    std::string GetState() const;
 private:
    std::string content_;
};

class Document {
 public:
    Document(const std::string& content);
    void Write(const std::string& text);
    std::string GetContent() const;
    Memento CreateMoment();
    void Restore(Memento& memento);
 private:
    std::string content_;
};

class History {
 public:
    void AddMemento(Memento memento);
    void GetMemento(Document& doc);
 private: 
    std::stack<Memento> history_;
};

#endif  //  MEMENTO_TEXTEDITOR_H_