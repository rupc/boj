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
    vector<int> vi;
    int tmp;
    while(pin >> tmp) vi.push_back(tmp);
    vector<bool> sel(vi.size());
    fill(sel.begin() + vi.size() - 7, sel.end(), true);
    do {
        int sum = 0;
        for (unsigned i = 0; i < sel.size(); i++) {
            if(sel[i] == true) {
                sum += vi[i];
                //cout << vi[i] << " ";
            }
        }
        //cout << endl;
        if(sum == 100) {
            for (unsigned i = 0; i < sel.size(); i++) {
                if(sel[i] == true) {
                    cout << vi[i] << endl;
                }
            }
        }
    } while(next_permutation(sel.begin(), sel.end()));

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
    vector<int> vi = {1,2,3,4};
    vector<bool> sel(5);
    /*fill(sel.begin() + 5 - 3, sel.end(), true);
    do {
        for (int i = 0; i < 5; i++) {
            if(sel[i] == true) {
                cout << vi[i] << " ";
            }
        }
        cout << endl;
    } while(next_permutation(sel.begin(), sel.end()));*/
    /*do {
        for (unsigned i = 0; i < vi.size(); i++) {
            cout << vi[i] << " ";
        }
        cout << endl;
    } while(next_permutation(vi.begin(), vi.end()));*/
    return 0;

}


