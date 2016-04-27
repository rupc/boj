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
    int N, key1, key2;
    pin >> N >> key1 >> key2;
    vector<int> players;
    vector<int> keys(2);
    keys[0] = key1;
    keys[1] = key2;
    sort(keys.begin(), keys.end());
    int n_round = 1;
    for (int i = 0; i < N; i++) {
        players.push_back(i+1);
    }
    bool found_match = false;
    while (1) {
        for (int i = 1; i < N; i += 2) {
            vector<int> tmps{players[i-1], players[i]};
            sort(tmps.begin(), tmps.end());
            if(tmps[0] == keys[0] && tmps[1] == keys[1]) {
                found_match = true;
                break;
            } else {
                if(players[i-1] == key1 ||
                        players[i-1] == key2) {
                    players[i] = 0;
                } else if (players[i] == key1 ||
                        players[i] == key2) {
                    players[i-1] = 0;
                } else {
                    players[i] = 0;
                }
            }
        }
        if(found_match == true) {
            break;
        }
        remove_if(players.begin(), players.end(),
                [](int n){
                   if(n == 0) return true;
                   else return false;
        });
        /*copy(players.begin(),players.end(),
                ostream_iterator<int>(cout, " "));*/
        n_round++;
    }
    cout << n_round;
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


