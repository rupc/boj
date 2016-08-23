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
    int R, C, T;
    pin >> R >> C;
    std::vector<vector<int>> images(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            pin >> images[i][j];
        }
    }
    pin >> T;
    std::vector<vector<int>> filtered_imgs(R-2, vector<int>(C-2));
    vector<int> filter(9);
    for (int i = 0; i < R-2; i++) {
        for (int j = 0; j < C-2; j++) {
            for (int k = 0; k < 9; k++) {
                //std::cout << i+k/3 << " " << j+k%3 << std::endl;
                filter[k] = images[i+k/3][j+k%3];
            }
            /*filter[0] = filtered_imgs[i][j];
            filter[1] = filtered_imgs[i][j+1];
            filter[2] = filtered_imgs[i][j+2];
            filter[3] = filtered_imgs[i+1][j];
            filter[4] = filtered_imgs[i+1][j+1];
            filter[5] = filtered_imgs[i+1][j+2];
            filter[6] = filtered_imgs[i+2][j];
            filter[7] = filtered_imgs[i+2][j+1];
            filter[8] = filtered_imgs[i+2][j+2];*/
            std::sort(filter.begin(), filter.end());
            filtered_imgs[i][j] = filter[4];
        }
    }
    int sum = 0;
    for (int i = 0; i < R-2; i++) {
        sum += std::count_if(filtered_imgs[i].begin(), filtered_imgs[i].end(),
                    [&](int &elem) {
                        if (elem >= T) {
                            return true;
                        } else return false;
                    }); 
    }
    std::cout << sum;
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


