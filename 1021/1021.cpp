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
    int N, M;
    deque<int> deck;
    queue<int> picks;
    pin >> N >> M;
    for (int i = 1; i <= N; i++) {
        deck.push_back(i);
    }
    for (int i = 0; i < M; i++) {
        int tmp;
        pin >> tmp;
        picks.push(tmp);
    }
    int op_cnt = 0;
    while(!picks.empty()) {
        int pick = picks.front();
        picks.pop();
        auto pick_pos 
            = find(deck.begin(), deck.end(), pick);
        int dist_from_left;
        int dist_from_right;
        dist_from_left = distance(deck.begin(), pick_pos);
        dist_from_right = distance(pick_pos, deck.end());

        op_cnt += min(dist_from_left, dist_from_right);

        // second operation
        if(dist_from_left <= dist_from_right) {
            for (int i = 0; i < dist_from_left; i++) {
                int tmp = deck.front();
                deck.pop_front();
                deck.push_back(tmp);
            }
        // third operation
        } else {
            for (int i = 0; i < dist_from_right; i++) {
                int tmp = deck.back();
                deck.pop_back();
                deck.push_front(tmp);
            }
        }
        // first operation
        deck.pop_front();
    }
    cout << op_cnt;
}
void genProbSolver::echo_input() {

}
void genProbSolver::process_solution() {
    
}
void genProbSolver::process_output(ostream &pout) {

}
int main(int argc, const char *argv[]) {
    /*vector<int> vi = {1,2,3,4,5,6};
    auto mid = find(vi.begin(), vi.end(), 3);
    cout << distance(mid, vi.end());*/
    genProbSolver probsolver("");
    probsolver.process_input(std::cin);
    probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


