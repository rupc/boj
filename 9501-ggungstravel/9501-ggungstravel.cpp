// input, output 
#include <iostream>
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
struct spaceship {
    double v,f,c;
    spaceship(int av, int af, int ac) :
        v(av), f(af), c(ac) {}
};
void genProbSolver::process_input(istream &pin) {
    int T;
    pin >> T;
    for (int i = 0; i < T; i++) {
        int N, D; 
        pin >> N >> D;
        vector<spaceship> ships;
        int t1, t2, t3;
        for (int j = 0; j < N; j++) {
            pin >> t1 >> t2 >> t3; 
            ships.push_back(spaceship(t1, t2, t3));
        }
        int possible_ships = 0;
        for(const auto &p : ships) {
            double move_time = 
                (double) D / p.v;
            if(p.f - move_time * p.c >= 0.0){
                possible_ships++;
            }
        }
        cout << possible_ships << endl;
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


