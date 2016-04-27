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
#include <bitset>
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
    string bin;
    pin >> bin; 
    string bin16(bin + "0000");
    //cout << bin16;
    string res("");
    string tmp("");
    bool carry = false;
    while(!bin.empty() && !bin16.empty()) {
        if(bin.back() == '0' && bin16.back() == '0') {
            if(carry)
                tmp.push_back('1');
            else tmp.push_back('0');
            carry = false;
        } else if(bin.back() == '1' && bin16.back() == '1') {
            if(carry)
                tmp.push_back('1');
            else tmp.push_back('0');
            carry = true;
        } else {
            if(carry) {
                tmp.push_back('0');
                carry = true;
            } else tmp.push_back('1');
        }
        bin.pop_back();
        bin16.pop_back();
    }
    res += tmp;
    long ibin16 = bitset<4>(bin16).to_ulong();
    if(carry) ibin16++;
    reverse(res.begin(), res.end());
    string ttmp = bitset<5>(ibin16).to_string();
    const auto first_digit = ttmp.find('1');
    ttmp = ttmp.substr(first_digit);
    res.insert(0, ttmp);
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


