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
int one, zero;
int fibonacci(int n) {
    if(n == 0) {
        zero++;
        return 0;
    } else if( n == 1 ) {
        one++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n -2);
    }
}
void genProbSolver::process_input(istream &pin) {
    int n;
    int N;
    pin >> N;
    while(pin >> n) {
        fibonacci(n);
        cout << zero << " " << one << endl;
        one = zero = 0;
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


