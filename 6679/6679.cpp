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
void genProbSolver::process_input(istream &pin) {

}
string convert_dec_to_duodec(string &dec) {
    int num = stoi(dec);
    int quot = num / 12;
    int rem = num % 12;
    num = quot;
    string res("");
    if(rem == 10) res += "a";
    if(rem == 11) res += "b";
    else
        res += to_string(rem);

    while(num != 0) {
        num = quot;
        quot = num / 12;
        rem = num % 12;

        if(rem == 10) res += "a";
        if(rem == 11) res += "b";
        else res += to_string(rem);

    }
    reverse(res.begin(), res.end());
    return res;
}
string ConvertToDuodecimal(unsigned long long n)
{
  if (n < 12)
    return string() + "0123456789ab"[n];
  return ConvertToDuodecimal(n / 12) + ConvertToDuodecimal(n % 12);
}
string ConvertToHex(unsigned long long n) {
    if(n < 16) 
        return string() + "0123456789abcdef"[n];
    return ConvertToHex(n / 16) + ConvertToHex(n % 16);
}
void genProbSolver::echo_input() {
    for (int i = 1000; i <= 9999; i++) {
        string decimal(to_string(i));
        string duodecimal(ConvertToDuodecimal(i));
        string hexa(ConvertToHex(i));
        int decsum = 0, duosum = 0, hexsum = 0;
        for (unsigned j = 0; j < decimal.size(); j++) {
            decsum += decimal[j] - '0';
        }
        for (unsigned j = 0; j < duodecimal.size(); j++) {
            if(isalpha(duodecimal[j])) {
                duosum += duodecimal[j] - 'a' + 10;
            } else duosum += duodecimal[j] - '0';
        }
        for (unsigned j = 0; j < hexa.size(); j++) {
            if(isalpha(hexa[j])) {
                hexsum += hexa[j] - 'a' + 10;
                //cout << "hexa[j]:" << hexa[j] << endl;
            } else hexsum += hexa[j] - '0'; 
        }
        /*if(i == 2992) {
            cout << decimal << " " << duodecimal << " " << hexa << endl;
            cout << decsum << " " << duosum << " " << hexsum << endl;
        }*/
        if(decsum == duosum &&
                duosum == hexsum) {
            cout << i << endl;
        }
    }
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


