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
    long long fib[46];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 46; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    while(T--) {
        long long n;
        pin >> n;
        long long sum = 0;
        list<long long> greedy_list;
        for (int i = 45; i >= 0; i--) {
            if (sum + fib[i] <= n) {
                sum += fib[i];
                greedy_list.push_front(fib[i]);
            }
            if (sum == n) {
                break;
            }
        }
        for (auto &p : greedy_list) {
            std::cout << p << " ";
        }
        std::cout << std::endl;
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


