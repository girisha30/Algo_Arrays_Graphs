#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int bruteForce(vector<pair<int, int>> stones)
{
    int n = stones.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (stones[i].first == stones[j].first || stones[i].second == stones[j].second)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    vector<int> vis(n, 0);
    int comps = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            comps++;
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
    return n - comps;
}

struct DSU
{
    unordered_map<int, int> p, r;
    int f(int x)
    {
        if (!p.count(x))
            p[x] = x;
        return p[x] == x ? x : p[x] = f(p[x]);
    }
    void u(int a, int b)
    {
        a = f(a);
        b = f(b);
        if (a == b)
            return;
        if (r[a] < r[b])
            swap(a, b);
        p[b] = a;
        if (r[a] == r[b])
            r[a]++;
    }
};
int optimal(vector<pair<int, int>> stones)
{
    DSU d;
    const int OFF = 100001;
    for (auto &s : stones)
    {
        d.u(s.first, s.second + OFF);
    }
    unordered_set<int> roots;
    for (auto &s : stones)
    {
        roots.insert(d.f(s.first));
        roots.insert(d.f(s.second + OFF));
    }
    int comps = roots.size();
    return (int)stones.size() - comps;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> stones(n);
    for (int i = 0; i < n; i++)
        cin >> stones[i].first >> stones[i].second;
    cout << bruteForce(stones) << "\n";
    cout << optimal(stones) << "\n";
}
