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
    string S;
    pin >> S;
    int n = S.size() / 3;
    int _type = 0;
    std::map<char, int> card_map;
    std::set<string> card_in;
    card_map['P'] = 13;
    card_map['K'] = 13;
    card_map['H'] = 13;
    card_map['T'] = 13;
    while (n--) {
        char card_type = S[_type];
        card_map[card_type]--;
        string card(S.begin() + _type, S.begin() + _type + 3);
        if (card_in.find(card) != card_in.end()) {
            std::cout << "GRESKA";
            return;
        } else {
            card_in.insert(card);
        }
        _type += 3;
    }
    std::cout << card_map['P'] << " ";
    std::cout << card_map['K'] << " ";
    std::cout << card_map['H'] << " ";
    std::cout << card_map['T'];
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


