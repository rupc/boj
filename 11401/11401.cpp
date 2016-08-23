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
#include <deque>
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
unsigned long long binomialCoeff(int n, int k)
{
    unsigned long long C[n+1][k+1];
    int i, j;
    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
 
            // Calculate value using previosly stored values
            else {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
                C[i][j] %= 1000000007;
            }
        }
    }
 
    return C[n][k];
}
unsigned long long ibinomialCoeff(int n, int k)
{
    unsigned long long res = 1;
 
    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;
 
    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
        res %= 1000000007;
    }
 
    return res;
}
void genProbSolver::process_input(istream &pin) {
    int N, K;
    pin >> N >> K;
    std::cout << ibinomialCoeff(N,K) % 1000000007;
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


