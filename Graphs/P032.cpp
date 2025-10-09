#include <iostream>
#include <vector>
#include <stack>
#include <functional>
#include <algorithm>
using namespace std;

int bruteForce(int V, vector<vector<int>> &adj)
{
    vector<vector<int>> reach(V, vector<int>(V, 0));
    for (int i = 0; i < V; i++)
    {
        vector<int> vis(V, 0);
        vector<int> st;
        st.push_back(i);
        vis[i] = 1;
        for (size_t k = 0; k < st.size(); k++)
        {
            int u = st[k];
            for (int v : adj[u])
                if (!vis[v])
                {
                    vis[v] = 1;
                    st.push_back(v);
                }
        }
        for (int j = 0; j < V; j++)
            if (vis[j])
                reach[i][j] = 1;
    }

    vector<int> comp(V, -1);
    int cid = 0;
    for (int i = 0; i < V; i++)
        if (comp[i] == -1)
        {
            comp[i] = cid;
            for (int j = i + 1; j < V; j++)
                if (reach[i][j] && reach[j][i])
                    comp[j] = cid;
            cid++;
        }
    return cid;
}

int optimal(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V, 0);
    stack<int> st;

    // declare first
    function<void(int)> dfs1;
    dfs1 = [&](int u) {
        vis[u] = 1;
        for (int v : adj[u])
            if (!vis[v])
                dfs1(v);
        st.push(u);
    };

    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs1(i);

    vector<vector<int>> radj(V);
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            radj[v].push_back(u);

    fill(vis.begin(), vis.end(), 0);
    int scc = 0;

    function<void(int)> dfs2;
    dfs2 = [&](int u) {
        vis[u] = 1;
        for (int v : radj[u])
            if (!vis[v])
                dfs2(v);
    };

    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (!vis[u])
        {
            dfs2(u);
            scc++;
        }
    }
    return scc;
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
    cout << bruteForce(V, adj) << "\n";
    cout << optimal(V, adj) << "\n";
    return 0;
}
