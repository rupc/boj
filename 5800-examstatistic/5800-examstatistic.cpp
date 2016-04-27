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
    for (int i = 0; i < K; i++) {
        int N; 
        pin >> N;
        vector<int> scores(N);
        for (int j = 0; j < N; j++) {
            int tmp;
            pin >> tmp;
            scores[j] = tmp; 
        }
        int max_score, min_score, largest_gap = 0;
        max_score = *max_element(scores.begin(), scores.end());
        min_score = *min_element(scores.begin(), scores.end());
        sort(scores.begin(), scores.end(), greater<int>());
        for (int j = 1; j < N; j++) {
            int gap = abs(scores[j-1] - scores[j]);
            if(gap > largest_gap) {
                largest_gap = gap;
            } 
        }
        printf("Class %d\nMax %d, Min %d, Largest gap %d\n",
                i+1, max_score, min_score, largest_gap);
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


