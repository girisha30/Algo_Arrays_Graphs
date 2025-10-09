#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bruteForce(vector<vector<int>> grid)
{
    int m = grid.size(), n = grid[0].size();
    int time = 0;
    bool changed = true;
    while (changed)
    {
        changed = false;
        vector<vector<int>> next = grid;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    if (i > 0 && grid[i - 1][j] == 1)
                    {
                        next[i - 1][j] = 2;
                        changed = true;
                    }
                    if (i < m - 1 && grid[i + 1][j] == 1)
                    {
                        next[i + 1][j] = 2;
                        changed = true;
                    }
                    if (j > 0 && grid[i][j - 1] == 1)
                    {
                        next[i][j - 1] = 2;
                        changed = true;
                    }
                    if (j < n - 1 && grid[i][j + 1] == 1)
                    {
                        next[i][j + 1] = 2;
                        changed = true;
                    }
                }
            }
        if (changed)
        {
            time++;
            grid.swap(next);
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1)
                return -1;
    return time;
}

int optimal(vector<vector<int>> grid)
{
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;
    int fresh = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
                q.push({i * n + j, 0});
            if (grid[i][j] == 1)
                fresh++;
        }
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int minutes = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int pos = cur.first, t = cur.second;
        int r = pos / n, c = pos % n;
        minutes = t;
        for (auto &d : dirs)
        {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1)
            {
                grid[nr][nc] = 2;
                fresh--;
                q.push({nr * n + nc, t + 1});
            }
        }
    }
    return fresh ? -1 : minutes;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> g(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    cout << bruteForce(g) << "\n";
    cout << optimal(g) << "\n";
}
