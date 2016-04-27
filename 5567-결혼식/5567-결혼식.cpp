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
    int n, m;
    pin >> n >> m;
    std::vector<pair<int, int>> all_friends;
    int a, b;
    while(pin >> a >> b) {
        if(a == 1 && b == 1) continue;
        all_friends.push_back(std::make_pair(a, b));
    }
    std::set<int> fri_friends;
    // friends of 1
    for(const auto &p : all_friends) {
        if (p.first == 1 || p.second == 1) {
            if(p.first != 1)
                fri_friends.insert(p.first);
            else fri_friends.insert(p.second);
        }
    }
    //int num_of_visitors = fri_friends.size();
    auto remove_pos = std::remove_if(all_friends.begin(), all_friends.end(),
        [](decltype(all_friends)::value_type &elem) {
            if(elem.first == 1 || elem.second == 1) return true;
            else return false;
    });
    all_friends.resize(distance(all_friends.begin(), remove_pos));
    /*for(const auto &p : fri_friends) {
        std::cout << p << std::endl;
    }
    std::cout << std::endl;*/
    //std::cout << num_of_visitors << std::endl;
    std::set<int> indirect_friends;
    // friends of friends of 1
    for(const auto &p : all_friends) {
        const bool first_fri = 
            (fri_friends.find(p.first) != fri_friends.end()); 
        const bool second_fri = 
            (fri_friends.find(p.second) != fri_friends.end()); 
        if(first_fri && !second_fri) {
            indirect_friends.insert(p.second);
        } else if(!first_fri && second_fri) {
            indirect_friends.insert(p.first);
        }
        /*if(fri_friends.find(p.first) != fri_friends.end()) {
            if(fri_friends.find(p.second) == fri_friends.end()) {
                if(p.second != 1) {
                    indirect_friends.insert(p.second);
                }
                //num_of_visitors++;
            }
        } else if(fri_friends.find(p.second) != friends.end()) {
        
        }*/
    }
    /*for(const auto &p : fri_friends) {
        std::cout << p << std::endl;
    }
    std::cout << "" << std::endl;*/
    //std::cout << num_of_visitors;
    std::cout << fri_friends.size() + indirect_friends.size();
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


