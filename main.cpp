#include <iostream>
#include "binom_line_reader.hpp"
#include "tester.hpp"
#include "Aligment.hpp"




int main(){
    // std::string line[6] = {"001_ncbi_single_simple.fasta",
    //                        "002_ncbi_two_simple.fasta",
    //                        "003_ncbi_two_with_asterics.fasta",
    //                        "004_start_with_semicolon_comment_asterics.fasta",
    //                        "005_db_description_header.fasta",
    //                        "006_ncbi_thri_wthout_devide_lines.fasta"};
    // std::string name;
    // std::string temp = PAST_TO_TEST;
    // for (int i = 0; i < 6; i++) {
    //     std::cout << i + 1 << ":" << std::endl;
    //     name = temp + "\\" + line[i];
    //     mass_of_subsequence gen_1(name);
    // }
    // Matrix n("1234", "5678");
    Score_for scr(1, -1, -1);
    NW_alg m("GCATGCU", "GATTACA", scr);
    m.sequence_aligment();
    return 0;
}
