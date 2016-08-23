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
// 11005 
void genProbSolver::process_input(istream &pin) {
    int N, B;
    pin >> N >> B;
    std::vector<char> transed;
    std::unordered_map<int, char> ns;
    for (int i = 0; i <= 35; i++) {
        if (i < 10) {
            ns[i] = '0' + i;
        } else {
            ns[i] = 'A' + i - 10;
        }
    }
    /*for (auto &p : ns) {
        std::cout << p.second << " ";
    }*/
    while (N > 0) {
        transed.push_back(ns[N % B]);
        N /= B;
    }
    std::reverse(transed.begin(), transed.end());
    for (auto &p : transed) {
        std::cout << p;
    }
}
void genProbSolver::echo_input() {

}
// 2745
void genProbSolver::process_solution() {
    string N;
    int B;
    istream &pin(cin);
    pin >> N >> B;
    std::unordered_map<char, int> ns;
    int n = 0;
    for (char c = '0'; c <= '9'; c++) {
        ns[c] = n++;
    }
    n = 0;
    for (char c = 'A'; c <= 'Z'; c++) {
        ns[c] = 10 + n++;
    }
    /*for (auto &p : ns) {
        std::cout << p.second << std::endl;
    }*/
    int sz = N.size();
    int sum = 0;
    int st = 0;
    while (sz--) {
        sum += pow(B, sz)  * ns[N[st++]];
    }
    std::cout << sum;
}
void genProbSolver::process_output(ostream &pout) {

}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("");
    //probsolver.process_input(std::cin);
    probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


