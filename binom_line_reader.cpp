//
// Created by User on 28.12.2024.
//

#include "binom_line_reader.hpp"

#include <iostream>


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
    std::string loader;
    subsequence elem;
    for (int i = 0; i < all_file.size(); i++) {
        std::cout << all_file[i];
        if (all_file[i] == '>') {
            subsequence elem;
            is_read = true;

        }
        if (nw_read) {
            if (all_file[i] == '\n') {
                elem.title = loader;
                loader = "";
                nw_read = false;
            }
        }
        if (!nw_read) {
            if (all_file[i] == ' ') {
                elem.sector = loader;
                loader = "";
                is_read = false;
                std::cout << elem.title << std::endl;
                std::cout << elem.sector << std::endl;
                subsequences.push_back(elem);
                nw_read = true;
            }
        }

        if (is_read){loader += all_file[i];}
    }
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