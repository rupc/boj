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
int N, S;
int cnt;
vector<int> element;
vector<bool> subsets;
bool is_first = true;
void sum_of_subsets(int idx, int weight) {
    if(weight == S) {
        cnt++;
    } else if(idx == N-1) {
        return;
    } else {
        subsets[idx+1] = true;
        sum_of_subsets(idx+1, weight + element[idx+1]);
        subsets[idx+1] = false;
        sum_of_subsets(idx+1, weight);
    }
}
void solve_sum_of_subsets() {
    for (int i = 0; i < N; i++) {
        sum_of_subsets(i - 1, element[i]);
    }
}
void genProbSolver::process_input(istream &pin) {
    pin >> N >> S;
    int tmp;
    while(pin >> tmp) {
        element.push_back(tmp);
        subsets.push_back(false);
    }
    solve_sum_of_subsets();
    cout << cnt;
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


