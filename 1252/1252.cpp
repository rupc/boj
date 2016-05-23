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
    vector<bool> bin1, bin2;
    string tmp;
    pin >> tmp;
    for (auto &p : tmp) {
        if (p == '0') {
            bin1.push_back(false);
        } else bin1.push_back(true);
    }
    pin >> tmp;
    for (auto &p : tmp) {
        if (p == '0') {
            bin2.push_back(false);
        } else bin2.push_back(true);
    }
    vector<bool> res;
    bool carry = false;
    while (!bin1.empty() && !bin2.empty()) {
        //std::cout << carry << std::endl;
        bool b1 = bin1.back();
        bool b2 = bin2.back();
        bin1.pop_back(); bin2.pop_back();
        bool sum = b1 ^ b2 ^ carry;
        res.push_back(sum);
        carry = (b1 & b2) | (carry & (b1 ^ b2));
    }
    /*for (auto p : res) {
        std::cout << p;
    }*/
    if (bin1.empty()) {
        while (!bin2.empty()) {
            bool b = bin2.back();
            bin2.pop_back();
            bool sum = b ^ carry;
            carry = b & carry;
            res.push_back(sum);
        }
    } else {
        while (!bin1.empty()) {
            bool b = bin1.back();
            bin1.pop_back();
            bool sum = b ^ carry;
            carry = b & carry;
            res.push_back(sum);
        }
    }
    if (carry) res.push_back(carry);
    std::reverse(res.begin(), res.end());
    if (res.front() == false) {
        res.erase(res.begin(), std::find(res.begin(), res.end(), true));
    }
    if (res.empty()) std::cout << 0;
    else {
        for (auto p : res) {
            std::cout << p;
        }
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


