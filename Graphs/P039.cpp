#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int u, v, w;
};

int bruteForce(int V, vector<Edge> &edges)
{
    const long long INF = 1LL << 60;
    vector<long long> dist(V, 0);
    for (int i = 0; i < V - 1; i++)
        for (auto &e : edges)
            if (dist[e.u] + e.w < dist[e.v])
                dist[e.v] = dist[e.u] + e.w;
    for (auto &e : edges)
        if (dist[e.u] + e.w < dist[e.v])
            return 1;
    return 0;
}
int optimal(int V, vector<Edge> &edges) { return bruteForce(V, edges); }
int main()
{
    int V, E;
    if (!(cin >> V >> E))
        return 0;
    vector<Edge> edges(E);
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    cout << bruteForce(V, edges) << "\n";
    cout << optimal(V, edges) << "\n";
    return 0;
}
