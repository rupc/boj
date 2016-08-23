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
    int N;
    pin >> N;
    std::vector<int> pupils(N);
    std::vector<int> reorder_info(N);
    for (int i = 0; i < N; i++) {
        pin >> reorder_info[i];
        pupils[i] = i+1;
    }
    for (int i = 0; i < N; i++) {
        int relocation = reorder_info[i];
        if (relocation == 0) continue;
        int j = i;
        while (relocation-- && j > 0) {
            std::swap(pupils[j], pupils[j-1]);
            --j;
        }
    }   
    for (auto &p : pupils) {
        std::cout << p << " ";
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


