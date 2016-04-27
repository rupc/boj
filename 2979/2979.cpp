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
    int A, B, C;
    pin >> A >> B >> C;
    int a1, a2, b1, b2, c1, c2;
    pin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    vector<int> intervals(101, 0);
    for (int i = a1; i < a2; i++) {
        intervals[i]++;
    }
    for (int i = b1; i < b2; i++) {
        intervals[i]++;
    }
    for (int i = c1; i < c2; i++) {
        intervals[i]++;
    }
    /*for(auto p : intervals) {
        cout << p;
    }
    cout << endl;*/
    int cost = 0;
    for (unsigned i = 0; i < intervals.size(); i++) {
        if(intervals[i] == 1) {
            cost += A;
        } else if(intervals[i] == 2) {
            cost += B*2;
        } else if(intervals[i] == 3) {
            cost += C*3;
        }
    }
    cout << cost;
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


