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
#include <unordered_map>
#include <unordered_set>
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
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N-1-i; j++) {
            std::cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            std::cout << "*";
            if (j != i) {
                std::cout << " ";
            }
        }
        if (i != N - 1) {
            std::cout << "\n";   
        }
    } 
}
void genProbSolver::echo_input() {
    istream &pin(cin);
    int N;
    pin >> N;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 1) {
            std::cout << " ";
        }
        for (int j = 0; j < N; j++) {
            std::cout << "*";
            if (j != N-1) {
                std::cout << " ";
            }
        }
        if (i != N-1) {
            std::cout << "\n";
        }
    }
}
void genProbSolver::process_solution() {
    
}
void genProbSolver::process_output(ostream &pout) {

}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("");
    //probsolver.process_input(std::cin);
    probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


