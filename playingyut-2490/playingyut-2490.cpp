// input, output 
#include <iostream>
#include <cmath>
// container
#include <vector>
#include <array>
#include <list>
#include <map>
#include <set>
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

}
void genProbSolver::echo_input() {

}
void genProbSolver::process_solution() {
    const int yut = 4;    
    vector<int> yuts;
    int tmp;
    while(cin >> tmp) {
        yuts.push_back(tmp);
        if(yuts.size() == yut) {
            int bae = count(yuts.begin(), yuts.end(), 0);
            if(bae == 0) {
                cout << "E" << endl;
            } else if(bae == 1) {
                cout << "A" << endl; 
            } else if(bae == 2) {
                cout << "B" << endl; 
            } else if(bae == 3) {
                cout << "C" << endl; 
            } else if(bae == 4) {
                cout << "D" << endl;
            }
            yuts.clear();
        }
    }
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


