#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int u, v, w;
};

vector<long long> bruteForce(int V, vector<Edge> &edges, int src)
{
    const long long INF = 1LL << 60;
    vector<long long> dist(V, INF);
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto &e : edges)
            if (dist[e.u] < INF && dist[e.u] + e.w < dist[e.v])
                dist[e.v] = dist[e.u] + e.w;
    }
    return dist;
}

vector<long long> optimal(int V, vector<Edge> &edges, int src)
{
    return bruteForce(V, edges, src);
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
    auto b = bruteForce(V, edges, src);
    auto o = optimal(V, edges, src);
    for (int i = 0; i < V; i++)
        cout << (b[i] >= (1LL << 50) ? -1 : b[i]) << (i + 1 == V ? "\n" : " ");
    for (int i = 0; i < V; i++)
        cout << (o[i] >= (1LL << 50) ? -1 : o[i]) << (i + 1 == V ? "\n" : " ");
    return 0;
}
