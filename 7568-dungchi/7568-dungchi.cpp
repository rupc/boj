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
struct Dungchi {
    int weight;
    int height;
    int index;
    int ranking;
    Dungchi(int w, int h, int i, int r) :
        weight(w), height(h), index(i), ranking(r) {}
    inline void set_rank(int r) {
        ranking = r;
    }
};
/*bool operator > (Dungchi &lhs, Dungchi &rhs) {
    if(lhs.weight > rhs.weight && 
        lhs.height > rhs.height) {
        return true;
    } else return false;
}*/
ostream& operator << (ostream &out, Dungchi &rhs) {
    out << rhs.weight << "\t" << rhs.height << "\t"
        << rhs.index << endl;
    return out;
}
void genProbSolver::process_input(istream &pin) {
    int N;    
    vector<Dungchi> dungchies;
    int t1, t2, idx = 0;
    pin >> N;

    while(pin >> t1 >> t2)
        dungchies.emplace_back(t1, t2, idx++, N);
    for (int i = 0; i < N; i++) {
         for (int j = 0; j <N; j++) {
             if(i != j) {
                 int h1, h2, w1, w2;
                 w1 = dungchies[i].weight;
                 h1 = dungchies[i].height;
                 w2 = dungchies[j].weight;
                 h2 = dungchies[j].height;
                 if(w1 >= w2 || h1 >= h2) {
                    dungchies[i].ranking -= 1;
                 }
             }
         }
    }
    for(auto &p : dungchies) {
        cout << p.ranking << " ";
    }
    /*sort(dungchies.begin(), dungchies.end(),
            [](Dungchi &lhs, Dungchi &rhs){
            if((lhs.weight > rhs.weight) &&
                    (lhs.height > rhs.height)) {
                return true;
            } else return false;
        });
    int ranking = 1;
    dungchies[0].ranking = ranking;
    int overlap = 0;
    for(auto &p : dungchies) {
        cout << p;
    } 
    for (int i = 1; i < N; i++) {
        int h1, h2, w1, w2;
        w1 = dungchies[i-1].weight;
        h1 = dungchies[i-1].height;
        w2 = dungchies[i].weight;
        h2 = dungchies[i].height;

        if(((w1 > w2) &&
            (h1 > h2))) { 
            ++ranking;
            ranking += overlap;
            overlap = 0;
        } else if(w1 <= w2 || h1 <= h2) {
            overlap++;
        } 
        dungchies[i].ranking = ranking;
    }
    sort(dungchies.begin(), dungchies.end(),
            [](Dungchi &lhs, Dungchi &rhs){
                if(lhs.index < rhs.index) return true;
                else return false;
            });
    for (auto p : dungchies) {
        cout << p.ranking << " ";
    }*/
    /*cout << "Weight\tHeight\tRank" << endl;
    for(auto &p : dungchies) {
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


