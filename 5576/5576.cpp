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
    std::vector<int> W(10);
    std::vector<int> K(10);
    for (int i = 0; i < 10; i++) {
        pin >> W[i];
    }
    for (int i = 0; i < 10; i++) {
        pin >> K[i];
    }
    std::sort(W.begin(), W.end(), greater<int>());
    std::sort(K.begin(), K.end(), greater<int>());
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 3; i++) {
        sum1 += W[i];
        sum2 += K[i];
    }
    std::cout << sum1 << " " << sum2;
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

