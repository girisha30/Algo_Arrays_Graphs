#include <iostream>
#include <vector>
#include <functional> // required for std::function
using namespace std;

int bruteForce(int N, vector<pair<int, int>> &prereq)
{
    // detect cycle using adjacency matrix DFS
    vector<vector<int>> adj(N, vector<int>(N, 0));
    for (auto &p : prereq)
        adj[p.first][p.second] = 1;
    vector<int> vis(N, 0), rec(N, 0);

    function<int(int)> dfs; // declare first for recursion
    dfs = [&](int u) -> int
    {
        vis[u] = 1;
        rec[u] = 1;
        for (int v = 0; v < N; v++) {
            if (adj[u][v]) {
                if (!vis[v]) {
                    if (dfs(v)) {
                        return 1;
                    }
                } else if (rec[v]) {
                    return 1;
                }
            }
        }
        rec[u] = 0;
        return 0;
    };

    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            if (dfs(i)) {
                return 0; // cycle found -> cannot finish
            }
        }
    }
    return 1; // no cycle -> can finish
}

int optimal(int N, vector<pair<int, int>> &prereq)
{
    vector<vector<int>> adj(N);
    vector<int> indeg(N, 0);
    for (auto &p : prereq)
    {
        adj[p.first].push_back(p.second);
        indeg[p.second]++;
    }
    int cnt = 0;
    vector<int> q;
    for (int i = 0; i < N; i++)
        if (indeg[i] == 0)
            q.push_back(i);
    for (size_t i = 0; i < q.size(); i++)
    {
        int u = q[i];
        cnt++;
        for (int v : adj[u])
            if (--indeg[v] == 0)
                q.push_back(v);
    }
    return cnt == N ? 1 : 0;
}

int main()
{
    int N, P;
    if (!(cin >> N >> P))
        return 0;
    vector<pair<int, int>> prereq(P);
    for (int i = 0; i < P; i++)
        cin >> prereq[i].first >> prereq[i].second;
    cout << bruteForce(N, prereq) << "\n";
    cout << optimal(N, prereq) << "\n";
    return 0;
}
