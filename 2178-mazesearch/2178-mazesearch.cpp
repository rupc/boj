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
    pin >> N >> M;
    std::vector<vector<bool>> matrix(N+2, std::vector<bool>(M+2));
    char t;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            pin >> t;
            matrix[i][j] = (t == '1' ? 1 : 0);
        }
    } 
    /*for (const auto &p : matrix, {
        for(const auto &q : p) {
            std::cout << q;
        }
        std::cout << std::endl;
    }*/
    int steps = 0;
    std::vector<vector<bool>> visits(N+2, std::vector<bool>(M+2));
    std::queue<std::pair<int, int >> after_visits;
    after_visits.push(std::make_pair(1, 1));
    visits[1][1] = true;
    std::vector<vector<int>> dists(N+2, std::vector<int>(M+2));
    dists[1][1] = 1;
    while (!after_visits.empty()) {
        std::pair<int, int> next_visit = after_visits.front();
        after_visits.pop();
        const int x = next_visit.second;
        const int y = next_visit.first;
        std::vector<std::pair<int, int>> four_direction
            // east, west, south, north
            = {{y, x+1}, {y, x-1}, {y+1, x}, {y-1, x}};
        for (const auto &p : four_direction) {
            const int nx = p.second;
            const int ny = p.first;
            if (nx == M && ny == N) {
                std::cout << dists[y][x] + 1;
                return;
            }
            if (matrix[ny][nx] && !visits[ny][nx]) {
                after_visits.push({ny, nx});
                visits[ny][nx] = true;
                dists[ny][nx] = dists[y][x] + 1;
            }
        }
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


