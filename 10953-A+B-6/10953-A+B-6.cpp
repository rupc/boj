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
#include <cstring>
//
// #define DEBUG
using namespace std;
// Declaration of variables
int T;

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
    pin >> T;
    for (int i = 0; i < T; i++) {
        string s("");
        int t1, t2;
        pin >> s;
        auto comma = find(s.begin(), s.end(), ',');
        /*t1 = atoi(string(s.begin(), comma).c_str());
        t2 = atoi(string(comma + 1, s.end()).c_str());*/
        t1 = stoi(string(s.begin(), comma));
        t2 = stoi(string(comma + 1, s.end()));
        cout << t1 + t2 << endl;

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


