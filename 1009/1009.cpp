// input, output 
#include <iostream>
#include <vector>
// #define DEBUG
using namespace std;
// Declaration of variables


// Declaration of auxiliary function
class genProbSolver {
    public:
        genProbSolver(string s) : name(s) {}
        void process_input();
        void process_solution();
        void process_output();
        void echo_input();
    private:
        string name;
};
void genProbSolver::process_input() {
    int T;
    cin >> T;
    std::vector<int> last_computers(T);
    int cnt = 0;
    while (T--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int t = a;
        if (b == 1) {
            t %= 10;
        } else {
            while (b-- > 1) {
                t *= a;
                t %= 10;
            }
        }
        if (t == 0) t = 10;
        last_computers[cnt++] = t;
    }
    for (auto &c : last_computers) {
        printf("%d\n", c);
    }
}
void genProbSolver::echo_input() {

}
void genProbSolver::process_solution() {
    
}
void genProbSolver::process_output() {

}
int main(void) {
    genProbSolver probsolver("");
    probsolver.process_input();
    probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output();
    return 0;
}


