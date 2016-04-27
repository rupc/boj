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
    vector<int> gandalf(6);
    vector<int> sauron(7);
    gandalf[0] = 1;
    gandalf[1] = 2;
    gandalf[2] = 3;
    gandalf[3] = 3;
    gandalf[4] = 4;
    gandalf[5] = 10;
    sauron[0] = 1;
    sauron[1] = 2;
    sauron[2] = 2;
    sauron[3] = 2;
    sauron[4] = 3;
    sauron[5] = 5;
    sauron[6] = 10;
    int num_of_war = 0;
    pin >> num_of_war;
    int cnt = 1;
    while(num_of_war--) {
        int g, s;
        int g_power = 0;
        int s_power = 0;
        for (int i = 0; i < 6; i++) {
            pin >> g;
            g_power += g * gandalf[i];
        }
        for (int i = 0; i < 7; i++) {
            pin >> s;
            s_power += s * sauron[i];
        }
        cout << "Battle "
            << cnt++;
        if(g_power == s_power) {
            cout << ": No victor on this battle field" 
                << endl;
        } else if(g_power > s_power) {
            cout << ": Good triumphs over Evil"
                << endl;
        } else {
            cout << ": Evil eradicates all trace of Good"
                << endl;
        }
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


