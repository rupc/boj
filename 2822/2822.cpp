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
bool operator > (pair<int, int> &p1, pair<int, int> &p2) {
    if(p1.first > p2.first) return true;
    else return false;
}
void genProbSolver::process_input(istream &pin) {
    vector<pair<int, int>> scores;
    int tmp;
    int idx = 1;
    while (pin >> tmp) {
        scores.push_back(make_pair(tmp, idx++));
    }
    sort(scores.begin(), scores.end()
            , greater<pair<int, int>>());
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += scores[i].first;
    }
    cout << sum << endl;
    vector<int> idx_srt(5);
    for (int i = 0; i < 5; i++) {
        idx_srt[i] = scores[i].second;
    }
    sort(idx_srt.begin(), idx_srt.end());
    copy(idx_srt.begin(), idx_srt.end(),
            ostream_iterator<int>(cout, " "));

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


