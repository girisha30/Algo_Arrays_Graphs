#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<vector<int>> bruteForce(const vector<vector<int>> &g)
{
    int m = g.size(), n = g[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == 1)
            {
                dist[i][j] = 0;
                continue;
            }
            for (int x = 0; x < m; x++)
                for (int y = 0; y < n; y++)
                    if (g[x][y] == 1)
                        dist[i][j] = min(dist[i][j], abs(x - i) + abs(y - j));
        }
    return dist;
}

vector<vector<int>> optimal(const vector<vector<int>> &g)
{
    int m = g.size(), n = g[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (g[i][j] == 1)
            {
                dist[i][j] = 0;
                q.push({i * n + j, 0});
            }
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int pos = cur.first, t = cur.second;
        int r = pos / n, c = pos % n;
        for (auto &d : dirs)
        {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && dist[nr][nc] > t + 1)
            {
                dist[nr][nc] = t + 1;
                q.push({nr * n + nc, t + 1});
            }
        }
    }
    return dist;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> g(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    auto b = bruteForce(g), o = optimal(g);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << b[i][j] << " ";
        cout << "\n";
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << o[i][j] << " ";
        cout << "\n";
    }
}
