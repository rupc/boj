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
    int K;
    pin >> K;
    ++K;
    vector<vector<int>> table(K);
    for (int i = 0; i < K; i++) {
        table[i].resize(2);
    }
    table[0][0] = 1;
    table[0][1] = 0;
    for (int i = 1; i < K; i++) {
        table[i][0] = table[i-1][1]; 
        table[i][1] = table[i-1][0] + table[i-1][1];
    }
    int a_cnt = table[K-1][0];
    int b_cnt = table[K-1][1];
    cout << a_cnt <<  " " << b_cnt;
    /*list<char> lst;
    lst.push_back('A');
    for (int i = 0; i < K; i++) {
        for (auto p = lst.begin(); p != lst.end(); ++p) {
            if(*p == 'A') {
                *p = 'B';
            } else {
                ++p;
                lst.insert(p, 'A');
                --p;
            }
        }
    }
    int a_cnt = count(lst.begin(), lst.end(), 'A');
    int b_cnt = count(lst.begin(), lst.end(), 'B');
    cout << a_cnt << " " << b_cnt;*/
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


