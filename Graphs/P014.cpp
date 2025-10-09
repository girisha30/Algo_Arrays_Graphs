#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bruteForce(int V, vector<vector<int>> &adj)
{
    vector<vector<int>> mat(V, vector<int>(V, 0));
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            mat[u][v] = 1;
    vector<int> vis(V, 0);
    for (int s = 0; s < V; s++)
    {
        if (vis[s])
            continue;
        queue<pair<int, int>> q;
        q.push({s, -1});
        vis[s] = 1;
        while (!q.empty())
        {
            int u = q.front().first, p = q.front().second;
            q.pop();
            for (int v = 0; v < V; v++)
            {
                if (mat[u][v])
                {
                    if (!vis[v])
                    {
                        vis[v] = 1;
                        q.push({v, u});
                    }
                    else if (v != p)
                        return 1;
                }
            }
        }
    }
    return 0;
}
int optimal(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V, 0);
    for (int s = 0; s < V; s++)
    {
        if (vis[s])
            continue;
        queue<pair<int, int>> q;
        q.push({s, -1});
        vis[s] = 1;
        while (!q.empty())
        {
            int u = q.front().first, p = q.front().second;
            q.pop();
            for (int v : adj[u])
            {
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push({v, u});
                }
                else if (v != p)
                    return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << bruteForce(V, adj) << "\n";
    cout << optimal(V, adj) << "\n";
}
