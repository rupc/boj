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
    int t;
    int sum = 0;
    while (pin >> t) {
        sum += t;
        pin.ignore();
    }
    std::cout << sum;
}
void genProbSolver::echo_input() {

}
// 10823
void genProbSolver::process_solution() {
    istream &pin(cin);
    string whole_line("");
    // ignore() needed if ">>" used
    string lbuf; // line buffer
    while (getline(pin, lbuf)) {
        whole_line += lbuf;
    }
    istringstream iss(whole_line);
    int t;
    int sum = 0;
    while (iss >> t) {
        sum += t;
        iss.ignore();
    }
    //std::cout << whole_line;
    std::cout << sum;
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


