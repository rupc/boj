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
    unsigned long long X;
    pin >> X;
    if (X == 1) {
        std::cout << "1/1";
        return;
    }
    unsigned long long n = 1;
    unsigned long long An = 1;
    while (X > An) {
        An = 1 + ((n*(n+1)) / 2);
        ++n;
    }
    --n;
    An -= n;
    X -= An;
    int num1 = 1, num2 = n;
    //std::cout << X << std::endl;
    for (unsigned long long i = 0; i < X; i++) {
        num1++;
        num2--;
    }
    if (num2 == 0) num2 = 1;
    if (n % 2 == 0) {
        std::cout << num1 << "/" << num2;
    } else {
        std::cout << num2 << "/" << num1;
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


