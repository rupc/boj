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
    while (T--) {
        string four;
        pin >> four;
        if (four == "6174") {
            std::cout << "0" << std::endl;
            continue;
        }
        int steps = 0;
        while (1) {
            std::sort(four.begin(), four.end());    
            int small = stoi(four);
            std::reverse(four.begin(), four.end()); 
            int big = stoi(four);
            int next_num = big - small;
            steps++;
            if (next_num == 6174) {
                break;
            }
            four = "";
            int sz = to_string(next_num).size();
            for (int i = 0; i < 4-sz; i++) {
                four += "0";
            }
            four += to_string(next_num);
        }
        std::cout << steps << std::endl;
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


