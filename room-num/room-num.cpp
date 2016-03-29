#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

// #define DEBUG
//
using namespace std;
class genProbSolver {
    public:
        genProbSolver(string s) : name(s) {}
        void process_input(istream &);
        void process_solution();
        void process_output(ostream &);
    private:
        string name;
};
// 
// Declaration of variables
//
string room;
std::map<char, unsigned> num_table;
unsigned set_of_card;
//
// Declaration of auxiliary function
// 
//
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("room number");
    probsolver.process_input(std::cin);
//     probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}

void genProbSolver::process_input(istream &pin) {
    pin >> room;
    for(const auto &c : room) {
        if(c == '9') {
            num_table['6']++;
            continue;
        }
        num_table[c]++;
    }
    num_table['6'] = ceil(((double)num_table['6'] / 2.0));
//     for(const auto &p : num_table) {
//         cout << p.first << " " << p.second << endl;
//     }
}
void genProbSolver::process_solution() {
    auto ret = max_element(begin(num_table), end(num_table),
        [](const pair<char, unsigned>&p1, const pair<char, unsigned>& p2) {
            return p1.second < p2.second;
        });    
    set_of_card = ret->second;
}
void genProbSolver::process_output(ostream &pout) {
    pout << set_of_card;
}
