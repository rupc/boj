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
    int V;
    pin >> V;
    set<int> *Adj = new set<int>[V];
    pin.ignore();
    // ignore() needed if you use just ">>"
    string lbuf; // line buffer
    int src = 0;
    while (getline(cin, lbuf)) {
        std::cout << src << std::endl;
        //std::cout << lbuf << std::endl;
        istringstream iss(lbuf);
        int smallest_length = 999999999;
        int smallest_idx = 0;
        int idx = 0;
        int tmp;
        while (iss >> tmp) {
            if (smallest_length > tmp) {
                smallest_length = tmp;
                smallest_idx = idx;
                
            }
            ++idx;
        }
        //if (smallest_idx >= src) 
        //if (src == 4) std::cout << smallest_idx << std::endl; ;
        smallest_idx += src ;
        //std::cout << smallest_idx << std::endl;
        Adj[src].insert(smallest_idx); 
        Adj[smallest_idx].insert(src);
        ++src;
    }
    for (int i = 0; i < V; i++) {
        std::cout << Adj[i].size() << " ";
        for (auto &p : Adj[i]) {
            std::cout << p+1 << " ";
        }
        std::cout << std::endl;
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


