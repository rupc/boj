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
// problem of longest consecutive increasing subsequence

void genProbSolver::process_input(istream &pin) {
    int N;
    pin >> N;
    int kids[N];
    int table[N] = {0,};
    std::unordered_map<int, int> kmap;
    for (int i = 0; i < N; i++) {
        scanf("%d", &kids[i]);
        kmap.insert({kids[i], i});
    }
    table[0]++;
    int max_length = 0;
    for (int i = 1; i < N; i++) {
        if (kids[i] == 1) {
            table[i]++;
            continue;
        }
        int ival = kmap[kids[i]-1]; // get an index
        /*std::cout << ival << std::endl;*/
        if (ival < i && ival >= 0) {
            table[i] += table[ival];
        }
        table[i]++;
        if (max_length < table[i]) {
            max_length = table[i];
        }
    }   
    /*std::cout << "------" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << table[i] << std::endl;
    }*/
    std::cout << N - max_length;
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


