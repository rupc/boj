// input, output 
#include <iostream>
#include <cmath>
// container
#include <vector>
#include <array>
#include <list>
#include <map>
#include <set>
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

//
// #define DEBUG
using namespace std;
#define STATE_INC 1
#define STATE_DEC 0
// Declaration of variables
int n;
vector<int> seq;
int solution;
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
   pin >> n; 
   int tmp;
   while(pin >> tmp) seq.push_back(tmp);
}
void genProbSolver::echo_input() {
    for(const auto &p : seq)
        cout << p << " ";
}

void genProbSolver::process_solution() {
   int isz, imax, dsz, dmax;
   isz = imax = dsz = dmax = 1;
   int equ = 0;
   int curr_state, prev_state;
   curr_state = prev_state = 
       (seq[0] < seq[1]) ? STATE_INC : STATE_DEC;

   /*cout << "isz\t" << "imax\t" 
       << "dsz\t" << "dmax\t" << "equ" << endl;*/
   for (int i = 1; i < seq.size(); i++) {
       if(seq[i-1] < seq[i]) {
           if(dsz > dmax) {
               dmax = dsz;
           }
           dsz = 1; 
           curr_state = STATE_INC;
           if(curr_state != prev_state) {
               prev_state = curr_state;
               isz += equ + 1;
           } else {
               isz++;
           }
           equ = 0;           
       } else if(seq[i-1] > seq[i]) {
           if(isz > imax){
               imax = isz;
           }
           isz = 1; 
           curr_state = STATE_DEC;
           if(curr_state != prev_state) {
               prev_state = curr_state;
               dsz += equ + 1;
           } else {
               dsz++;
           }
           equ = 0;
       } else if(seq[i-1] == seq[i]) {
            if(isz > 1) isz++;
            else dsz++;
            ++equ;
       }

       /*cout << isz << "\t" << imax << "\t"
           << dsz << "\t" << dmax << "\t"
           << equ << endl;*/
   }
   if(isz > imax) imax = isz;
   if(dsz > dmax) dmax = dsz;
   solution = max(imax, dmax);
}
void genProbSolver::process_output(ostream &pout) {
    cout << solution;
}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("");
    probsolver.process_input(std::cin);
    //probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


