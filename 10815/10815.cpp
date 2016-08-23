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
#include <unordered_set>
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
    int N, M;
    pin >> N;
    int t;
    std::unordered_set<int> cards;
    for (int i = 0; i < N; i++) {
        scanf("%d", &t);
        cards.insert(t);
    }
    pin >> M;
    //std::unordered_set<int> checks;
    std::vector<int> checks(M);
    for (int i = 0; i < M; i++) {
        pin >> t;
        if (cards.find(t) != cards.end()) {
            checks[i] = true;
        } else {
            checks[i] = false;
        }
    }
    std::cout << plus<int>(10, 22);
    for (auto &p : checks) {
        //std::cout << p << " ";
        printf("%d ", p);
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


