#include <iostream>
#include <vector>

struct Vertex {
    int id;
    std::vector<int> adj;
};

struct Edge {
    int u, v, c;
    Edge() {}
    Edge(int u, int v, int c) : u(u), v(v), c(c) {}
};

struct Graph {
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    Graph(int vsize) : vertices(vsize) {
        for (int id = 0; id < vsize; id++) {
            vertices[id].id = id;
        }
    }

    void add_edge(int u, int v, int c) {
        vertices[u].adj.push_back(edges.size());
        edges.emplace_back(u, v, c);
    }
};

int main() {
    Graph G(10);
    G.add_edge(1, 2, 100);
    G.add_edge(2, 3, 200);
    G.add_edge(1, 5, 300);
    for (auto &vertex: G.vertices) {
        std::cout << vertex.id << ": ";
        for (auto &eid: vertex.adj) {
            auto &edge = G.edges[eid];
            std::cout << edge.v << " " << edge.c << ", ";
        }
        std::cout << "\n";
    }
    return 0;
}