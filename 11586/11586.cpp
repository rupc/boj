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
    int N;
    pin >> N;
    std::vector<std::vector<char>> mirror(N, std::vector<char>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            pin >> mirror[i][j];
        }
    } 
    int K;
    pin >> K;
    if (K == 1) {

    } else if (K == 2) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N/2; j++) {
                swap(mirror[i][j], mirror[i][N-1-j]);
            }
        }
    } else {
        for (int i = 0; i < N/2; ++i) {
            for (int j = 0; j < N; ++j) {
                swap(mirror[i][j], mirror[N-1-i][j]);
            }
        } 
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << mirror[i][j];
        }
        std::cout << std::endl;
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


