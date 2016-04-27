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
void genProbSolver::process_input(istream &pin) {
    int n;
    pin >> n;
    int a, b, c;
    int scenario_cnt = 1;
    while(pin >> a >> b >> c) {
        vector<int> sides({a,b,c});
        auto max_side =
            max_element(sides.begin(), sides.end());
        int max_pow = *max_side * (*max_side);
        sides.erase(max_side);
        int min_pow1 = sides[0] * sides[0];
        int min_pow2 = sides[1] * sides[1];

        bool pythagoras_test
            = (max_pow == (min_pow1 + min_pow2));

        cout << "Scenario #" << scenario_cnt << ":" << endl;
        if(pythagoras_test == true) {
            cout << "yes";
        } else {
            cout << "no";
        } 

        if(scenario_cnt != n) {
            cout << "\n\n";
        }
        scenario_cnt++;
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


