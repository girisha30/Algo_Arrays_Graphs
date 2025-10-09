#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bruteForce(int V, vector<vector<int>> &adj)
{
    vector<vector<int>> mat(V, vector<int>(V, 0));
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            mat[u][v] = 1;
    vector<int> vis(V, 0);
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            count++;
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v = 0; v < V; v++)
                    if (mat[u][v] && !vis[v])
                    {
                        vis[v] = 1;
                        q.push(v);
                    }
            }
        }
    }
    cout << count << "\n";
}

void dfs(int u, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v])
            dfs(v, adj, vis);
}
void optimal(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V, 0);
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            count++;
            dfs(i, adj, vis);
        }
    }
    cout << count << "\n";
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
    bruteForce(V, adj);
    optimal(V, adj);
}
