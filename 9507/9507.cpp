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
#include <cstdint>
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
long long modi_fib(int n) {
    vector<long long> fibs(68);
    fibs[0] = 1;
    fibs[1] = 1;
    fibs[2] = 2;
    fibs[3] = 4;
    if(n <= 3) return fibs[n];

    for (int i = 4; i <= n; i++) {
        fibs[i] = fibs[i-1] + fibs[i-2] + fibs[i-3] + fibs[i-4];
    }
    return fibs[n];
}
void genProbSolver::process_input(istream &pin) {
    int t;
    pin >> t;
    int tmp;
    while(pin >> tmp) {
        cout << modi_fib(tmp) << endl;
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


