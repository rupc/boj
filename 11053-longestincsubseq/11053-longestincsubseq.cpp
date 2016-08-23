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
bool operator < (vector<int> &v1, vector<int> &v2) {
    if(v1.size() < v2.size()) return true;
    else return false;
}
void genProbSolver::process_input(istream &pin) {
    int A;
    vector<int> seq;
    pin >> A;
    int tmp; 
    while(pin >> tmp) seq.push_back(tmp);
    /*for(const auto &p : seq) {
        cout << p << " ";
    }*/
    vector<vector<int>> cache(seq.size());
    cache[0].push_back(seq[0]);
    int max_val = 0, max_idx;
    for (int i = 1; i < A; i++) {
        for (int j = 0; j < i; j++) {
            if((seq[j] < seq[i]) &&
               (cache[i].size() < cache[j].size()+1)) {
                cache[i] = cache[j];
            }
        }
        cache[i].push_back(seq[i]);
        if(max_val < cache[i].size()) {
            max_val = cache[i].size();
            max_idx = i;
        }
    }

    //cout << cache[3][0] << endl;
    /*for(const auto &p : cache) {
        for (int k = 0; k < p.size(); k++) {
            cout << p[k] << " "; 
        }
        cout << endl;
    }*/
    cout << A - cache[max_idx].size();
    /*for (int i = 0; i < max_val; i++) {
        cout << cache[max_idx][i] << " ";
    }*/

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


