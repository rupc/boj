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

#define COLOR_WHITE 0x01 // for unexplored node
#define COLOR_GRAY  0x02 // for exploring node.
#define COLOR_BLACK 0x03 // for explored node
#define DIST_INF INT_MAX

#define EDGE_WEIGHT_DEFAULT 1
string input_file("input-data/mat2.in");
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
        : id(node_id), color(COLOR_WHITE),
          dist(DIST_INF), phi(nullptr), name("") {}
};
struct gEdge {
    gNode *src;
    gNode *dst;
    int weight;
    gEdge() = default;
    gEdge(gNode *s, gNode *d, int w) 
        : src(s), dst(d), weight(w) {}
    gEdge(gNode *s, gNode *d)
        : src(s), dst(d), weight(EDGE_WEIGHT_DEFAULT) {}
};
bool act_on_node(gNode * v);
typedef std::vector<int> iVO; // id visit order
typedef std::vector<gNode *> VisitOrder;    // return type of bfs, dfs
typedef std::function<bool(int)> iActor;
typedef std::function<bool(gNode *)> eActor; // action on each node
typedef std::vector<vector<int>> Matrix;
class AdjGraph {
    public:
        AdjGraph() = default;
        AdjGraph(bool dir) 
            : directed(dir) {
        }
        AdjGraph(Matrix mat);
        ~AdjGraph() {}
        // initialize internal data structures
        void init_all_nodes_property();
        void init_as_mat(std::vector<vector<int>> mat);
        inline void insert_node(int id);
        inline gEdge& insert_edge(int src, int dst);
        inline void insert_edge(int src, int dst, int weight);
        inline void insert_node(gNode node);
        inline void insert_edge(gNode src, gNode dst);
        inline void insert_edge(gEdge edge);

        gNode* get_node(int id);
        VisitOrder breadth_first_search(int sid, eActor act_on_node);
        VisitOrder depth_first_search(int sid, eActor act_on_node);
        vector<int> dfs_v2(int src, int dst);
        // test if path from srcc to dst exsit
        Matrix check_all_path_to();
        bool check_path_to(int src, int dst);
        inline bool mcheck_path_to(int src, int dst);
        Matrix mcheck_reachable(Matrix *mat);
        bool check_cycle(int src); // check cycle from src to src
        bool check_cycle();
        inline bool is_already(int id);
        void print(ostream &pout);
        void mprint(ostream &pout);
    private:
        std::map<int, gNode> id_node_map;
        std::map<int, set<int>> id_adj_map;
        // edge can be replicated ex) multi graph
        std::vector<gEdge> edge_set;
        Matrix adj_mat;
        bool directed;
};
Matrix AdjGraph::check_all_path_to() {
    const size_t sz = adj_mat.size();
    Matrix res(sz, vector<int>(sz));
    std::stack<int> ds;
    std::vector<bool> visited(sz, false);
    for (size_t i = 0; i < sz; i++) {
        ds.push(i);
        while (!ds.empty()) {
            int u = ds.top(); ds.pop();
            if(!visited[u]) {
                visited[u] = true;
                for (size_t j = 0; j < sz; j++) {
                    if (adj_mat[u][j] != 0) res[i][j] = 1 ;
                    if (!visited[j] && adj_mat[u][j] != 0) {
                        ds.push(j);
                        //cout << j+1 << " ";
                    }
                }
            }
        }
        std::fill(visited.begin(), visited.end(), false);
    }
    return res;
}
inline bool AdjGraph::mcheck_path_to(int src, int dst) {
    /*auto actor = [&](int curr) -> bool {
        if(curr == dst) return true;
        else return false;
    };*/
    iVO vo = dfs_v2(src, dst);
    /*if(src == 0 && dst == 0) {
        std::cout << std::endl;
        for (size_t i = 0; i < vo.size(); i++) {
            cout << vo[i] + 1 << " ";
        }
        std::cout << std::endl;
    }*/
    if(vo.back() == dst) {
        return true;
    } else return false;
}

inline std::vector<int> AdjGraph::dfs_v2(int src, int dst) {
    const size_t sz = adj_mat.size();
    std::vector<bool> visited(sz, false);
    std::stack<int> ds;
    std::vector<int> VO;
    ds.push(src);
    while(!ds.empty()) {
        int u = ds.top();
        ds.pop();
        VO.push_back(u);
        if(!visited[u]) {
            visited[u] = true;
            for (size_t i = 0; i < sz; i++) {
                if(adj_mat[u][i] != 0) {
                    if(i == dst) {
                        VO.push_back(i);
                        return VO;
                    }
                }
                if(!visited[i] && adj_mat[u][i]) {
                    ds.push(i);
                    //cout << i+1 << " ";
                }
            }
        }
    }
    return VO;
}
Matrix mcheck_reachable(Matrix *mat=nullptr) {
}

inline bool AdjGraph::check_cycle(int src) {
    return check_path_to(src, src);
}
inline bool AdjGraph::check_path_to(int src, int dst) {
    auto actor = [&](gNode *v) -> bool {
        if(v->id == dst) return true;
        else return false;
    };
    VisitOrder vO = depth_first_search(src, actor);
    if(vO.size() < 2) return false; // no comming out edge from src
    if(vO.back()->id == dst) {
        return true;
    } else return false;
}
int main(void)
{
    AdjGraph graph1(false);
    /*std::ifstream pin("./input-data/edge1.in");
    int e1, e2;
    while (pin >> e1 >> e2) {
        graph1.insert_edge(e1, e2);
    }*/
    int N;
    cin >> N;
    int t;
    Matrix adj_matrix(N, vector<int>(N));
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            cin >> t;
            adj_matrix[i][j] = t;
        }
    } 
    AdjGraph graph2(adj_matrix);
    //graph2.mprint(cout);
    Matrix res(graph2.check_all_path_to());
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            std::cout << res[i][j] << " ";
        }
        if(i != N-1) std::cout << std::endl;
    } 
    //graph2.init_as_mat(adj_matrix);
    //graph2.print(std::cout);
    int path_mat[N][N] = {0,};
    /*for (unsigned i = 0; i < N; ++i) {
        for (unsigned j = 0; j < N; ++j) {
            //path_mat[i][j] = graph2.mcheck_path_to(i, j);
            std::cout << graph2.mcheck_path_to(i, j);
        }
        if(i != N-1) std::cout << std::endl;
    } */
    /*Matrix res(graph2.check_all_path_to());
    for (unsigned i = 0; i < N; ++i) {
        for (unsigned j = 0; j < N; ++j) {
            cout << path_mat[i][j];
        }
        if(i != N - 1) std::cout << std::endl;
    } */
    //cout << graph2.check_path_to(3, 1) << endl;
    /*graph2.print(std::cout);
    graph2.breadth_first_search(1, act_on_node);
    graph2.depth_first_search(1, act_on_node);*/
    return 0;
}

void AdjGraph::init_as_mat(std::vector<vector<int>> adj_mat) {
    const unsigned N = adj_mat.size();
    for (unsigned i = 0; i < N; ++i) {
        for (unsigned j = 0; j < N; ++j) {
            if(i == 2) {
                insert_node(3);
            }
            if(adj_mat[i][j] != 0) {
                insert_edge(i+1, j+1, adj_mat[i][j]);
            }
        }
    } 
}
void AdjGraph::init_all_nodes_property() {
    for (auto &p : id_node_map) {
        p.second.color = COLOR_WHITE; 
        p.second.dist = DIST_INF;
        p.second.phi = nullptr;
        p.second.fin = 0;
    }
}
VisitOrder AdjGraph::depth_first_search(int sid,
        eActor act_on_node = nullptr ) {
    if(id_adj_map[sid].size() == 0) return VisitOrder();
    init_all_nodes_property();
    int depth = 0;
    size_t sz = id_adj_map.size();
    std::vector<bool> visited(sz, false);
    std::stack<gNode *> ds;
    gNode *s = get_node(sid);
    s->dist = depth;
    s->color = COLOR_GRAY;
    ds.push(s);
    VisitOrder vOrder;
    // Visiting smallest id as first is slightly poor performance
    // Because exploring node(i.e. root of forest) also can be pushed to stack
    while(!ds.empty()) {
        gNode *u = ds.top();
        ds.pop();
        // because it pushes every adjacent & grey node to visit the node with smallest id as first
        if(u->color == COLOR_BLACK) {
            continue;
        } 
        u->color = COLOR_BLACK;
        vOrder.push_back(u);
        depth++;
        for (auto p = id_adj_map[u->id].rbegin(); p != id_adj_map[u->id].rend(); ++p) {
            gNode *v = get_node(*p);
            // if target node is discovered, finish search
            if(act_on_node(v) == true)  {
                vOrder.push_back(v);
                return vOrder;
            }
            if (v->color != COLOR_BLACK) {
                v->phi = u;
                v->color = COLOR_GRAY;
                v->dist = depth;
                ds.push(v);
            }
        }   
    }
    return vOrder;
}
VisitOrder AdjGraph::breadth_first_search(int sid, eActor act_on_node = nullptr) {
    init_all_nodes_property();
    gNode *sNode = get_node(sid);
    sNode->color = COLOR_GRAY;
    sNode->dist = DIST_INF;
    sNode->phi = nullptr;
    queue<gNode *> bq;
    bq.push(sNode);
    VisitOrder vOrder;
    bool fir = true;
    while(!bq.empty()) {
        gNode *uNode = bq.front();
        bq.pop();
        vOrder.push_back(uNode);
        // if target node is discovered, finish search
        if(act_on_node(uNode) == true) {
            break;
        }
        for (auto p : id_adj_map[uNode->id]) {
            gNode *v = get_node(p);
            if (v->color == COLOR_WHITE) {
                v->color = COLOR_GRAY;
                v->dist = uNode->dist + 1;
                v->phi = get_node(uNode->id);
                bq.push(v); // copy by value
            }
        }
        uNode->color = COLOR_BLACK;
    }
    return vOrder;
}
inline bool AdjGraph::is_already(int id) {
    if(id_node_map.find(id)
            != id_node_map.end()) return true;
    else return false;
}
inline void AdjGraph::insert_node(int id) {
    if (!is_already(id)) {
        id_node_map.insert(make_pair(id, gNode(id)));
        //std::cout << id_node_map.size() << std::endl;
        //if(id == 3) std::cout << "3here" << std::endl;
    }
}
gNode* AdjGraph::get_node(int id) {
    return &id_node_map[id];
}
// when grpah input is given as pair of number
gEdge& AdjGraph::insert_edge(int src, int dst) {
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
    gNode *sNode = get_node(src);
    gNode *dNode = get_node(dst);
    edge_set.emplace_back(sNode, dNode);
    return edge_set[edge_set.size() - 1];
}

inline void AdjGraph::insert_edge(int src, int dst, int weight) {
    insert_edge(src, dst).weight = weight;
}
void AdjGraph::print(std::ostream &pout) {
    pout << "Graph Info\n";
    if(directed) pout << "Direct graph";
    else pout << "Indirect graph with";
    pout << " with (|V| = " << id_node_map.size() << ", |E| = ";
    pout << edge_set.size() << ")" << std::endl;

    std::cout << std::endl;
    pout << "id\t" << "adj list" << endl; 
    for (const auto p : id_node_map) {
        pout << right << p.first << "\t-> ";
        for (const auto q : id_adj_map[p.first]) {
            pout << q << " ";
        }
        pout << std::endl;
    }
}
void AdjGraph::mprint(std::ostream &pout) {
    for (size_t i = 0; i < adj_mat.size(); ++i) {
        for (size_t j = 0; j < adj_mat.size(); ++j) {
            std::cout << adj_mat[i][j];
        }
        std::cout << std::endl;
    } 
}
AdjGraph::AdjGraph(Matrix mat) {
    const size_t sz = mat.size();
    adj_mat.resize(sz);
    for (size_t i = 0; i < sz; i++) {
        adj_mat[i].resize(sz);
        for (size_t j = 0; j < sz; j++) {
            adj_mat[i][j] = mat[i][j];
        }
    }
}
bool act_on_node(gNode *v) {
    std::cout << v->id << " ";
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
