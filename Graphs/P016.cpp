#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bruteForce(vector<string> board)
{
    int n = board.size(), m = board[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O')
            {
                // check if there's a path to border using BFS on matrix copy
                vector<vector<int>> vis(n, vector<int>(m, 0));
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;
                bool reaches = false;
                int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                while (!q.empty())
                {
                    auto p = q.front();
                    q.pop();
                    int r = p.first, c = p.second;
                    if (r == 0 || r == n - 1 || c == 0 || c == m - 1)
                        reaches = true;
                    for (auto &d : dirs)
                    {
                        int nr = r + d[0], nc = c + d[1];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && board[nr][nc] == 'O')
                        {
                            vis[nr][nc] = 1;
                            q.push({nr, nc});
                        }
                    }
                }
                if (!reaches)
                {
                    // flip component to X
                    for (int x = 0; x < n; x++)
                        for (int y = 0; y < m; y++)
                            if (vis[x][y])
                                board[x][y] = 'X';
                }
            }
        }
    for (int i = 0; i < n; i++)
        cout << board[i] << "\n";
}

void optimal(vector<string> board)
{
    int n = board.size(), m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 'O' && !vis[i][0])
        {
            queue<pair<int, int>> q;
            q.push({i, 0});
            vis[i][0] = 1;
            while (!q.empty())
            {
                auto p = q.front();
                q.pop();
                for (auto &d : dirs)
                {
                    int nr = p.first + d[0], nc = p.second + d[1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && board[nr][nc] == 'O')
                    {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        if (board[i][m - 1] == 'O' && !vis[i][m - 1])
        {
            queue<pair<int, int>> q;
            q.push({i, m - 1});
            vis[i][m - 1] = 1;
            while (!q.empty())
            {
                auto p = q.front();
                q.pop();
                for (auto &d : dirs)
                {
                    int nr = p.first + d[0], nc = p.second + d[1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && board[nr][nc] == 'O')
                    {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (board[0][j] == 'O' && !vis[0][j])
        {
            queue<pair<int, int>> q;
            q.push({0, j});
            vis[0][j] = 1;
            while (!q.empty())
            {
                auto p = q.front();
                q.pop();
                for (auto &d : dirs)
                {
                    int nr = p.first + d[0], nc = p.second + d[1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && board[nr][nc] == 'O')
                    {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        if (board[n - 1][j] == 'O' && !vis[n - 1][j])
        {
            queue<pair<int, int>> q;
            q.push({n - 1, j});
            vis[n - 1][j] = 1;
            while (!q.empty())
            {
                auto p = q.front();
                q.pop();
                for (auto &d : dirs)
                {
                    int nr = p.first + d[0], nc = p.second + d[1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && board[nr][nc] == 'O')
                    {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] == 'O' && !vis[i][j])
                board[i][j] = 'X';
    for (int i = 0; i < n; i++)
        cout << board[i] << "\n";
}

int main()
{
    int n, m;
    if (!(cin >> n >> m))
        return 0;
    vector<string> board(n);
    for (int i = 0; i < n; i++)
        cin >> board[i];
    bruteForce(board);
    optimal(board);
    return 0;
}
