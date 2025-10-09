#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void topoDfs(int u, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
{
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v])
            topoDfs(v, adj, vis, st);
    st.push(u);
}

vector<int> bruteForce(int V, vector<vector<int>> &adj, int src)
{
    const int INF = 1e9;
    vector<int> dist(V, INF);
    dist[src] = 0;
    for (int i = 0; i < V; i++)
    {
        for (int u = 0; u < V; u++)
            for (int v : adj[u])
                if (dist[u] < INF && dist[v] > dist[u] + 1)
                    dist[v] = dist[u] + 1;
    }
    for (int i = 0; i < V; i++)
        if (dist[i] == INF)
            dist[i] = -1;
    return dist;
}

vector<int> optimal(int V, vector<vector<int>> &adj, int src)
{
    stack<int> st;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
        if (!vis[i])
            topoDfs(i, adj, vis, st);
    const int INF = 1e9;
    vector<int> dist(V, INF);
    dist[src] = 0;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (dist[u] < INF)
            for (int v : adj[u])
                if (dist[v] > dist[u] + 1)
                    dist[v] = dist[u] + 1;
    }
    for (int i = 0; i < V; i++)
        if (dist[i] == INF)
            dist[i] = -1;
    return dist;
}

int main()
{
    int V, E;
    if (!(cin >> V >> E))
        return 0;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int src;
    cin >> src;
    auto b = bruteForce(V, adj, src);
    for (int i = 0; i < V; i++)
        cout << b[i] << (i + 1 == V ? "\n" : " ");
    auto o = optimal(V, adj, src);
    for (int i = 0; i < V; i++)
        cout << o[i] << (i + 1 == V ? "\n" : " ");
    return 0;
}
