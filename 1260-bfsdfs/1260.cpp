// input, output 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
// container
#include <vector>
#include <array>
#include <string>
#include <list>
#include <map>
#include <set>
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
#include <climits>
using namespace std;

#define GRAPH_COLOR_WHITE 0x01
#define GRAPH_COLOR_GRAY  0x02
#define GRAPH_COLOR_BLACK 0x03
#define GRAPH_DIST_INF INT_MAX

#define GRAPH_EDGE_WEIGHT_DEFAULT 1
struct gNode {
    // Followed node property of CLRS convention
    // Basic property
    int color;
    int dist;
    gNode* phi;
    // Depth first search property
    int fin; // finish time
    // Node Identifier by number or string name
    int id;
    std::string name;
    // Set of pointer of adjacent nodes
    std::set<int> adj_nodes;
    gNode() = default;
    gNode(int node_id)
        : id(node_id), color(GRAPH_COLOR_WHITE),
          dist(GRAPH_DIST_INF), phi(nullptr), name("") {}
};
struct gEdge {
    gNode *src;
    gNode *dst;
    int weight;
    pair<int, int> endpoint;
    gEdge() = default;
    gEdge(gNode *s, gNode *d, int w) 
        : src(s), dst(d), weight(w) {}
    gEdge(gNode *s, gNode *d)
        : src(s), dst(d), weight(GRAPH_EDGE_WEIGHT_DEFAULT) {}
};
class AdjacentListGraph {
    public:
        AdjacentListGraph() = default;
        AdjacentListGraph(bool dir) 
            : directed(dir) {
        }
        ~AdjacentListGraph() {}
        inline void insert_node(int id);
        inline void insert_edge(int src, int dst);
        inline void insert_edge(int src, int dst, int weight);
        inline void insert_node(gNode node);
        inline void insert_edge(gNode src, gNode dst);
        inline void insert_edge(gEdge edge);

        gNode& get_node(int id);
        void init_all_nodes_property();
        void breadth_first_search(int sid, std::function<void(vector<gNode *>&)> visit_actor);
        void depth_first_search(int sid, std::function<void(vector<gNode *>&)> visit_actor);
        inline bool is_already(int id);
        void print(ostream &pout);
    private:
        std::map<int, gNode> id_node_map;
        std::map<int, set<int>> id_adj_map;
        // edge can be replicated ex) multi graph
        std::vector<gEdge> edge_set;
        bool directed;
};

void AdjacentListGraph::depth_first_search(int sid,
        std::function<void(vector<gNode *> &)> visit_actor = nullptr ) {
    init_all_nodes_property();
    int depth = 0;
    std::stack<gNode *> ds;
    gNode &sNode = get_node(sid);
    ds.push(&sNode);
    sNode.dist = depth;
    sNode.color = GRAPH_COLOR_GRAY;
    while(!ds.empty()) {
        gNode *u = ds.top();
        ds.pop();
        if(u->color == GRAPH_COLOR_BLACK) {
            continue;
        } 
        cout << u->id << " ";
        u->color = GRAPH_COLOR_BLACK;
        for (auto i = id_adj_map[u->id].rbegin(); i != id_adj_map[u->id].rend(); ++i) {
            gNode &vNode = get_node(*i);
            if (vNode.color == GRAPH_COLOR_WHITE ||
                    vNode.color == GRAPH_COLOR_GRAY) {
                vNode.phi = u;
                vNode.color = GRAPH_COLOR_GRAY;
                ds.push(&vNode);
            }
        }   
        //depth++;

    }


}
void visit_action(vector<gNode *> visit_order) {
    for (auto p : visit_order) {
        cout << p->id << " ";
    }
    /*std::cout << std::endl;
    std::cout << "Breadth First Search from Node id:"
        << visit_actor[0]->id << std::endl;
    int curr_depth = visit_actor[0]->dist;
    int prev_depth = -1;
    for (auto p : visit_actor) {
        cout << p->id << "-";
        curr_depth = p->dist;
        if (curr_depth != prev_depth) {
            std::cout << std::endl;
            prev_depth = curr_depth;
        }
    }
    std::cout << std::endl;
    std::cout << "END" << std::endl;*/

}
int main(void)
{
    AdjacentListGraph graph1(false);
    //ifstream pin("./input-data/edge1.in");
    int N, M, V;
    cin >> N >> M >> V;
    int e1, e2;
    while (cin >> e1 >> e2) {
        graph1.insert_edge(e1, e2);
    }
    //graph1.print(cout);
    graph1.depth_first_search(V, visit_action);
    std::cout << std::endl;
    graph1.breadth_first_search(V, visit_action);
    return 0;
}
void AdjacentListGraph::init_all_nodes_property() {
    for (auto &p : id_node_map) {
        p.second.color = GRAPH_COLOR_WHITE; 
        p.second.dist = GRAPH_DIST_INF;
        p.second.phi = nullptr;
        p.second.fin = 0;
    }
}
void AdjacentListGraph::breadth_first_search(int sid, std::function<void(vector<gNode *> &)> visit_actor = nullptr) {
    init_all_nodes_property();
    gNode &sNode = get_node(sid);
    sNode.color = GRAPH_COLOR_GRAY;
    sNode.dist = GRAPH_DIST_INF;
    sNode.phi = nullptr;
    queue<gNode *> bq;
    bq.push(&sNode);
    vector<gNode *> visit_order;
    while(!bq.empty()) {
        gNode *uNode = bq.front();
        bq.pop();
        visit_order.push_back(uNode);
        for (auto p : id_adj_map[uNode->id]) {
            gNode &vNode = get_node(p);
            if (vNode.color == GRAPH_COLOR_WHITE) {
                vNode.color = GRAPH_COLOR_GRAY;
                vNode.dist = uNode->dist + 1;
                vNode.phi = &get_node(uNode->id);
                bq.push(&vNode); // copy by value
            }
        }
        uNode->color = GRAPH_COLOR_BLACK;
    }
    visit_actor(visit_order);
}
inline bool AdjacentListGraph::is_already(int id) {
    if(id_node_map.find(id)
            != id_node_map.end()) return true;
    else return false;
}
inline void AdjacentListGraph::insert_node(int id) {
    if (!is_already(id)) {
        id_node_map.insert(make_pair(id, gNode(id)));
    }
}
gNode& AdjacentListGraph::get_node(int id) {
    return id_node_map[id];
}
// when grpah input is given as pair of number
void AdjacentListGraph::insert_edge(int src, int dst) {
    if (!is_already(src)) {
        insert_node(src);
    }
    if (!is_already(dst)) {
        insert_node(dst);
    }
    id_adj_map[src].insert(dst);
    if (!directed) {
        id_adj_map[dst].insert(src);
    }
    gNode &sNode = get_node(src);
    gNode &dNode = get_node(dst);
    edge_set.emplace_back(&sNode, &dNode);
}

void AdjacentListGraph::print(ostream &pout) {
    if(directed) pout << "Direct graph";
    else pout << "Indirect graph with" << endl;
    pout << "(|V| = " << id_adj_map.size() << ", |E| = ";
    pout << edge_set.size() << ")" << std::endl;
    for (auto p : edge_set) {
        cout << p.src->id << " " << p.dst->id << endl;
    }
    std::cout << std::endl;
    pout << "id\t" << "adj list" << endl; 
    for (const auto p : id_adj_map) {
        pout << right << p.first << "\t-> ";
        for (const auto q : p.second) {
            pout << q << " ";
        }
        pout << std::endl;
    }
}
