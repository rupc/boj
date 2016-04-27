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
    int T;
    pin >> T;
    unsigned N;
    while(pin >> N) {
        vector<pair<string, int>> alchohol;
        string S;
        int L;
        for (size_t i = 0; i < N; i++) {
            pin >> S >> L;
            alchohol.push_back(make_pair(S, L));
        }
        pair<string, int> holic
            = *std::max_element(alchohol.begin(), alchohol.end(),
                    [](decltype(alchohol)::value_type &p1,
                       decltype(alchohol)::value_type &p2){
                        if(p1.second < p2.second) return true;
                        else return false;
                    });
        std::cout << holic.first << std::endl;
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


