#include <iostream>
#include <vector>
using namespace std;

int bruteForce(int n, const vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(n);
    for (auto &e : edges)
    {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }
    vector<int> vis(n, 0);
    int comps = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            comps++;
            // DFS
            vector<int> st = {i};
            vis[i] = 1;
            while (!st.empty())
            {
                int u = st.back();
                st.pop_back();
                for (int v : adj[u])
                    if (!vis[v])
                    {
                        vis[v] = 1;
                        st.push_back(v);
                    }
            }
        }
    }
    int extra = (int)edges.size() - (n - comps);
    if (extra >= comps - 1)
        return comps - 1;
    return -1;
}

struct DSU
{
    vector<int> p, r;
    DSU(int n)
    {
        p.resize(n);
        r.assign(n, 0);
        for (int i = 0; i < n; i++)
            p[i] = i;
    }
    int f(int x) { return p[x] == x ? x : p[x] = f(p[x]); }
    bool u(int a, int b)
    {
        a = f(a);
        b = f(b);
        if (a == b)
            return false;
        if (r[a] < r[b])
            swap(a, b);
        p[b] = a;
        if (r[a] == r[b])
            r[a]++;
        return true;
    }
};
int optimal(int n, const vector<pair<int, int>> &edges)
{
    DSU d(n);
    int extra = 0;
    for (auto &e : edges)
        if (!d.u(e.first, e.second))
            extra++;
    int comps = 0;
    for (int i = 0; i < n; i++)
        if (d.f(i) == i)
            comps++;
    if (extra >= comps - 1)
        return comps - 1;
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }
    cout << bruteForce(n, edges) << "\n";
    cout << optimal(n, edges) << "\n";
}
