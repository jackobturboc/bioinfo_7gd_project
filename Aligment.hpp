//
// Created by User on 03.01.2025.
//

#ifndef ALIGMENT_HPP
#define ALIGMENT_HPP


#include <string>
#include <stdio.h>

struct Matrix {
    Matrix(std::string ss, std::string s);
    std::string up_sequence;
    std::string dn_sequence;
    int x;
    int y;
    int * matr;
    void set(int x, int y, int value);
    int get(int x, int y);
    void print_matrix();
};

struct Score_for {
    Score_for() = default;
    Score_for(int x, int y, int z): match(x), mismath(y), gap(z) {};
    int match;
    int gap;
    int mismath;
    int compair_score(char a, char b);
};

struct NW_alg {
    NW_alg(std::string up_seq, std::string dn_seq, Score_for & scr);
    std::string up_sequence;
    std::string dn_sequence;
    Matrix * matrix;
    Score_for score;
    void sequence_aligment();
};

struct Aligmnment {
    Aligmnment(std::string up_seq, std::string dn_seq, Score_for & scr);
    std::string up_sequence;
    std::string dn_sequence;
    void run();
};

int max(int a, int b, int c);


#endif //ALIGMENT_HPP
