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
    int N;
    pin >> N;
    int digit = 0;
    int n = N;
    int cnt = 1;
    while (n > 0) {
        n -= cnt * pow(10, cnt-1) * 9;
        ++digit;
        ++cnt;
    }
    if (n == 1) {
        std::cout << n;
        return;
    }
    //int pos = (digit - 1) * pow(10, digit - 2) * 9; // #of prev elem
    int pos = 0;
    for (int i = 0; i < digit - 1; i++) {
        pos += (digit - 1 - i) * pow(10, digit - 2 - i) * 9;
    }
    N -= pos + 1;
    //std::cout << N;
    std::cout << pos << endl;;
    int nth = N / digit;
    int remain = N % digit;
    int start = pow(10, digit-2);
    for (int i = 0; i < nth; i++) {
        ++start;
    }
    std::cout << start;
    /*if (0) {
        --start;
        std::cout << start % 10;
    } else {
        string res(to_string(start));
        std::cout << res[remain - 1];
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
    probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}

