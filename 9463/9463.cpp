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
#include <cstdio>
// Declaration of auxiliary function
class genProbSolver {

    public:
        genProbSolver(std::string s) : name(s) {}
        void process_input(std::istream &);
        void process_solution();
        void process_output(std::ostream &);
        void echo_input();
    private:
        std::string name;
};
void genProbSolver::process_input(std::istream &pin) {
    int T;
    pin >> T;
    while (T--) {
        int n;
        pin >> n;
        int seqs[2][n+1];
        for (int i = 1; i <= n; i++) {
            scanf("%d", &seqs[0][i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &seqs[1][i]);
        }
    }
}
void genProbSolver::echo_input() {

}
void genProbSolver::process_solution() {
    
}
void genProbSolver::process_output(std::ostream &pout) {

}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("");
    probsolver.process_input(std::cin);
    probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


