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
    double a, b, c, res;
    char unknown = 'z';
    int case_number = 1;
    bool err_flg = false;
    while(pin >> a >> b >> c) {
        if(a == 0 && b == 0 && c == 0) {
            break;
        } 

        if(a == -1) unknown = 'a';
        if(b == -1) unknown = 'b';
        if(c == -1) unknown = 'c';
        if(unknown == 'c') {
            res = sqrt(pow(a,2) + pow(b,2));
        } else if(unknown == 'a') {
            double test = pow(c,2) - pow(b,2);
            if(test <= 0) {
                err_flg = true; 
            } else {
                res = sqrt(test);
            }
        } else if(unknown == 'b') {
            double test = pow(c,2) - pow(a,2);
            if(test <= 0) {
                err_flg = true;
            } else {
                res = sqrt(test);
            }
        } 

        cout << "Triangle #" << case_number << endl;
        if(err_flg) {
            cout << "Impossible." << endl;
            err_flg = false;
        } else {
            cout << unknown << " = " << fixed << setprecision(3) << res << endl;
        }
        cout << endl;
        case_number++;
    }
}
void genProbSolver::echo_input() {

}
void genProbSolver::process_solution() {
    
}
void genProbSolver::process_output(ostream &pout) {

}
int main(int argc, const char *argv[]) {
    /*cout << __TIME__ << endl;
    cout << __LINE__ << endl;
    cout << __FILE__ << endl;
    cout << __DATE__ << endl;*/
    printf("%s\n%d\n%s\n%s\n", __TIME__, __LINE__, __FILE__, __DATE__);
    genProbSolver probsolver("");
    probsolver.process_input(std::cin);
    probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


