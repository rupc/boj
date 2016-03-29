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
#include <forward_list>
//#define DEBUG
using namespace std;
// Declaration of variables
// string-bomb.in
list<char> sentence;
string bomb(""), after_all("FRULA"), residue("");
int sol_flg;
#define BOMB_EVERY 0
#define BOMB_RESIDUE 1
// Declaration
// of auxiliary function
template<class T>
void pretty_print(list<T> ls){
    std::cout << "[";    
    for (auto i = ls.begin(); i != ls.end(); ++i) {
        if(i != prev(ls.end()))
            std::cout << *i << "-";
        else std::cout << *i;
    }   
    std::cout << "]" << std::endl;
}
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
    auto it = back_inserter(sentence);
    string tmp;
    pin >> tmp;
    copy(tmp.begin(), tmp.end(), it);
    pin >> bomb;
}
void genProbSolver::echo_input() { 
    pretty_print(sentence);
    std::cout << "bomb : " << bomb << endl;;
}
inline void set_sol_flag() {
    if(!sentence.empty()) {
        sol_flg = BOMB_RESIDUE; 
        residue.resize(sentence.size());
        copy(sentence.begin(), sentence.end(), residue.begin());
    } else {
        sol_flg = BOMB_EVERY;
    }
}
void genProbSolver::process_solution() {
    // 문제 조건에 의해 폭탄 단어의 모든 문자는 서로 다름
    const char pre_bomb = bomb[0];
    const int bomb_size = bomb.size();
    int cnt_order = 0;
    stack<int> bomb_can;
    bool potential = false;
#ifdef DEBUG
    std::cout << "sentence sz : " << sentence.size() << std::endl;
    std::cout << pre_bomb << post_bomb << std::endl;
    cout << "cnt\t" << "*p"<< endl;
#endif
    if(bomb_size == 1) {
        sentence.remove(pre_bomb);
        return;
    }
    for(auto p = sentence.begin(); p != sentence.end(); ++p) {
        const char target = *p;
#ifdef DEBUG
        cout << cnt_order << "\t" << *p << endl;
#endif
        if(cnt_order == bomb_size) {
            if(!bomb_can.empty()) {
                const int next_pop = bomb_can.top();
                bomb_can.pop();
                cnt_order = next_pop;
            }
            sentence.erase(prev(p,bomb_size), p);
        }
        if(target == pre_bomb) {
            if(potential) {
                // next character potential to combine with
                bomb_can.push(cnt_order);
            } else {
                // appear first bomb character
                potential = true;
            }
            cnt_order = 1;
            continue;
        }
        if(target == bomb[cnt_order]) {
            ++cnt_order;
        } else {
            cnt_order = 0;
            potential = false;
        }
    }
    string tmp(sentence.rbegin(), next(sentence.rbegin(), bomb_size));
    reverse(tmp.begin(), tmp.end());
    auto trail_end = sentence.end();
    if(tmp == bomb) {
        sentence.erase(prev(sentence.end(), bomb_size), trail_end);
    } 
}
void genProbSolver::process_output(ostream &pout) {
    set_sol_flag();

    if(sol_flg == BOMB_EVERY) std::cout << after_all;
    else if(sol_flg == BOMB_RESIDUE) std::cout << residue;
}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("");
    probsolver.process_input(std::cin);
#ifdef DEBUG
    probsolver.echo_input();
#endif
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


