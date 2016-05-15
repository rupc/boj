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
    string word;
    pin >> word;
    std::map<char, int> char_map;
    for (auto &p : word) {
        char_map[toupper(p)]++;
    }
    auto most = std::max_element(char_map.begin(), char_map.end(),
            [](decltype(char_map)::value_type &p1, 
               decltype(char_map)::value_type &p2){
                if (p1.second < p2.second) {
                    return true;
                } else return false;
            });
    auto cnt =  std::count_if(char_map.begin(),char_map.end(),
        [&](decltype(char_map)::value_type &elem) {
            if (elem.second == most->second) {
                return true;
            } else return false;
    });
    if (cnt == 1) {
        std::cout << most->first << std::endl;
    } else  {
        std::cout << "?" << std::endl;
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


