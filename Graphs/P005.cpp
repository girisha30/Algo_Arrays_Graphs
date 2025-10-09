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
    vector<int> color(V, -1);
    for (int s = 0; s < V; s++)
    {
        if (color[s] != -1)
            continue;
        queue<int> q;
        q.push(s);
        color[s] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v = 0; v < V; v++)
            {
                if (mat[u][v])
                {
                    if (color[v] == -1)
                    {
                        color[v] = color[u] ^ 1;
                        q.push(v);
                    }
                    else if (color[v] == color[u])
                        return 0;
                }
            }
        }
    }
    return 1;
}
bool dfs(int u, int c, vector<int> &col, vector<vector<int>> &adj)
{
    col[u] = c;
    for (int v : adj[u])
    {
        if (col[v] == -1)
        {
            if (!dfs(v, c ^ 1, col, adj))
                return false;
        }
        else if (col[v] == c)
            return false;
    }
    return true;
}
int optimal(int V, vector<vector<int>> &adj)
{
    vector<int> col(V, -1);
    for (int i = 0; i < V; i++)
        if (col[i] == -1)
            if (!dfs(i, 0, col, adj))
                return 0;
    return 1;
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
