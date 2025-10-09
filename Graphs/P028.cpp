#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bruteForce(int n, vector<vector<int>> &adj, int src)
{
    vector<int> dist(n, -1);
    // repeated BFS from src but naive visit management
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
    return dist;
}

vector<int> optimal(int n, vector<vector<int>> &adj, int src)
{
    return bruteForce(n, adj, src); // same for unweighted BFS
}

int main()
{
    int n, m;
    if (!(cin >> n >> m))
        return 0;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;
    cin >> src;
    auto b = bruteForce(n, adj, src);
    for (int i = 0; i < n; i++)
        cout << b[i] << (i + 1 == n ? "\n" : " ");
    auto o = optimal(n, adj, src);
    for (int i = 0; i < n; i++)
        cout << o[i] << (i + 1 == n ? "\n" : " ");
    return 0;
}
