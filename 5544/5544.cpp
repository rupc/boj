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
    int N;
    pin >> N;
    vector<int> team_score(N+1, 0);
    int t1, t2, t3, t4;
    while(pin >> t1 >> t2 >> t3 >> t4) {
        if(t3 == t4) {
            team_score[t1] += 1;
            team_score[t2] += 1;
        } else if (t3 > t4) {
            team_score[t1] += 3;
            team_score[t2] += 0;
        } else if (t3 < t4) {
            team_score[t1] += 0;
            team_score[t2] += 3;
        }
    }
    /*for(const auto &p : team_score) {
        std::cout << p << std::endl;
    }
    std::cout << "" << std::endl;*/
    vector<int> team_rank(N+1, N);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if(i != j) {
                if(team_score[i] >= team_score[j]) {
                    team_rank[i]--;
                }
            }
        }
    } 
    team_rank.erase(team_rank.begin());
    for(const auto &p : team_rank) {
        std::cout << p << std::endl;
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


