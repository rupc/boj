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
#include <unordered_map>
#include <unordered_set>
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

// Declaration of auxiliary function
class genProbSolver {

    public:
        genProbSolver(std::string s) : name(s) {}
        void process_input(std::istream &);
        void process_solution();
        void process_output(std::ostream &);
        void echo_input();
    private:
        std::string name;
};
void genProbSolver::process_input(std::istream &pin) {
    int N, M;
    pin >> N >> M;
    std::vector<std::vector<char>> image1(N, std::vector<char>(M, 0));
    std::vector<std::vector<char>> image2(N, std::vector<char>(2*M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            pin >> image1[i][j];
        }
    } 
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2*M; ++j) {
            pin >> image2[i][j];
            //std::cout << image2[i][j];
        }
        //std::cout << std::endl;
    } 
    std::vector<std::vector<char>> image3(N, std::vector<char>(2*M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2*M; j += 2) {
            image3[i][j] = image1[i][j];
            image3[i][j+1] = image1[i][j];

        }
    } 
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2*M; ++j) {
            std::cout << image3[i][j];
        }
        std::cout << std::endl;
    } 
    bool equality = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2*M; ++j) {
            if (image2[i][j] != image3[i][j]) {
                equality = false;
                break;
            }
        }
        if (!equality) {
            break;
        }
    } 
    if (equality) {
        std::cout << "Eyfa" << std::endl;
    } else {
        std::cout << "Not Eyfa" << std::endl;
    }
}
void genProbSolver::echo_input() {

}
void genProbSolver::process_solution() {
    
}
void genProbSolver::process_output(std::ostream &pout) {

}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("");
    probsolver.process_input(std::cin);
    probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


