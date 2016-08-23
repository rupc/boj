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

// Declaration of auxiliary function
class genProbSolver {

    public:
        genProbSolver(std::string s) : name(s) {}
        void process_input(std::istream &);
        void process_solution();
        void process_output(std::ostream &);
        void echo_input();
    private:
        std::string name;
};
void genProbSolver::process_input(std::istream &pin) {
    int money;
    int cnt = 0;
    pin >> money; 
    money = 1000 - money;
    while (money > 0) {
        if (money >= 500) {
            money -= 500;
            std::cout << "here" << std::endl;
        } else if (money >= 100) {
            money -= 100;  
        } else if (money >= 50) {
            money -= 50;   
        } else if (money >= 10) {
            money -= 10;   
        } else if (money >= 5) {
            money -= 5;    
        } else if (money >= 1) {
            money -= 1;
        }
        cnt++;
    }
    std::cout << cnt;
}
void genProbSolver::echo_input() {

}
void genProbSolver::process_solution() {
    
}
void genProbSolver::process_output(std::ostream &pout) {

}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("");
    probsolver.process_input(std::cin);
    probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


