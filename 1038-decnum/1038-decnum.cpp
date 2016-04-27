// 
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

vector<vector<vector<vector<int>>>> matrix(10);
vector<vector<int>> table(10);
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
void print_table() {
    for(const auto &p : table) {
        for(const auto &q : p) {
            cout.width(3);
            cout << q << " "; 
        }
        cout << endl;
    }
}
void print_matrix() {
    for(const auto &p :matrix) {
        for(auto &q : p) {
            for(auto &r : q) {
                for(auto &s : r) {
                    cout << s << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
}
void genProbSolver::process_input(istream &pin) {
    for (int i = 0; i < table.size(); i++) {
        table[i].resize(10); 
    }
    for (int i = 0; i < 10; i++) {
        table[0][i] = 0; 
        table[i][0] = 1;
    }

    for (int i = 1; i < 10; i++) {
        for (int j = 1; j <= i; j++) {
            table[i][j] = table[i-1][j-1] + table[i-1][j];
        }
    }
    int sum = 0;
    for(const auto &p : table) {
        sum += accumulate(p.begin(), p.end(), 0);
    }
    int N;
    pin >> N;
    if(N > sum) {
        cout << "-1";
        return;
    } else {
         for (int i = 0; i <10; i++) {
             matrix[i].resize(10); 
         }
         // init first column to vector {1}
         for (int i = 0; i < 10; i++) {
             vector<vector<int>> seqs(1);
             seqs.push_back({i+1});
             matrix[i][0] = seqs;
         }
         // init first row to vector {0}
         for (int i = 0; i < 10; i++) {
             vector<vector<int>> seqs(1);
             seqs.push_back({0});
             matrix[0][i] = seqs;
         }
         //print_matrix();
         for (int i = 1; i < 10; i++) {
             for (int j = 1; j <= i; j++) {
                 const int sz = table[i][j];
                 matrix[i][j].resize(sz);
                 // insert first digit;
                 for (int k = 0; k < sz; k++) {
                     matrix[i][j][k].push_back(i);
                 }

                 for (int k = j-1; k < i-j+1; k++) {
                     //matrix[i][k] 
                 }


             }
         }

    }


    cout << sum << endl;
    print_table();
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


