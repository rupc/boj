// input, output 
#include <iostream>
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
#include <string>
//
// #define DEBUG
using namespace std;
// Declaration of variables
vector<string> words;
int N;

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
    pin >> N;
    string tmp("");
    while(pin >> tmp) words.push_back(tmp);
}
void genProbSolver::echo_input() {
    for(const auto &p : words) {
        cout << p << endl;
    }
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


