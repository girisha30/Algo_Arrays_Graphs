#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n), r(n, 0) {
        for (int i = 0; i < n; ++i) p[i] = i;
    }
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]); // path compression (recursive but shallow)
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) ++r[a];
        return true;
    }
};

int bruteForce(int V, vector<Edge> &edges)
{
    // Use Kruskal (serves as brute placeholder here)
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });
    DSU d(V);
    long long total = 0;
    int cnt = 0;
    for (auto &e : edges) {
        if (d.unite(e.u, e.v)) {
            total += e.w;
            ++cnt;
        }
    }
    if (cnt != V - 1) return -1;
    return (int)total;
}

int optimal(int V, vector<Edge> &edges)
{
    // Kruskal is optimal here too
    return bruteForce(V, edges);
}

int main()
{
    int V, E;
    if (!(cin >> V >> E)) return 0;
    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
    cout << bruteForce(V, edges) << "\n";
    cout << optimal(V, edges) << "\n";
    return 0;
}
