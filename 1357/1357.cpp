// input, output 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
// container
#include <vector>
#include <array>
#include <list>
#include <map>
#include <set>
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
    string X, Y, Z;
    int rx, ry, rz;
    pin >> X >> Y;
    reverse(X.begin(), X.end());
    reverse(Y.begin(), Y.end());
    rx = stoi(X);
    ry = stoi(Y);
    rz = rx + ry;
    Z = to_string(rz);
    reverse(Z.begin(), Z.end());

    cout << stoi(Z);
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


