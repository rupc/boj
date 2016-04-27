// input, output 
#include <iostream>
#include <iomanip>
// container
#include <vector>
#include <array>
#include <list>
#include <map>
#include <set>
#include <string>
// container adaper
#include <stack>
#include <queue>
// STL algorithm related
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <memory>
#include <utility>
// C standard library
#include <cmath>
#include <cstdlib>

//
// #define DEBUG
using namespace std;
// Declaration of variables


// Declaration of auxiliary function
class genProbSolver {

    public:
        genProbSolver(string s) : name(s) {}
        void process_input(istream &);
        void process_solution();
        void process_output(ostream &);
        void echo_input();
    private:
        string name;
};
map<string, pair<int, int>> reg_table;
void genProbSolver::process_input(istream &pin) {
     reg_table["black"] = make_pair(0, 1); 
     reg_table["brown"] = make_pair(1, 10); 
     reg_table["red"] = make_pair(2, 100); 
     reg_table["orange"] = make_pair(3, 1000); 
     reg_table["yellow"] = make_pair(4, 10000); 
     reg_table["green"] = make_pair(5, 100000); 
     reg_table["blue"] = make_pair(6, 1000000); 
     reg_table["violet"] = make_pair(7, 10000000); 
     reg_table["grey"] = make_pair(8, 100000000); 
     reg_table["white"] = make_pair(9, 1000000000); 
     string s1, s2, s3;
     pin >> s1 >> s2 >> s3;
     int value = reg_table[s1].first * 10 + reg_table[s2].first;
     long long res = value * (long long)reg_table[s3].second;
     cout << res;

}

void genProbSolver::echo_input() {

}
void genProbSolver::process_solution() {
    
}
void genProbSolver::process_output(ostream &pout) {

}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("");
    probsolver.process_input(std::cin);
    probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


