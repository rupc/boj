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
    vector<int> gan(10);
    vector<char> izi(12);
    for (int i = 0; i < 10; i++) {
        gan[i] = i; 
    }
    char ch = 'A';
    for (int i = 0; i < 12; i++) {
        izi[i] = ch++;  
    }
    int year;
    pin >> year;
    --year;
    int remain = year % 60;
    int gan_cnt = 0;
    int izi_cnt = 0;
    for (int i = 0; i < remain; i++) {
        ++gan_cnt; 
        ++izi_cnt;
    }
    gan_cnt -= 3;
    izi_cnt -= 3;
    gan_cnt %= 10;
    izi_cnt %= 12;
    printf("%c%d", izi[izi_cnt], gan[gan_cnt]);
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


