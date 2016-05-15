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
std::vector<bool> visit(1000000, false);
std::vector<int> balloons(1000000);
std::vector<std::pair<int, int>> bq(1000000);
void genProbSolver::process_input(istream &pin) {
    int N;
    pin >> N;

    int t;

    for (int i = 0; i < N; i++) {
        scanf("%d", &t);
        //pin >> t;
        balloons[i] = t;
        bq[i] = {t, i};
        //bq.push({t, i});
    }
    int arrow = 0;
    sort(bq.begin(), bq.end(), greater<pair<int, int>>());
    int high = 0;
    size_t sz = N;
    while (N > 0 && !bq.empty()) {
        int highest = bq[high].first;
        int h_id = bq[high].second;
        ++high;
        if(visit[h_id]) continue;
        //std::cout << highest << std::endl;
        --N;
        highest--;
        visit[h_id] = true;

        for (size_t i = h_id+1; i < sz; i++) {
            if (highest  == balloons[i] && !visit[i]) {
                visit[i] = true;
                highest--;
                --N;
            }
        }
        arrow++;
    }
    std::cout << arrow;
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


