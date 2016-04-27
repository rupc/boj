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
struct nation {
    int num;
    int gold;
    int silver;
    int bronz;
    int rate;
    nation(int n, int g, int s, int b, int r) :
        num(n), gold(g), silver(s), bronz(b), rate(r) {}

};
bool operator > (nation &lhs, nation &rhs) {
    if(lhs.gold > rhs.gold) return true;
    else if(lhs.gold == rhs.gold) {
        if(lhs.silver > rhs.silver) return true;
        else if(lhs.silver == rhs.silver) {
            if(lhs.bronz > rhs.bronz) return true;
            else return false;
        } else return false;
    } else return false;
}

bool operator == (nation &lhs, nation &rhs) {
    if(lhs.gold == rhs.gold &&
        lhs.silver == rhs.silver &&
        lhs.bronz == rhs.bronz) return true;
    else return false;
}
ostream& operator << (ostream &out, nation &rhs) {
    out << rhs.num << "\t" << rhs.gold << "\t"
        << rhs.silver << "\t" << rhs.bronz << "\t"
        << rhs.rate << endl;
    return out;
}
void genProbSolver::process_input(istream &pin) {
    int N, k;
    pin >> N >> k;
    int t1, t2, t3, t4;
    vector<nation> nations;
    while(pin >> t1 >> t2 >> t3 >> t4) {
        nations.emplace_back(t1, t2, t3, t4, N);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(i != j) {
                if((nations[i] > nations[j])) {
                    nations[i].rate -= 1;
                } else if(nations[i] == nations[j]) {
                    nations[i].rate -= 1;
                }
            }
        }
    }
    auto find_match 
        = find_if(nations.begin(), nations.end(),
                [&](nation &lhs){
                   if(lhs.num == k) return true; 
                   else return false;
                });
    cout << find_match->rate;
    //cout << nations[3-1].rate;
    /*for(auto p : nations) {
        cout << p;
    }*/
    
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


