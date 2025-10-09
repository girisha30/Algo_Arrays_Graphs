#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> bruteForce(int V, vector<vector<int>> &mat)
{
    const int INF = 1e9;
    vector<vector<int>> dist = mat;
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    return dist;
}

vector<vector<int>> optimal(int V, vector<vector<int>> &mat)
{
    return bruteForce(V, mat);
}

int main()
{
    int V, E;
    if (!(cin >> V >> E))
        return 0;
    const int INF = 1e9;
    vector<vector<int>> mat(V, vector<int>(V, INF));
    for (int i = 0; i < V; i++)
        mat[i][i] = 0;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mat[u][v] = w;
    }
    auto b = bruteForce(V, mat);
    auto o = optimal(V, mat);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << (b[i][j] >= INF / 2 ? -1 : b[i][j]) << (j + 1 == V ? "\n" : " ");
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << (o[i][j] >= INF / 2 ? -1 : o[i][j]) << (j + 1 == V ? "\n" : " ");
    }
    return 0;
}
