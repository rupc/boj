// input, output 
#include <iostream>
#include <iomanip>
// container
#include <vector>
#include <array>
#include <list>
#include <map>
#include <unordered_map>
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


#define DIST_INF 100000
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
// id, dist
std::list<std::pair<int, int>> *Adjs; // id, adj-list
//int dists[20001] = {DIST_INF, };
typedef std::pair<int, int> iPair;

void genProbSolver::process_input(istream &pin) {
    int V, E;
    pin >> V >> E;
    // id, dist
    Adjs = new std::list<std::pair<int, int>> [V+1];
    int start_node;
    pin >> start_node;
    int u, v, w;
    while(E--) {
        scanf("%d%d%d", &u, &v, &w);
        Adjs[u].push_back({v, w});
    }
    /*for (size_t i = 1; i <= V; i++) {
        std::cout << i <<"th node's adj : ";
        for (auto &p : Adjs[i]) {
            std::cout << "(" << p.first << "," << p.second << "), ";
        }
        std::cout << std::endl;
    }*/
    std::vector<int> dists(V+1, DIST_INF);
    // weight, id
    std::priority_queue<iPair, std::vector<iPair>, std::greater<iPair>> pq;
    pq.push(std::make_pair(0, start_node));
    dists[start_node] = 0;
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto &p : Adjs[u]) {
            int v = p.first;
            int weight = p.second;
            if(dists[v] > dists[u] + weight) {
                dists[v] = dists[u] + weight;
                pq.push({dists[v], v});
            }
        }
    }
    for (int i = 1; i <= V; i++) {
        if (dists[i] == DIST_INF) printf("INF\n");
        else if (i == start_node) printf("0\n"); 
        else printf("%d\n", dists[i]);
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


