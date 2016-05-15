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
    std::vector<int> nums(10);
    std::map<int, int> freq;
    for (int i = 0; i < 10; i++) {
        pin >> nums[i];
        freq[nums[i]]++;
    }
    int avg = std::accumulate(nums.begin(), nums.end(), 0) / 10;
    auto min_freq
        = std::max_element(freq.begin(), freq.end(),
                [](std::decltype(freq)::value_type &p1,
                   std::decltype(freq)::value_type &p2) -> bool{
                    if (p1.second < p2.second) {
                        return true;
                    } else return false;
                });
    std::cout << avg << std::endl;
    std::cout << min_freq->first;
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


