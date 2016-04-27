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
int N;
vector<int> prices;

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
    for (int i = 0; i < N; i++) {
        int t; 
        pin >> t;
        prices.push_back(t);
    }
}
void genProbSolver::echo_input() {

}
void genProbSolver::process_solution() {
    int quot = prices.size() / 3;
    int remain = prices.size() % 3;
    int res = 0;
    sort(prices.begin(), prices.end());
    reverse(prices.begin(), prices.end());
    
    for (int i = 0; i < quot; i++) {
        int sum =
            accumulate(prices.begin()+i*3,
                    prices.begin()+3+i*3, 0);
        auto m = 
            min_element(prices.begin()+i*3,
                    prices.begin()+3+i*3);
        res += sum -(*m); 
    }
    int residue
        = accumulate(prices.rbegin(),
            prices.rbegin() + remain, 0);
    res += residue;
    cout << res;
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


