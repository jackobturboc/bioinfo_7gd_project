//
// Created by User on 03.01.2025.
//

#include "console_work.hpp"

#include <conio.h>

void a() {
    bool stop = true;
    std::string console_inp;
    while (stop) {
        std::cin >> console_inp;
        if (console_inp == "stop") {
            stop = false;
        }
    }
}
