#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bruteForce(vector<vector<int>> g)
{
    int n = g.size(), m = g[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 1)
            {
                // check if component touches border via full BFS
                vector<vector<int>> vis(n, vector<int>(m, 0));
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;
                bool touch = false;
                int cells = 0;
                int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                while (!q.empty())
                {
                    auto p = q.front();
                    q.pop();
                    cells++;
                    int r = p.first, c = p.second;
                    if (r == 0 || r == n - 1 || c == 0 || c == m - 1)
                        touch = true;
                    for (auto &d : dirs)
                    {
                        int nr = r + d[0], nc = c + d[1];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && g[nr][nc] == 1)
                        {
                            vis[nr][nc] = 1;
                            q.push({nr, nc});
                        }
                    }
                }
                if (!touch)
                    cnt += cells;
            }
    return cnt;
}

int optimal(vector<vector<int>> g)
{
    int n = g.size(), m = g[0].size();
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        if (g[i][0] == 1)
        {
            q.push({i, 0});
            g[i][0] = 0;
        }
        if (g[i][m - 1] == 1)
        {
            q.push({i, m - 1});
            g[i][m - 1] = 0;
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (g[0][j] == 1)
        {
            q.push({0, j});
            g[0][j] = 0;
        }
        if (g[n - 1][j] == 1)
        {
            q.push({n - 1, j});
            g[n - 1][j] = 0;
        }
    }
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        for (auto &d : dirs)
        {
            int nr = p.first + d[0], nc = p.second + d[1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] == 1)
            {
                g[nr][nc] = 0;
                q.push({nr, nc});
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 1)
                cnt++;
    return cnt;
}

int main()
{
    int n, m;
    if (!(cin >> n >> m))
        return 0;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    cout << bruteForce(g) << "\n";
    cout << optimal(g) << "\n";
    return 0;
}
