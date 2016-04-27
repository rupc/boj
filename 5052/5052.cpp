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
    int t;
    pin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        pin >> n;
        vector<string> phone_nums(n);
        string tmp;
        for (int j = 0; j < n; j++) {
            pin >> tmp;
            phone_nums[j] = tmp;
        }

        bool yes_no = true;
        sort(phone_nums.begin(), phone_nums.end());
        /*for(const auto p : phone_nums) {
            std::cout << p << std::endl;
        }*/
        for (int i = 1; i < n; i++) {
            bool equ
                = equal(phone_nums[i-1].begin(), phone_nums[i-1].end(),
                        phone_nums[i].begin());
            if(equ == true) {
                yes_no = false;
                break;
            }
        }
        /*for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if(j != k) {
                    if(phone_nums[j].size() <= phone_nums[k].size()) {
                        string subs(phone_nums[k].substr(0, phone_nums[j].size()));
                        if(subs == phone_nums[j]) {
                            yes_no = false;
                            break;
                        }
                    }
                }
            }
            if(yes_no == false) {
                break;
            }
        }*/
        if(yes_no == true) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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


