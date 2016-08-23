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
bool RelativelyPrime (int a, int b) { // Assumes a, b > 0
   return (a<b) ? RelativelyPrime(b,a) : !(a%b) ? (b==1) : RelativelyPrime (b, a%b);
}
void genProbSolver::process_input(istream &pin) {
    int T;
    scanf("%d", &T);
    std::vector<unsigned long long> seen_points(1001);
    seen_points[0] = 0;
    seen_points[1] = 3;
    seen_points[2] = 5;
    for (int i = 3; i < 1001; i++) {
        seen_points[i] = seen_points[i-1];
        unsigned long long offsets = 1;
        for (int j = 2; j < i; j++) {
            if (RelativelyPrime(i, j)) {
                offsets++;
            }
        }
        seen_points[i] += (offsets * 2);
    }
    int N;
    while (T--) {
        scanf("%d", &N);
        std::cout << seen_points[N] << std::endl;
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


