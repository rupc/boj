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
    int t1, t2;
    pin >> t1 >> t2;
    vector<int> seq(1000);
    int idx = 0;
    int cnt = 1;
    bool out_of = false;
    while(1) {
        if(out_of == true) {
            break;
        }
        for (int i = 0; i < cnt; i++) {
            seq[idx++] = cnt;
            if(idx == 1000) {
                out_of = true;
                break; 
            }
        }
        ++cnt;
    }
    int res = 
        accumulate(&seq[t1-1], &seq[t2], 0);
    //copy(&seq[t1-1], &seq[t2], ostream_iterator<int>(cout, " "));
    std::cout << res;
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


