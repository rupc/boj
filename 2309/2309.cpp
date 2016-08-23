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
    std::vector<int> dwarfs(9);
    for (int i = 0; i < 9; i++) {
        pin >> dwarfs[i];
    }
    std::sort(dwarfs.begin(), dwarfs.end());
    // combination by select vector and stl-next_permutation
    std::vector<bool> selection(9);
    std::fill(selection.begin()+9-7, selection.end(), true);
    do {
        int sum = 0;
        for(size_t i = 0; i < selection.size(); ++i) {
            if(selection[i] == true) {
                // do something
                sum += dwarfs[i];
            }
        }
        if (sum == 100) {
            for (int i = 0; i < 9; i++) {
                if (selection[i] == true) {
                    std::cout << dwarfs[i] << std::endl;
                }
            }
            break;
        }
    } while(std::next_permutation(selection.begin(), selection.end()));
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


