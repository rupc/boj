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
void print_tomato(vector<vector<int>> to) {
    for (unsigned i = 0; i < to.size(); i++) {
        for (unsigned j = 0; j < to[i].size(); j++) {
            cout.width(3);
            cout << to[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
#define FENCE (9)
#define RIPEN (1)
#define UNRIPEN (0)
#define EMPTY (-1)
int N, M;
vector<vector<int>> tomato;
vector<vector<int>> vtomato;
int max_tomato;
queue<pair<int, int>> matoq;
int immature_cnt = 0;
void genProbSolver::process_input(istream &pin) {
    pin >> M >> N;
    int tmp;
    tomato.resize(N+2);
    vtomato.resize(N+2);
    for (int i = 0; i < N+2; i++) {
        tomato[i].resize(M+2);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            pin >> tmp;
            tomato[i][j] = tmp;
            if(tmp == RIPEN) {
                matoq.push(make_pair(i, j));
            }
        }
    }
    matoq.push(make_pair(-1, -1));
    int empty_cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if(tomato[i][j] == -1) {
                empty_cnt++;
            }
            if(tomato[i][j] == 0) {
                immature_cnt++;
            }
        }
    }
    if(empty_cnt == N * M) {
        cout << "-1";
        exit(0);
    }
    max_tomato = N * M - empty_cnt;
    bool all_mature = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if(tomato[i][j] == UNRIPEN) {
                all_mature = false;
                break;
            }
        }
        if(all_mature == false) {
            break;
        }
    }
    if(all_mature == true) {
        cout << "0";
        exit(0);
    }
    for (int i = 0; i < M+2; i++) {
        tomato[0][i] = FENCE;
        tomato[N+1][i] = FENCE;
    }
    for (int i = 0; i < N+2; i++) {
        tomato[i][0] = FENCE;
        tomato[i][M+1] = FENCE;
    }
    copy(tomato.begin(), tomato.end(), vtomato.begin());
    //cout << "original" << endl;
    //print_tomato(vtomato);
}
void genProbSolver::echo_input() {

}
bool operator == (vector<int> &v1, vector<int> &v2) {
    const int sz = v1.size();
    bool same_thing = true;
    for (int i = 0; i < sz; i++) {
        if(v1[i] != v2[i]) {
            same_thing = false;
            break;
        }
    }
    return same_thing;
}
void update_next_tomato_state() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if(tomato[i][j] == RIPEN) {
                // east
                if(tomato[i][j+1] == UNRIPEN) {
                    vtomato[i][j+1] = RIPEN;
                }
                // west
                if(tomato[i][j-1] == UNRIPEN) {
                    vtomato[i][j-1] = RIPEN;
                }
                // south
                if(tomato[i+1][j] == UNRIPEN) {
                    vtomato[i+1][j] = RIPEN;
                }
                // north
                if(tomato[i-1][j] == UNRIPEN) {
                    vtomato[i-1][j] = RIPEN;
                }
            }
        }
    }
    /*cout << "tomato" << endl;
    print_tomato(tomato);
    cout << endl;
    cout << "vtomato" << endl;
    print_tomato(vtomato);*/
    if(equal(tomato.begin(), tomato.end(), vtomato.begin())) {
        cout << "-1";
        exit(0);
    } else {
        copy(vtomato.begin(), vtomato.end(), tomato.begin());
    }
}
int count_mature_tomato() {
    int mature = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if(tomato[i][j] == RIPEN) {
                mature++;
            }
        }
    }
    return mature;
}
int ripen_days;
void genProbSolver::process_solution() {
    int days = 0;
    //const int total = max_tomato;
    int immature = 0;
    //int ripen_tomato_prev = -2;
    vector<pair<int, int>> tmp_pairs;
    while(!matoq.empty()) {
        pair<int, int> curr 
            = matoq.front();
        int x = curr.first;
        int y = curr.second;
        matoq.pop();
        if(x == -1 && y == -1) {
            if(!matoq.empty()) {
                days++;
                matoq.push(make_pair(-1, -1));
                continue;
            } else {
                break;
            }
        }
        pair<int, int> east = make_pair(x+1, y);
        pair<int, int> west = make_pair(x-1, y);
        pair<int, int> south = make_pair(x, y+1);
        pair<int, int> north = make_pair(x, y-1);
        if(tomato[x+1][y] == UNRIPEN) {
            tomato[x+1][y] = RIPEN;
            immature++;
            matoq.push(east);
        }
        if(tomato[x-1][y] == UNRIPEN) {
            tomato[x-1][y] = RIPEN;
            immature++;
            matoq.push(west);
        }
        if(tomato[x][y+1] == UNRIPEN) {
            tomato[x][y+1] = RIPEN;
            immature++;
            matoq.push(south);
        }
        if(tomato[x][y-1] == UNRIPEN) {
            tomato[x][y-1] = RIPEN;
            immature++;
            matoq.push(north);
        }
        //print_tomato(tomato);
    }
    //std::cout << immature << std::endl;
    if(immature_cnt == immature) {
        ripen_days = days;
    } else {
        cout << "-1";
        exit(1);
    }
    /*if(days == total) {
        cout << days;
        exit(1);
    } else {
        cout << "-1";
        exit(1);
    }*/
    /*while(1) {
        update_next_tomato_state();
        int ripen_tomato = count_mature_tomato();
        if(ripen_tomato == ripen_tomato_prev) {
            cout << "-1";
            exit(1);
        } else {
            ripen_tomato_prev = ripen_tomato;
        }
        ++days;
        if(ripen_tomato == total) {
            break;
        }
    }*/
    ripen_days = days;
}
void genProbSolver::process_output(ostream &pout) {
    cout << ripen_days;
}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("");
    probsolver.process_input(std::cin);
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}


