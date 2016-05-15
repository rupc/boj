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
vector<int> friendship(100000, 0);
void genProbSolver::process_input(istream &pin) {
    unsigned N, M;
    pin >> N >> M;
    int A, B;
    for (size_t i = 0; i < M; i++) {
        scanf("%d %d", &A, &B);
        friendship[A-1]++;
        friendship[B-1]++;
    }
    /*while(pin >> A >> B) {
        friendship[A-1]++;
        friendship[B-1]++;
    }*/
    for (size_t i = 0; i < N; i++) {
        printf("%d\n", friendship[i]);
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


