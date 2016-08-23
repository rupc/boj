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
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)  return false;
 
    // Check from 2 to n-1
    for (int i=2; i<n; i++)
        if (n%i == 0)
            return false;
 
    return true;
}
void genProbSolver::process_input(istream &pin) {
    int N;
    pin >> N;
    std::vector<int> primes;
    int t;
    while(pin >> t) primes.push_back(t);
    int cnt = 0;
    for (auto &p : primes) {
        if(isPrime(p)) {
            cnt++;
        }
    }
    std::cout << cnt;
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


