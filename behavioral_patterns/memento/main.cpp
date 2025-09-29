/**
 * @file main.cpp
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

#include "textEditor.h"

int main() {
    Document document("Hi, ");
    History history;

    document.Write("I'm here");
    history.AddMemento(document.CreateMoment());

    document.Write(" to help you ");
    history.AddMemento(document.CreateMoment());

    document.Write("i mistack");
    history.AddMemento(document.CreateMoment());

    std::cout << "before undo: " << document.GetContent() << std::endl;

    history.GetMemento(document);

    std::cout << "after undo: " << document.GetContent() << std::endl;

}