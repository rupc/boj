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
    int V, E;
    pin >> V >> E;
    // dist, id
    typedef std::pair<int, int> simpleNode;
    std::priority_queue<simpleNode,
                        std::vector<simpleNode>,
                        greater<simpleNode>> PQ;
    list<simpleNode> *Adjs;
    Adjs = new list<simpleNode> [V+1];
    int u,v,w;
    while(E--) {
        pin >> u >> v >> w;
        Adjs[u].push_back({w,v});
    }
    int src, dst;
    pin >> src >> dst;
    #define INF 999999999
    std::vector<int> dist(V+1, INF);

    PQ.push({0, src});
    dist[src] = 0;

    while(!PQ.empty()) {
        int u = PQ.top().second;
        PQ.pop();
        for (auto &p : Adjs[u]) {
            int v = p.second;
            int weight = p.first;
            if(dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                PQ.push({dist[v], v});
            }
        }
    }
    /*for (const auto &p : dist) {
        std::cout << p << std::endl;
    }*/
    std::cout << dist[dst];
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


