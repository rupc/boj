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
#include <bitset>
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

string decimal_to_binary(int n)
{
    string res("");
    if (n / 2 != 0) {
        res += decimal_to_binary(n / 2);
    }
    return res + to_string(n%2);
}
unsigned long binary_to_decimal(string &b) {
    return bitset<32>(b).to_ulong();
}
void genProbSolver::process_input(istream &pin) {
    int N;
    pin >> N;
    string bin = decimal_to_binary(N);
    std::reverse(bin.begin(), bin.end());
    std::cout << binary_to_decimal(bin);
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


