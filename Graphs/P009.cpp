#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const long long MOD = 1000000007LL;

long long bruteForce(int n, vector<vector<pair<int, int>>> &adj)
{
    const long long INF = (1LL << 60);
    vector<long long> dist(n, INF), ways(n, 0);
    vector<int> used(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    for (int it = 0; it < n; it++)
    {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!used[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        if (u == -1 || dist[u] >= INF / 2)
            break;
        used[u] = 1;
        for (auto &e : adj[u])
        {
            int v = e.first, w = e.second;
            long long nd = dist[u] + w;
            if (nd < dist[v])
            {
                dist[v] = nd;
                ways[v] = ways[u];
            }
            else if (nd == dist[v])
            {
                ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
    }
    return ways[n - 1] % MOD;
}

long long optimal(int n, vector<vector<pair<int, int>>> &adj)
{
    const long long INF = (1LL << 60);
    vector<long long> dist(n, INF), ways(n, 0);
    using T = pair<long long, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        long long d = cur.first;
        int u = cur.second;
        if (d != dist[u])
            continue;
        for (auto &e : adj[u])
        {
            int v = e.first, w = e.second;
            long long nd = d + w;
            if (nd < dist[v])
            {
                dist[v] = nd;
                ways[v] = ways[u];
                pq.push({nd, v});
            }
            else if (nd == dist[v])
            {
                ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
    }
    return ways[n - 1] % MOD;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << bruteForce(n, adj) << "\n";
    cout << optimal(n, adj) << "\n";
}
