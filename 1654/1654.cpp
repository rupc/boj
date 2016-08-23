// input, output 
#include <iostream>
// container
#include <vector>
// container adaper
// STL algorithm related
#include <algorithm>
// C standard library

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
    int K, N;
    pin >> K >> N;
    std::vector<long long> LANs(K);
    for (int i = 0; i < K; i++) {
        //pin >> LANs[i];
        scanf("%d", &LANs[i]);
    }
    std::sort(LANs.begin(), LANs.end());
    long long mid, start = 1, last = LANs[K-1];
    long long now = 0;
    /*for (auto &p : LANs) {
        std::cout << p << " ";
    }
    std::cout << std::endl;*/
    while (start <= last) {
        mid = (start + last) / 2;
        /*if (mid == 1) {
            break;
        }*/
        for (auto &p : LANs) {
            now += (p / mid);
        }
        //std::cout << start << " " << mid << " " << last << " | " << now << "\n";
        if (now < N) {
            last = mid - 1;
        } else {
            start = mid + 1;
        }
        now = 0;
    }
    std::cout << last;
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


