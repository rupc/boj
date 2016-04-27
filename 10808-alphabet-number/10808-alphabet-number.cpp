// input, output 
#include <iostream>
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
map<char, int> table;
string target;
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
    string tmp("");
    pin >> tmp;
    for(char c = 'a'; c <= 'z'; ++c) {
        table[c] = 0;
    }
    target = tmp;
}
void genProbSolver::echo_input() {

}
void genProbSolver::process_solution() {
    for(const auto &p : target) {
        table[p]++;
    } 
}
void genProbSolver::process_output(ostream &pout) {
    for(const auto &p : table) {
        cout << p.second << " ";
    }

}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("");
    probsolver.process_input(std::cin);
    probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


