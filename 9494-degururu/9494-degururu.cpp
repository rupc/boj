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
    while(pin >> n) {
        pin.ignore(); // equals to pin.ignore(1, '\n');
        if(n == 0) {
            break;
        }
        vector<string> vs(n);
        string tmp("");
        for (int i = 0; i < n; i++) {
            getline(pin, tmp); 
            vs[i] = tmp;
        }
        int first_ws_pos = vs[0].find(' ');
        if(first_ws_pos == -1) first_ws_pos = vs[0].size();
        for (int i = 1; i < n; i++) {
            if(first_ws_pos > vs[i].size()) {
                continue;
            }
            first_ws_pos = vs[i].find(' ', first_ws_pos);
            if(first_ws_pos == -1) first_ws_pos = vs[i].size();
        }
        cout << first_ws_pos+1 << endl;
        
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


