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

}
void genProbSolver::echo_input() {

}
inline int digit_sum(int n) {
    int res = 0;
    while(n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}
#define SELF_LIMIT (10000)
void genProbSolver::process_solution() {
    vector<bool> self_test(SELF_LIMIT+1, true);
    for (int i = 1; i <= SELF_LIMIT; i++) {
        int self = i;
        //cout << "start self : " << i << endl;
        while(1) {
            self += digit_sum(self);
            if(self <= SELF_LIMIT) {
                self_test[self] = false;
                //std::cout << self << std::endl;
            } else {
                break;
            }
        }
    }
    for (int i = 1; i <= SELF_LIMIT; i++) {
        if(self_test[i] == true) {
            cout << i << endl;
        }
    }
}
void genProbSolver::process_output(ostream &pout) {

}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("");
    probsolver.process_input(std::cin);
    probsolver.echo_input();
    //std::cout << digit_sum(11) << std::endl;
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


