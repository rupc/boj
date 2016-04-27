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
    int N, A, B, C;
    pin >> N >> A >> B >> C;
    std::vector<int> cals;
    int t;
    while (pin >> t) {
        cals.push_back(t);
    }
    const int dou_cost = A;
    const int dou_cal = C;
    const int toping_cost = B;
    
    std::sort(cals.begin(), cals.end(), greater<int>());
    std::vector<int> cal_per_dollar(N+1);
    for (unsigned i = 0; i < cal_per_dollar.size(); ++i) {
        int toping_cal = 0;
        for (unsigned j = 0; j < i; ++j) {
            toping_cal += cals[j];
        }
        cal_per_dollar[i] = 
            (dou_cal + toping_cal) / (dou_cost + toping_cost * i); 
    } 
    int best_choice
        = *std::max_element(cal_per_dollar.begin(), cal_per_dollar.end());
    std::cout << best_choice;
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


