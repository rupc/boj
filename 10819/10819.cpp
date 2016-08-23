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
    int N;
    pin >> N;
    std::vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        pin >> nums[i];
    }
    int highest = 0;
    int cnt = 1;
    std::sort(nums.begin(), nums.end());
    do {
        int sum = 0;
        for (int i = 1; i < N; i++) {
            sum += (abs(nums[i-1] - nums[i]));
        }
        if (highest < sum) {
            highest = sum;
        }
        //std::cout << cnt++ << std::endl;
    } while (next_permutation(nums.begin(), nums.end()));
    std::cout << highest;
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


