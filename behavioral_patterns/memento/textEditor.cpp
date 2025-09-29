/**
 * @file textEditor.cpp
 * @author 
 * @brief 
 * @version 0.1
 * @date 2025-09-29
 * 
 * @copyright Copyright (c) 2025
 * 
 * 
 */

#include "textEditor.h"

Memento::Memento(std::string content) : content_(content) {}

void Memento::SetState(const std::string& content) {
    content_ = content;
}

std::string Memento::GetState() const {
    return content_;
}

Document::Document(const std::string& content) 
    : content_(content) {}

void Document::Write(const std::string& text) {
    content_ += text;
}

Memento Document::CreateMoment() {
    return Memento(content_);
}

std::string Document::GetContent() const {
    return content_;
}

void Document::Restore(Memento& memento) {
    content_ = memento.GetState();
}

void History::AddMemento(Memento memento) {
    history_.push(memento);
}

void History::GetMemento(Document& doc) {
    history_.pop();
    doc.Restore(history_.top());
}