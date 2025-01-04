//
// Created by User on 03.01.2025.
//

#include "Aligment.hpp"

#include <iostream>


Matrix::Matrix(std::string ss, std::string s) {
    up_sequence = s;
    dn_sequence = ss;
    x = s.length() + 1;
    y = ss.length() + 1;
    matr = new int[x * y];
    for (int i = 0; i < x * y; i++) {matr[i] = 0;}
}

void Matrix::print_matrix() {
    std::cout << "      ";
    for (int i = 0; i < x - 1; i++) {
        printf("%c  ", dn_sequence[i]);
    }
    std::cout << std::endl;
    std::cout << " ";
    for (int i = 0; i < x; i++) {
        if (i > 0) {
            printf("%c", up_sequence[i - 1]);
        }
        for (int j = 0; j < y; j++) {
            printf("%3d", matr[x * i + j]);
        }
        std::cout << std::endl;
    }
}




void Matrix::set(int xx, int yy, int value) {
    // if ((x > xx) || (y > yy)) {
    //     std::cout << "(" << xx << "," << yy << ") " << ">"
    //               << " (" << x << "," << y << ")" << std::endl;
    //     return;
    // }
    matr[x * xx + yy] = value;
}

int Matrix::get(int xx, int yy) {
    return matr[x * xx + yy];
}

int max(int a, int b, int c) {
    if (a > b) {if (a > c) return a; return c;} return b;
}

NW_alg::NW_alg(std::string up_seq, std::string dn_seq, Score_for & scr) {
    up_sequence = up_seq;
    dn_sequence = dn_seq;
    matrix = new Matrix(up_sequence, dn_sequence);
    score = scr;
}

int Score_for::compair_score(char a, char b) {
    if (a == b) {return match;} return mismath;
}

void NW_alg::sequence_aligment() {
    // for (int x = 1; x < up_sequence.length() + 1; x++) {
    //     for (int y = 1; y < dn_sequence.length() + 1; y++) {
    //         matrix->set(x, y, ret_coinc(dn_sequence[x], up_sequence[y]));
    //     }
    // }
    int gap = score.gap;
    int match = 0;
    int delate = 0;
    int insert = 0;
    for (int i = 0; i < up_sequence.length() + 1; i++)  {
        matrix->set(i, 0, i * -1);
    }
    for (int i = 0; i < dn_sequence.length() + 1; i++)  {
        matrix->set(0, i, i * -1);
    }

    for (int i = 1; i < dn_sequence.length() + 1; i++) {
        for (int j = 1; j < up_sequence.length() + 1; j++) {
            match = matrix->get(i - 1, j - 1) + score.compair_score(up_sequence[j - 1], dn_sequence[i - 1]);
            delate = matrix->get(i - 1, j) + gap;
            insert = matrix->get(i, j - 1) + gap;
            // std::cout << delate << std::endl;
            matrix->set(i, j, max(match, delate, insert));
        }
    }
    matrix->print_matrix();
}

void Aligmnment::run() {
    Score_for scr(1, -1, -1);
    NW_alg alg(up_sequence, dn_sequence, scr);
}

