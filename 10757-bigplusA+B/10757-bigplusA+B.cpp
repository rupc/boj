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
    string s1, s2;
    string bigres("");
    pin >> s1 >> s2;
    int carry = 0;
    while(!s1.empty() && !s2.empty()) {
        int n1 = s1.back() - '0';
        int n2 = s2.back() - '0';
        s1.pop_back();
        s2.pop_back();
        int res = n1 + n2 + carry;
        if(res >= 10){
            carry = 1;
            res -= 10;
        } else {
            carry = 0;
        }
        bigres.push_back(to_string(res)[0]);
    }
    if(s1.empty() && s2.empty()) {
        if(carry == 1) bigres.push_back('1'); 
    }
    if(!s1.empty()) {
        int residue = stoi(s1);
        if(carry == 1) ++residue;
        string tmp = to_string(residue);
        reverse(tmp.begin(), tmp.end());
        bigres += tmp;
    } else if(!s2.empty()) {
        int residue = stoi(s2);
        if(carry == 1) ++residue;
        string tmp = to_string(residue);
        reverse(tmp.begin(), tmp.end());
        bigres += tmp;
    }
    reverse(bigres.begin(), bigres.end());
    cout << bigres;
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


