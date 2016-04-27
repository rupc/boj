// input, output 
#include <iostream>
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
vector<pair<int ,int>> A, B;
vector<int> res;
int N;

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
    pin >> N;
    int t;
    for (int i = 0; i < N; i++) {
        pin >> t;
        A.push_back(make_pair(t, i));
    }
    for (int i = 0; i < N; i++) {
        pin >> t;
        B.push_back(make_pair(t, i));
    }
}
void genProbSolver::echo_input() {

}
void genProbSolver::process_solution() {
     vector<pair<int, int>> orin_B;
     sort(A.begin(), A.end()); 
     orin_B = B;
     sort(B.begin(), B.end());
     reverse(B.begin(), B.end());
     res.resize(N);
     for (int i = 0; i < N; i++) {
         //cout << B[i] << ""
         res[B[i].second] = A[i].first; 
         //cout << A[i].first << " "; 
     }
     int min_product = 0;     
     for (int i = 0; i < N; i++) {
         min_product += res[i] * orin_B[i].first; 
     }
     cout << min_product;

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


