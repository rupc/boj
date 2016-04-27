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
    int T;
    vector<int> rounds;
    
    pin >> T;
    int tmp;
    while(pin >> tmp) {
        rounds.push_back(tmp);
    }
    for (int i = 0; i < T; i++) {
        int rooms = rounds[i];
        vector<bool> doors(rooms, false);
        for (int j = 1; j <= rooms; j++) {
            for (int k = j-1; k < rooms; k += j) {
                doors[k] = !(doors[k]);
            }

        }
        int prison_breakers = 
            count_if(doors.begin(), doors.end(), 
                [](bool b){
                    if(b) return true;
                    else return false;
            });
        cout << prison_breakers << endl;
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


