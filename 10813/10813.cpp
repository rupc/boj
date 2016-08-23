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
    int N, M;
    pin >> N >> M;
    std::vector<int> baskets(N+1);
    for (int i = 1; i <= N; i++) {
        baskets[i] = i;
    }
    int t1, t2;
    for (int i = 0; i < M; i++) {
        pin >> t1 >> t2;
        swap(baskets[t1], baskets[t2]);
    }
    baskets.erase(baskets.begin());
    for (auto &p : baskets) {
        std::cout << p << " ";
    }
}
void genProbSolver::echo_input() {

}
// 10810
void genProbSolver::process_solution() {
    int N, M;
    istream &pin(cin);
    pin >> N >> M;
    std::vector<int> baskets(N+1, 0);
    int t1, t2, ball;
    for (int i = 0; i < M; i++) {
        pin >> t1 >> t2 >> ball;
        std::fill(baskets.begin() + t1, baskets.begin() + t2+1, ball);
    }
    baskets.erase(baskets.begin());
    for (auto &p : baskets) {
        std::cout << p << " ";
    }
}
// 10811
void genProbSolver::process_output(ostream &pout) {
    int N, M;
    istream &pin(cin);
    pin >> N >> M;
    std::vector<int> baskets(N+1);
    for (int i = 1; i <= N; i++) {
        baskets[i] = i;
    }
    int t1, t2;
    for (int i = 0; i < M; i++) {
        pin >> t1 >> t2;
        std::reverse(baskets.begin()+t1, baskets.begin() + t2 + 1);
    }
    baskets.erase(baskets.begin());
    for (auto &p : baskets) {
        std::cout << p << " ";
    }
}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("");
    //probsolver.process_input(std::cin);
    probsolver.echo_input();
    //probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


