#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

struct Edge
{
    int u, v, w;
};

vector<int> bruteForce(int V, const vector<Edge> &edges, int src, int dest)
{
    const long long INF = 1LL << 60;
    vector<long long> dist(V, INF);
    vector<int> par(V, -1);
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto &e : edges)
        {
            if (dist[e.u] < INF && dist[e.u] + e.w < dist[e.v])
            {
                dist[e.v] = dist[e.u] + e.w;
                par[e.v] = e.u;
            }
        }
    }
    if (dist[dest] == INF)
        return vector<int>();
    vector<int> path;
    for (int v = dest; v != -1; v = par[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

vector<int> optimal(int V, const vector<Edge> &edges, int src, int dest)
{
    return bruteForce(V, edges, src, dest);
}

int main()
{
    int V, E;
    if (!(cin >> V >> E))
        return 0;
    vector<Edge> edges(E);
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    int src;
    cin >> src;
    int dest;
    cin >> dest;
    auto b = bruteForce(V, edges, src, dest);
    for (size_t i = 0; i < b.size(); i++)
        cout << b[i] << (i + 1 == b.size() ? "\n" : " ");
    auto o = optimal(V, edges, src, dest);
    for (size_t i = 0; i < o.size(); i++)
        cout << o[i] << (i + 1 == o.size() ? "\n" : " ");
    return 0;
}
