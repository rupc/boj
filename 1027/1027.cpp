
//put, output 
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
// Declaration of variables


int N;
vector<int> heights;
vector<int> looks;
int sol;
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
    pin >> N;
    heights.resize(N);
    looks.resize(N);
    int tmp;
    for (int i = 0; i < N; i++) {
        pin >> tmp;
        heights[i] = tmp;
    }
}
void genProbSolver::echo_input() {
    for(const auto &p : heights) {
        cout << p << " ";
    } 
    cout << endl;
}
struct point {
    int x;
    int y;
    point(int ax, int ay)
        : x(ax), y(ay) {}
};
struct frac {
    long long int number;
    long long int denom;
    frac(int n, int d) : 
        number(n), denom(d) {}
    frac& operator = (frac &f) {
        number = f.number;
        denom = f.denom;
    }
    double get_frac() {
        return (double)number / (double)denom;
    }
    void set_frac(int num, int den) {
        number = num;
        denom = den;
    }
    frac() = default;
};

ostream& operator << (ostream& out, frac& f) {
    cout << f.number 
        << "/" << f.denom;
    return out;
}
frac get_gradient(point &p1, point &p2) {
    frac res(p2.y - p1.y, p2.x - p1.x);
    return res;
}
bool operator < (frac &f1, frac &f2) {
    if((f1.number * f2.denom) < (f2.number * f1.denom))
        return true;
    else return false;
    /*if(f1.get_frac() < f2.get_frac()) return true;
    else return false;*/
}
bool operator == (frac &f1, frac &f2) {
    if((f1.number == f2.number) &&
        (f1.denom == f2.denom)) return true;
    else return false;
}
void genProbSolver::process_solution() {
    vector<int> hi(move(heights));
    frac max_gradi; 
    for (int i = 0; i < N; i++) {
        if(i == N -1) break; 
        max_gradi.set_frac(hi[i+1] - hi[i], 1);
        for (int j = i+1; j < N; j++) {
            point p1(i, hi[i]);
            point p2(j, hi[j]);
            frac gradi = get_gradient(p1, p2);
            //cout << gradi << endl;
            if((max_gradi < gradi) ||
                max_gradi == gradi) {
                max_gradi = gradi;
                looks[i]++;
                looks[j]++;
                //cout << max_gradi << endl;
            }
            //cout << max_gradi << endl;
        }
        //cout << max_gradi << endl;
        //cout << endl;
    }
    const int most_see = *max_element(looks.begin(), looks.end());
    sol = most_see; 
}
void genProbSolver::process_output(ostream &pout) {
    cout << sol;
}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("");
    probsolver.process_input(std::cin);
    //probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


