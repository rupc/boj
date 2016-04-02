// input, output 
#include <ctime>
#include <iostream>
// container
#include <vector>
// container adaper
#include <stack>
// STL algorithm related
#include <utility>
//
// #define DEBUG
using namespace std;
// Declaration of variables
int num_of_tower;
vector<int> towers(500000);
vector<int> comm_tab(500000);
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
    int tmp;
    int max_height = 0;
    pin >> num_of_tower;
    for (int i = 0; i < num_of_tower; i++) {
        pin >> tmp;
        if(tmp > max_height) {
            max_height = tmp;
            comm_tab[i] = 0;
            //cout << "0 ";
        } else {
            for(int j = i-1; j >= 0; --j) {
                if(towers[j] > tmp) {
                    comm_tab[i] = j+1;
                    //cout << j+1 << " ";
                    break;
                } else {
                    j = comm_tab[j]; 
                }
            }
        }
        towers[i] = tmp; 
    }
}
void genProbSolver::echo_input() {
    cout << towers.size() << endl;
}
void genProbSolver::process_solution() {
    stack<pair<int, int>> stk;
    int num, tmp; 
    int idx = 0;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> tmp; 
        while(!stk.empty()) {
            if(stk.top().second > tmp) {
                //cout << stk.top().first << " ";
                break;
            }
            stk.pop();
        }
        //if(stk.empty()) cout << "0 ";
        stk.push(make_pair(i, tmp));
    }
}
void genProbSolver::process_output(ostream &pout) {
}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("");
    double interval;
    clock_t t1 = clock();
    probsolver.process_solution();
    clock_t t2 = clock();
    interval = (double)(t2 - t1) / CLOCKS_PER_SEC;
    cout << "stack strategy : " << interval << endl;

    cin.seekg(0);

    clock_t t3 = clock();
    probsolver.process_input(std::cin);
    clock_t t4 = clock();
    interval = (double)(t4 - t3) / CLOCKS_PER_SEC;
    cout << "table strategy : " << interval << endl;
    return 0;
}


