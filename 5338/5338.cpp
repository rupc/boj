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
#include <unordered_map>
#include <unordered_set>
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
void genProbSolver::process_input(istream &pin) {
printf("       _.-;;-._ \n");
printf("'-..-'|   ||   |\n");
printf("'-..-'|_.-;;-._|\n");
printf("'-..-'|   ||   |\n");
printf("'-..-'|_.-''-._|");
}
void genProbSolver::echo_input() {
printf(".  .   .\n");
printf("|  | _ | _. _ ._ _  _\n");
printf("|/\\|(/.|(_.(_)[ | )(/.\n");
}
void genProbSolver::process_solution() {
printf("    8888888888  888    88888\n");
printf("   88     88   88 88   88  88\n");
printf("    8888  88  88   88  88888\n");
printf("       88 88 888888888 88   88\n");
printf("88888888  88 88     88 88    888888\n\n");
printf("88  88  88   888    88888    888888\n");
printf("88  88  88  88 88   88  88  88\n");
printf("88 8888 88 88   88  88888    8888\n");
printf(" 888  888 888888888 88  88      88\n");
printf("  88  88  88     88 88   88888888\n");
}
void genProbSolver::process_output(ostream &pout) {
    printf("SHIP NAME      CLASS          DEPLOYMENT IN SERVICE\n");
    printf("N2 Bomber      Heavy Fighter  Limited    21        \n");
    printf("J-Type 327     Light Combat   Unlimited  1         \n");
    printf("NX Cruiser     Medium Fighter Limited    18        \n");
    printf("N1 Starfighter Medium Fighter Unlimited  25        \n");
    printf("Royal Cruiser  Light Combat   Limited    4          ");
}
void res() {

printf("NFC West       W   L  T\n");
printf("-----------------------\n");
printf("Seattle        13  3  0\n");
printf("San Francisco  12  4  0\n");
printf("Arizona        10  6  0\n");
printf("St. Louis      7   9  0\n");
printf("\n");
printf("NFC North      W   L  T\n");
printf("-----------------------\n");
printf("Green Bay      8   7  1\n");
printf("Chicago        8   8  0\n");
printf("Detroit        7   9  0\n");
printf("Minnesota      5  10  1");
}
void catprint() {
printf("\\    /\\\n");
printf(" )  ( ')\n");
printf("(  /  )\n");
printf(" \\(__)|");
}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("");
    //probsolver.process_input(std::cin);
    //probsolver.echo_input();
    //probsolver.process_solution();
    //probsolver.process_output(std::cout);
    //catprint();
    //printf("280\nrupc");
    wchar_t a = 'ㅁ';
    std::cout << a;
    return 0;
}


