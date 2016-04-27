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
struct paper {
        int x;
        int y;
        paper(int ax, int ay) :
            x(ax), y(ay) {}
        paper() {}
};
bool operator == (paper &lhs, paper &rhs) {
    if(lhs.x == rhs.x &&
        lhs.y == rhs.y) {
        return true;
    } else {
        return false;
    }
}
bool operator < (paper &lhs, paper &rhs) {
    if(lhs.x <= rhs.x && lhs.y <= rhs.y) {
        return true;
    } else {
        return false;
    }
}
void genProbSolver::process_input(istream &pin) {
    int N;
    pin >> N;
    int t1, t2;
    /*unsigned long long total = 0;
    vector<paper> papers;*/
    vector<vector<bool>> matrix(100, {false, });
    for (int i = 0; i < 100; i++) {
        matrix[i].resize(100);
    }
    while (pin >> t1 >> t2) {
        //papers.emplace_back(t1, t2);  
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                matrix[i+t1][j+t2] = true;
            }
        }
    }
    
    int sz = 0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if(matrix[i][j] == true) {
                sz++;
            }
        }
    } 
    cout << sz;
    /*{ // eliminate duplicates
        std::sort(papers.begin(), papers.end());
        auto it = std::unique(papers.begin(), papers.end());
        papers.resize(std::distance(papers.begin(), it));
    }

    N = papers.size();
    total = N * 100;
    for (int i = 0; i < N; i++) {
        int x1 = papers[i].x;
        int y1 = papers[i].y;
        for (int j = i+1; j < N; j++) {
            int x2 = papers[j].x;
            int y2 = papers[j].y;
            int dist_x = abs(x1 - x2);
            int dist_y = abs(y1 - y2);
            if (dist_x < 10 && dist_y < 10) {
                unsigned long long piled
                    = (10 - dist_x) * (10 - dist_y);
                total -= piled;
                #ifdef DEBUG
                    std::cout << x1 << "," << y1 << "\t" << x2 << "," << y2 << "\t" << piled  << std::endl;
                #endif
            } else {
                
            }
        }
    }*/
    //std::cout << total;

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


