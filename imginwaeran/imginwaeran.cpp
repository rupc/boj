#include <iostream>
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
int N, out_a, out_b;
map<int, int> original;
struct ans {
    friend ostream& operator << (ostream &out, const ans &lhs);
    int hash_val;
    int order;
    int real_order;
    ans(int h, int o, int r) :
        hash_val(h), order(o), real_order(r) {}
    bool operator < (ans &lhs) {
       if(real_order < lhs.real_order) return true;
       else return false;
    }
};
ostream& operator << (ostream &out, const ans &lhs) {
     out << lhs.hash_val << ", " << lhs.order << ", "
        << lhs.real_order << endl;
     return out;
}
vector<ans> commit;
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
    string tmp("");
    auto bi = back_inserter(commit);
    hash<string> str_hash;
    int cnt = 1;
    int h_val;
    for (int i = 0; i < N; i++) {
        pin >> tmp;
        original[str_hash(tmp)] = cnt++;
    }
    cnt = 1;
    for (int i = 0; i < N; i++) {
        pin >> tmp;
        h_val = str_hash(tmp);
        *bi = ans(h_val, cnt++, original[h_val]);
    }
}
void genProbSolver::echo_input() {
    std::cout << "N : " << N << std::endl;
    std::cout << "=============" << std::endl;
    for(const auto &p : original)
        std::cout << p.first << ", " << p.second << std::endl;
    std::cout << "=============" << std::endl;
    for(const auto &p : commit)
        std::cout << p << std::endl;

}
void genProbSolver::process_solution() {
    int score = 0;
    sort(commit.begin(), commit.end()); 
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            //std::cout << i+1 << " and " << j+1 << std::endl;
            if(commit[i].order < commit[j].order) {
                //std::cout << commit[i] << " " << commit[j];
                ++score;
            }
        }   
        //std::cout << std::endl;
    }
    out_a = score;
}
void genProbSolver::process_output(ostream &pout) {
    out_b =  (N * (N - 1) / 2);
    pout << out_a << "/" << out_b; 
}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("imginwaeran");
    probsolver.process_input(std::cin);
    //probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


