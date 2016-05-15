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
std::vector<int> seq(1000000);
//std::set<int, greater<int>> seq_s;
bool fun(int i, int j) {
    return i > j;
}
void genProbSolver::process_input(istream &pin) {
    unsigned N;
    pin >> N;
    int t;
    for (size_t i = 0; i < N; i++) {
        //pin >> t;
        scanf("%d", &t);
        seq[i] = t;
        //seq_s.insert(t);
    }
    //seq.resize(N);
    std::sort(seq.begin(), seq.begin()+N, greater<int>());
    /*for (const auto p : seq_s) {
        printf("%d\n", p);
    }*/
    for (size_t i = 0; i < N; i++) {
        printf("%d\n", seq[i]);
    }
    /*for (const auto p : seq) {
        std::cout << p << "\n";
    }*/
    /*while (pin >> t) {
        seq.push_back(t);
    }*/
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
    /*probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);*/
    return 0;
}


