#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>
#include <functional>
#include <map>
#include <list>
#include <stack>
#include <numeric>
// #define DEBUG
using namespace std;
// Declaration of variables

#define COUNT_SQUARE_FAIL (-1)
const char border_out = '.';
int n, m; // n : row, m : col
int solution;
vector<string> matrix;
vector<vector<int>> cache;
// Declaration of auxiliary function
//
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
void init_cache() {
    cache.resize(n+2);
    for (int i = 0; i < n+2; i++) {
        cache[i].resize(m+2);
        for (int j = 0; j < m+2; j++) {
            cache[i][j] = 0;
        }
    }
}
void init_matrix() {
    string tmp("");
    string tmp2(m+2, border_out);
    getline(cin, tmp);
    matrix.push_back(tmp2);
    for (int i = 1; i <= n; i++) {
        getline(cin, tmp);
        copy(tmp.begin(), tmp.end(), tmp2.begin() + 1);        
        matrix.push_back(tmp2);
    }
    matrix.emplace_back(string(m+2,border_out)); 
}
void genProbSolver::process_input(istream &pin) {
    pin >> n >> m;
    init_cache();
    init_matrix();
}
void genProbSolver::echo_input() {
    std::cout << matrix.size() << std::endl;
    for(const auto &p : matrix) {
        std::cout << p << std::endl;
    } 
}
int check_right_bottom_edge(int i, int j, int k);
void print_cache() {
    std::cout << "----print cache----" << std::endl;
    for(const auto &p : cache) {
        for(const auto &q :p)
            std::cout << q;
        cout << endl;
    }
}
void genProbSolver::process_solution() {
    int max_square = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // solution code start
            if(matrix[i][j] == '1') {
                int max_surrounding 
                    = max({cache[i][j-1], 
                            cache[i-1][j-1],
                            cache[i-1][j]
                            });
                int side_length = max_surrounding-1;            
                int k = side_length;
                while(check_right_bottom_edge(i, j, k)
                        != COUNT_SQUARE_FAIL) {
                    side_length++;
                    ++k;
                }
                if(side_length > max_square)
                    max_square = side_length;
                cache[i][j] = side_length;
            }
        }
    }
    solution = max_square;
    //print_cache();
}
// check_right_bottom_edge : O(n)
int check_right_bottom_edge(int i, int j, int k) {
    char bottom, right;
    int cnt = 0; // assume (i, j) in matrix is one
    for(int l = 0; l <= k; ++l) {
        bottom = matrix[i+k][j+l];
        right = matrix[i+l][j+k];
        if(bottom != '1' ||
           right  != '1') {
            return COUNT_SQUARE_FAIL;
        } else {
            cnt++; 
        }
    }
    return cnt;
}

void genProbSolver::process_output(ostream &pout) {
    cout << solution * solution;
}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("max-square");
    probsolver.process_input(std::cin);
    //probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


