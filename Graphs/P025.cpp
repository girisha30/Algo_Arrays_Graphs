#include <iostream>
#include <vector>
using namespace std;

vector<int> bruteForce(int N, vector<pair<int, int>> &edges)
{
    // naive Kahn recompute indeg
    vector<int> used(N, 0), res;
    for (int k = 0; k < N; k++)
    {
        int found = -1;
        for (int i = 0; i < N; i++)
            if (!used[i])
            {
                int indeg = 0;
                for (auto &e : edges)
                    if (e.second == i && !used[e.first])
                        indeg++;
                if (indeg == 0)
                {
                    found = i;
                    break;
                }
            }
        if (found == -1)
            return vector<int>();
        used[found] = 1;
        res.push_back(found);
    }
    return res;
}

vector<int> optimal(int N, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(N);
    vector<int> indeg(N, 0);
    for (auto &e : edges)
    {
        adj[e.first].push_back(e.second);
        indeg[e.second]++;
    }
    vector<int> q;
    for (int i = 0; i < N; i++)
        if (indeg[i] == 0)
            q.push_back(i);
    for (size_t i = 0; i < q.size(); i++)
    {
        int u = q[i];
        for (int v : adj[u])
            if (--indeg[v] == 0)
                q.push_back(v);
    }
    if ((int)q.size() != N)
        return vector<int>();
    return q;
}

int main()
{
    int N, P;
    if (!(cin >> N >> P))
        return 0;
    vector<pair<int, int>> edges(P);
    for (int i = 0; i < P; i++)
        cin >> edges[i].first >> edges[i].second;
    auto b = bruteForce(N, edges);
    for (size_t i = 0; i < b.size(); i++)
        cout << b[i] << (i + 1 == b.size() ? "\n" : " ");
    auto o = optimal(N, edges);
    for (size_t i = 0; i < o.size(); i++)
        cout << o[i] << (i + 1 == o.size() ? "\n" : " ");
    return 0;
}
