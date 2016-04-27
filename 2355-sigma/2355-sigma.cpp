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
    long long i, j;
    pin >> i >> j;
    long long res = 0;
    if(i == j) {
        res = i;
        cout << res;
        return;
    }
    if(i < 0 && j < 0) {
        i = -i; j = -j;
        int max_val = max(i, j);
        int min_val = min(i, j);
        int bias = (min_val * (min_val + 1)) / 2;
        res = (((max_val * (max_val + 1)) / 2) - bias + min_val);
        res = -res;
    } else if((i <= 0) && (j >= 0)) {
        i = -i;
        long long minus_sum = ((i*(i+1)) / 2);
        long long plus_sum = ((j*(j+1))/ 2);
        res = plus_sum - minus_sum;
    } else if((i >= 0) && (j <= 0)) {
        j = -j;
        long long minus_sum = ((j*(j+1)) / 2);
        long long plus_sum = ((i*(i+1))/ 2);
        res = plus_sum - minus_sum;
    } else if((i > 0) && (j > 0)) {
        int max_val = max(i, j);
        int min_val = min(i, j);
        int bias = (min_val * (min_val + 1)) / 2;
        res = ((max_val * (max_val + 1)) / 2) - bias + min_val;
    } 
    cout << res;

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


