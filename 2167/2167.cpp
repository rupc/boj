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
    int N, M;
    pin >> N >> M;
    std::vector<std::vector<int>> matrix(N, std::vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    } 
    int K;
    pin >> K;
    std::vector<int> sums(K);
    while (K--) {
        int a, b, x, y;
        scanf("%d%d%d%d", &a,&b,&x,&y);
        int sum = 0;
        for (int i = a-1; i <= x-1; ++i) {
            for (int j = b-1; j <= y-1; ++j) {
                sum += matrix[i][j];
            }
        } 
        sums[K] = sum;
    }
    int sz = sums.size();
    for (int i = 0; i < sz; i++) {
        printf("%d\n", sums[sz-i-1]);
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


