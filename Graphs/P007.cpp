#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int bruteForce(vector<vector<int>> g, int sr, int sc, int dr, int dc)
{
    int n = g.size(), m = g[0].size();
    if (sr < 0 || sr >= n || sc < 0 || sc >= m || dr < 0 || dr >= n || dc < 0 || dc >= m || g[sr][sc] == 0 || g[dr][dc] == 0)
        return -1;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    // naive queue without visited optimization (still BFS but less tidy)
    queue<pair<int, int>> q;
    q.push({sr * m + sc, 0});
    dist[sr][sc] = 0;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int pos = cur.first, d = cur.second;
        int r = pos / m, c = pos % m;
        if (d > dist[r][c])
            continue;
        for (auto &x : dirs)
        {
            int nr = r + x[0], nc = c + x[1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] == 1)
            {
                if (dist[nr][nc] > d + 1)
                {
                    dist[nr][nc] = d + 1;
                    q.push({nr * m + nc, d + 1});
                }
            }
        }
    }
    return dist[dr][dc] == INT_MAX ? -1 : dist[dr][dc];
}
int optimal(vector<vector<int>> g, int sr, int sc, int dr, int dc)
{
    int n = g.size(), m = g[0].size();
    if (sr < 0 || sr >= n || sc < 0 || sc >= m || dr < 0 || dr >= n || dc < 0 || dc >= m || g[sr][sc] == 0 || g[dr][dc] == 0)
        return -1;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    q.push({sr * m + sc, 0});
    dist[sr][sc] = 0;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int pos = cur.first, d = cur.second;
        int r = pos / m, c = pos % m;
        if (r == dr && c == dc)
            return d;
        for (auto &x : dirs)
        {
            int nr = r + x[0], nc = c + x[1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] == 1 && dist[nr][nc] == INT_MAX)
            {
                dist[nr][nc] = d + 1;
                q.push({nr * m + nc, d + 1});
            }
        }
    }
    return -1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    int sr, sc, dr, dc;
    cin >> sr >> sc >> dr >> dc;
    cout << bruteForce(g, sr, sc, dr, dc) << "\n";
    cout << optimal(g, sr, sc, dr, dc) << "\n";
}
