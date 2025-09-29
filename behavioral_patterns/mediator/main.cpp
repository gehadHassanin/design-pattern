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

#include "chatRoom.h"

int main() {
    auto googleRoom = std::make_shared<GoogleRoom>();

    auto gehad = std::make_shared<Person>("gehad", googleRoom);
    auto hager = std::make_shared<Person>("hager", googleRoom);

    googleRoom->Join(hager);
    googleRoom->Join(gehad);

    gehad->Say("Hello, everyone");
    hager->Pm("gehad", "Hi gehad");

}