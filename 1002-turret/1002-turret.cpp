// input, output 
#include <iostream>
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
int T;
struct Point {
    int x;
    int y;
    Point(int ax, int ay) :
        x(ax), y(ay) {}
};
struct Circle {
    int x, y;
    int r;
    Circle(int ax, int ay, int ar) :
        x(ax), y(ay), r(ar) {}
};
bool operator == (Circle &c1, Circle &c2) {
    if((c1.x == c2.x) &&
       (c1.y == c2.y) &&
       (c1.r == c2.r)) return true;
    else return false;
}
int intersection_circle(Circle &c1, Circle &c2) {
    int res;
    int r_dist = c1.r + c2.r;
    if(c1 == c2) return -1; 
    auto get_dist = [](int x1, int y1, 
                   int x2, int y2){
        return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    };
    double dist = get_dist(c1.x, c1.y, c2.x, c2.y);
    int max_r = max(c1.r, c2.r);
    int min_r = min(c1.r, c2.r);
    // circle include another circle
    if(max_r - min_r == dist) return 1;
    else if(max_r - min_r > dist) return 0;
    else if(max_r + min_r == dist) return 1;
    else if(max_r + min_r > dist) return 2;
    else if(max_r + min_r < dist) return 0;
}
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
    pin >> T;
    int x1, y1, r1, x2, y2, r2;
    for (int i = 0; i < T; i++) {
        pin >> x1 >> y1 >> r1;
        pin >> x2 >> y2 >> r2;
        Circle c1(x1, y1, r1);
        Circle c2(x2, y2, r2);
        cout << intersection_circle(c1, c2) << endl;


    }
}
void genProbSolver::echo_input() {

}
void genProbSolver::process_solution() {

}
void genProbSolver::process_output(ostream &pout) {

}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("turret");
    probsolver.process_input(std::cin);
    probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


