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
    int D, K;
    pin >> D >> K;
    int fibs[31];
    fibs[0] = 0;
    fibs[1] = 1;
    for (int i = 2; i < 31; i++) {
        fibs[i] = fibs[i-1] + fibs[i-2];
    }
    int first_day;
    int second_day;
    bool found = false;

    for (int i = 1; i < 100000; i++) {
        for (int j = 1; j < 100000; j++) {
            if (fibs[D-2] * i == K - j*fibs[D-1]) {
                found = true;
                first_day = i;
                second_day = j;
            }
        }
        if (found) {
            break;
        }
    }
    std::cout << first_day << std::endl;    
    std::cout << second_day << std::endl;
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


