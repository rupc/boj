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
#include <sstream>
#include <string>
// #define DEBUG
using namespace std;
// Declaration of variables
#define INST_SZ 3
#define STACK_ERROR -1
#define STACK_NUM_LIMIT 1000000000
#define STACK_END -2
int repeat;
vector<int> input_vec;
stack<int> go_stack;
int curr_input;
list<string> inst_list;
void process_instruction(string &inst) {
    string prefix(inst.begin(), inst.begin() + INST_SZ);
    //std::cout << prefix << std::endl;
    if(prefix == "END") {
        throw STACK_END;
    }
    if(prefix == "NUM") {
        string tmp(inst.begin() + INST_SZ, inst.end());
        int push_val = atoi(tmp.c_str());
        go_stack.push(push_val);
    } else if (prefix == "POP") {
        if(go_stack.empty()) throw STACK_ERROR;
        go_stack.pop(); 
    } else if (prefix == "INV") {
        if(go_stack.empty()) throw STACK_ERROR;
        int inv_val = -go_stack.top(); go_stack.pop();
        go_stack.push(inv_val);
    } else if (prefix == "DUP") {
        if(go_stack.empty()) throw STACK_ERROR;
        go_stack.push(go_stack.top()); 
    } else { // binary operation
        if(go_stack.size() < 2) throw STACK_ERROR;
        int itmp1, itmp2, res;
        itmp1 = go_stack.top();
        go_stack.pop();
        itmp2 = go_stack.top();
        go_stack.pop();
        if (prefix == "SWP") {
            go_stack.push(itmp1);
            go_stack.push(itmp2);
        } else if (prefix == "ADD") {
            long long int res = (long long int)itmp1 + itmp2;
            if(res > STACK_NUM_LIMIT) throw STACK_NUM_LIMIT;
            go_stack.push(res);
        } else if (prefix == "SUB") {
            long long int res = (long long int)itmp2 - itmp1;
            if(abs(res) > STACK_NUM_LIMIT) throw STACK_NUM_LIMIT;
            go_stack.push(res);
        } else if (prefix == "MUL") {
            long long int res = (long long int)itmp1 * itmp2;
            if(res > STACK_NUM_LIMIT) throw STACK_NUM_LIMIT;
            go_stack.push(res);
        } else if (prefix == "DIV") {
            if(itmp1 == 0) throw STACK_ERROR;
            res = abs(itmp2) / abs(itmp2);
            if((itmp2 < 0) && (itmp1 > 0) ||
               (itmp2 > 0) && (itmp1 < 0))
                res -= res;
            go_stack.push(res);
        } else if (prefix == "MOD") {
            if(itmp1 == 0) throw STACK_ERROR;
            res = abs(itmp2) % abs(itmp1); 
            if(itmp2 < 0) res = -res;
            go_stack.push(res);
        }
    }
}
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
void read_directives(string &tmp) {
    repeat = atoi(tmp.c_str());
    int itmp;
    input_vec.resize(repeat);
    for (int i = 0; i < repeat; i++) {
        cin >> itmp;
        //cout << itmp << endl;
        input_vec[i] = itmp;
    }

    //getline(cin, tmp);
}
void print_current_instruction() {
    for(const auto &p : inst_list) 
        cout << p << endl;
}
void genProbSolver::process_input(istream &pin) {
    string tmp("");
    int input_num = 1;
    // read instruction
    while(getline(pin, tmp)) {
        if(tmp == "QUIT") {
            //std::cout << tmp << std::endl;
            break; 
        }
        if(tmp.empty()) {
            continue;
        }
        if(isalpha(tmp[0])) {
            inst_list.push_back(tmp);
        } else {
            //std::cout << tmp << std::endl;
            // read directives
            read_directives(tmp);        
            // instruction processing start here.
            //print_current_instruction();
            for (int i = 0; i < input_vec.size(); i++) {
                curr_input = input_vec[i];
                go_stack.push(curr_input);
                // process one input
                for(auto &p : inst_list) {
                    try {
                        process_instruction(p);
                    } catch(int n) {
                        if(n == STACK_ERROR) {
                            cout << "ERROR";
                            break;
                        } else if(n == STACK_NUM_LIMIT) {
                            cout << "ERROR";
                            break;
                        } else if(n == STACK_END) {
                            if(go_stack.size() == 1) {
                                cout << go_stack.top();
                            } else {
                                cout << "ERROR";
                            }
                        }
                    }
                }
                cout << endl;
                // after processing one input
                // clear stack
                while(!go_stack.empty())
                    go_stack.pop();
            }
            cout << endl;
            // after one test case,
            // clear instruction list, input vector
            inst_list.clear();
            input_vec.clear();
        }
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


