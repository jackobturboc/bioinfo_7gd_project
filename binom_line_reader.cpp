//
// Created by User on 28.12.2024.
//

#include "binom_line_reader.hpp"

#include <iostream>
#include <windows.h>


mass_of_subsequence::mass_of_subsequence(std::string name_of_file){ // only read file
    std::string all_file;
    std::ifstream subsequence;
    subsequence.open(name_of_file);
    std::string line_of_subsequence;
    if (subsequence.is_open()) {
        while (std::getline(subsequence, line_of_subsequence)) {
            all_file += (line_of_subsequence + "\n");
        }
    }
    spreader(all_file);
}

void mass_of_subsequence::spreader(std::string all_file) { // split all file for genom's sectors
    bool is_read = false;
    bool nw_read = true;
    int counter = 0;
    std::string loader;
    subsequence elem;
    for (int i = 0; i < all_file.size(); i++) {
        if (all_file[i] == ';') {
            if (counter == 1) {
                elem.title = loader;
                nw_read = true;
                loader = "";
                is_read = true;
            } else {
                counter++;
                elem.sector = loader;
                subsequences.push_back(elem);
                elem.sector = "";
                elem.title = "";
                loader = "";
                is_read = true;
            }
        }
        if (all_file[i] == '>') {
            elem.sector = loader;
            nw_read = true;
            subsequences.push_back(elem);
            elem.sector = "";
            elem.title = "";
            loader = "";
            is_read = true;
        }
        if (nw_read) {
            if (all_file[i] == '\n') {
                if (counter == 2) {elem.subtitle = loader;}
                elem.title = loader;
                loader = "";
                nw_read = false;
            }
        }
        if (is_read){loader += all_file[i];}
        else {trash += all_file[i];}

    }
    elem.sector = loader;
    subsequences.push_back(elem);

    std::cout << elem.title << std::endl;
    std::cout << elem.sector << std::endl;
    std::cout << trash << std::endl;
}

int flenght(std::string name) { // lenght of file (only before open file)
    std::ifstream file;
    file.open(name);
    std::string line;
    int counter = 0;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            counter++;
        }
    }
    return counter;
}