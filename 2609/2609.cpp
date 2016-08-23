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
#include <unordered_map>
#include <unordered_set>
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
unsigned long long gcd(unsigned long long n, unsigned long long m) {
    if (m == 0) {
        return n;
    } else {
        return gcd(m, n % m);
    }
}    
long long lcm(long long n, long long m) {
    return n / gcd(n, m) * m;
}
unsigned long long eleven(int n) {
    unsigned long long ret = 0;
    //string s;
    //s.resize(n);
    for (int i = 0; i < n; i++) {
        ret += (unsigned long long)pow(10, i);
    }
    //ret = stoull(s);
    return ret;
}
void genProbSolver::process_input(istream &pin) {
    long long n, m;
    pin >> n >> m;
    //std::cout << eleven(m);
    std::cout << gcd(eleven(n), eleven(m));
    //std::cout << lcm(n, m) << endl;
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


