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
bool is_perfect_square(int n) {
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return n == root * root;
}

void genProbSolver::process_input(istream &pin) {
    int M, N;
    pin >> M >> N;
    int min_sqrt = 10000;
    std::vector<int> sqrts;
    for (int i = M; i <= N; i++) {
        if(is_perfect_square(i)) {
            if(min_sqrt > i) 
                min_sqrt = i;
            sqrts.push_back(i);
        }
    }
    if (sqrts.empty()) {
        std::cout << "-1" << std::endl;
    } else {
        std::cout << std::accumulate(sqrts.begin(), sqrts.end(), 0) << std::endl;
        std::cout << min_sqrt << std::endl;
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


