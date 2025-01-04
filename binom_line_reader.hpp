//
// Created by User on 28.12.2024.
//

#ifndef BINOM_LINE_READER_HPP
#define BINOM_LINE_READER_HPP


#define FILE_NAME "binom.txt"



#include <fstream>
#include <string>
#include <vector>

struct subsequence{ // sector
    std::string sector;
    std::string title;
    std::string subtitle;
};

struct mass_of_subsequence{ // mass of sectors
    mass_of_subsequence(std::string name_of_file);
    void spreader(std::string all_file);
    std::vector<subsequence> subsequences;
    std::string trash;
};


int flenght(std::string name);
#endif //BINOM_LINE_READER_HPP
