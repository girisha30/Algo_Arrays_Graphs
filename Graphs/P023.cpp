#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bruteForce(int V, vector<vector<int>> &adj)
{
    // naive Kahn using recompute indeg each time (O(V^2))
    vector<int> res;
    vector<int> used(V, 0);
    for (int k = 0; k < V; k++)
    {
        int found = -1;
        for (int i = 0; i < V; i++)
            if (!used[i])
            {
                int indeg = 0;
                for (int u = 0; u < V; u++)
                    for (int v : adj[u])
                        if (v == i && !used[u])
                            indeg++;
                if (indeg == 0)
                {
                    found = i;
                    break;
                }
            }
        if (found == -1)
            break;
        used[found] = 1;
        res.push_back(found);
    }
    return res;
}

vector<int> optimal(int V, vector<vector<int>> &adj)
{
    vector<int> indeg(V, 0);
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            indeg[v]++;
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indeg[i] == 0)
            q.push(i);
    vector<int> res;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for (int v : adj[u])
            if (--indeg[v] == 0)
                q.push(v);
    }
    return res;
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
    auto b = bruteForce(V, adj);
    for (size_t i = 0; i < b.size(); i++)
        cout << b[i] << (i + 1 == b.size() ? "\n" : " ");
    auto o = optimal(V, adj);
    for (size_t i = 0; i < o.size(); i++)
        cout << o[i] << (i + 1 == o.size() ? "\n" : " ");
    return 0;
}
