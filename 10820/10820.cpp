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
void genProbSolver::process_input(istream &pin) {
    // ignore() needed if ">>" used
    string lbuf; // line buffer
    int lower_case, upper_case, number, white;
    lower_case = upper_case = number = white = 0;
    while (getline(pin, lbuf)) {
        for (auto &p : lbuf) {
            if (isupper(p)) {
                upper_case++;
            } else if (islower(p)) {
                lower_case++;
            } else if (isdigit(p)) {
                number++;
            } else if (isspace(p)) {
                white++;
            }
        }
        std::cout << lower_case << " " << upper_case
            << " " << number << " " << white << std::endl;
        lower_case = upper_case = number = white = 0;
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


