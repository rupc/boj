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
struct Student {
    string name;
    int day;
    int month;
    int year;
    Student(string n, int d, int m, int y) 
        : name(n), day(d), month(m), year(y) {}
};
bool operator < (Student &lhs, Student &rhs) {
    if(lhs.year < rhs.year) return true;
    else if(lhs.year == rhs.year) {
        if(lhs.month < rhs.month) return true;
        else if(lhs.month == rhs.month) {
            if(lhs.day < rhs.day) return true;
            else return false;
        } else return false;
    } else return false;
}
void genProbSolver::process_input(istream &pin) {
    int n;
    pin >> n;
    string name;
    int year, month, day;
    vector<Student> students;
    while(pin >> name >> day >> month >> year) {
        students.emplace_back(name, day, month, year);
    }
    sort(students.begin(), students.end());
    cout << students.back().name << endl;
    cout << students.front().name << endl;


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


