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
#include <deque>
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
void genProbSolver::process_input(istream &pin) {
    int R, C, ZR, ZC;
    pin >> R >> C >> ZR >> ZC;
    std::vector<vector<char>> newspaper(R, vector<char>(C, '.'));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf(" %c", &newspaper[i][j]);
        }
    }
    const int ex_col = C * ZC;
    const int ex_row = R * ZR;
    std::vector<vector<char>> extended(ex_row, vector<char>(ex_col, '#'));
    std::vector<vector<char>> extended_col(R, vector<char>(ex_col, '&'));
     //col extension
    //std::cout << extended[0].size();

    for (int k = 0; k < R; k++) {
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < ZC; j++) {
                extended_col[k][i*ZC+j] = newspaper[k][i]; 
            }
        }
    }

    /*for (int i = 0; i < extended_col.size(); ++i) {
        for (int j = 0; j < extended_col[i].size(); ++j) {
            std::cout << extended_col[i][j];
        }
        std::cout << std::endl;
    } */
    // row extension
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < ZR; j++) {
            copy(extended_col[i].begin(), extended_col[i].end(), extended[i*ZR+j].begin());
            //extended[i*ZR+j][k] = extended_col[i][k]; 
        }
    }
    //std::cout << extended.size();
    for (size_t i = 0; i < extended.size(); ++i) {
        for (size_t j = 0; j < extended[i].size(); ++j) {
            printf("%c", extended[i][j]);
        }
        if (i != extended.size() - 1) std::cout << std::endl; 
    } 
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


