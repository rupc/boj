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
    int T;
    pin >> T;
    while (T--) {
        int N, M;
        pin >> N >> M;
        std::priority_queue<int> impos;
        std::queue<pair<int, int>> docs;
        std::vector<pair<int, int>> bufs;
        for (int i = 0; i < N; i++) {
            int t; pin >> t;
            impos.push(t);
            bufs.push_back({i, t});
        }
        /*for (int i = N-1; i >= 0; i--) {
            docs.push(bufs[i]);
        }*/
        for (int i = 0; i < N; i++) {
            docs.push(bufs[i]);
        }
        int steps = 0;
        while (1) {
            int curr_doc_impo = docs.front().second;
            int top_doc_impo = impos.top();
            if (top_doc_impo > curr_doc_impo) {
                docs.push(docs.front());
                docs.pop();
            } else {
                steps++;
                if (docs.front().first == M) {
                    if (N == 6) {

                    }
                    break;
                }
                docs.pop();
                impos.pop();
            }
        }
        std::cout << steps << std::endl;
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


