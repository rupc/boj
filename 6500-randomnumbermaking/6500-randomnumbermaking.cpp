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
    string tmp;
    vector<string> table;
    set<string> stab;
    while(pin >> tmp) {
        if(tmp == "0") break;
        //table.push_back(tmp);
        stab.insert(tmp);
        while(1) {
            string a_square = to_string((int)pow(stoi(tmp), 2));
            if(a_square.size() < 8) {
                string zeros("");
                for (int i = 0; i < (8 - a_square.size()); i++) {
                    zeros += "0";
                }
                a_square.insert(0, zeros);
                //cout << a_square << endl;
            }
            string middle(a_square.begin()+2, a_square.begin() + 6);
            //cout << middle << endl;
            if(stab.find(middle) == stab.end()) {
                stab.insert(middle);
                tmp = middle;
            } else {
                cout << stab.size() << endl;
                break;
            }
            /*if(find(table.begin(), table.end(), middle)
                    == table.end()) {
                table.push_back(middle);
                tmp = middle;
            } else {
                cout << table.size() << endl;
                break;
            }*/
        }
        table.clear();
        stab.clear();
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


