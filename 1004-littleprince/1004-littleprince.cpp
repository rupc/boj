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
struct Circle {
    int x, y;
    int r;
    Circle(int ax, int ay, int ar) :
        x(ax), y(ay), r(ar) {}
};
// Declaration of auxiliary function
struct Point {
    int x;
    int y;
    Point(int ax, int ay) :
        x(ax), y(ay) {}
};
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
     for (int i = 0; i <T; i++) {
         int t1, t2, t3, t4;
         pin >> t1 >> t2 >> t3 >> t4;
         Point departure(t1, t2);
         Point destination(t3, t4);
         int num_of_planet;
         pin >> num_of_planet;
         vector<Circle> planets;
         for (int j = 0; j < num_of_planet; j++) {
             pin >> t1 >> t2 >> t3;
             planets.push_back(Circle(t1, t2, t3));
         }
         auto get_dist = [](int x1, int y1, 
                 int x2, int y2){
             return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
         };
         int num_of_inout = 0;
         for(const auto &p : planets) {
            double dep_dist =
                get_dist(departure.x, departure.y,
                         p.x, p.y);
            double des_dist =
                get_dist(destination.x, destination.y,
                         p.x, p.y);
            if(dep_dist < p.r) num_of_inout++;
            if(des_dist < p.r) num_of_inout++;
            if((dep_dist < p.r) &&
               (des_dist < p.r)) {
                num_of_inout--;
                num_of_inout--;
            }

         }
         cout << num_of_inout;
         if(i < T - 1) cout << endl;
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


