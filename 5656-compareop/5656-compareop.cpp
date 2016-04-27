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
    int a, b;
    string op;
    bool flag = false;
    int case_cnt = 1;
    while(pin >> a >> op >> b) {
        if(op == "E") break;
        if(op == ">") {
            flag = (a > b);
        } else if(op == ">=") {
            flag = (a >= b);
        } else if(op == "<") {
            flag = (a<b);
        } else if(op == "<=") {
            flag = (a<=b);
        } else if(op == "==") {
            flag = (a==b);
        } else if(op == "!=") {
            flag = (a!=b);
        }  
        string tmp("");
        if(flag) tmp = "true"; 
        else tmp = "false";
        cout << "Case " << case_cnt << ": " << tmp << endl;
        case_cnt++;
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


