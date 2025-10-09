#include <iostream>
#include <vector>
using namespace std;

int bruteForce(vector<vector<int>> g)
{
    int n = g.size(), m = g[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 1)
            {
                cnt++;
                // BFS/DFS mark all connected (8-dir naive)
                vector<vector<int>> vis(n, vector<int>(m, 0));
                vector<pair<int, int>> st;
                st.push_back({i, j});
                vis[i][j] = 1;
                for (size_t k = 0; k < st.size(); k++)
                {
                    int r = st[k].first, c = st[k].second;
                    for (int dr = -1; dr <= 1; dr++)
                        for (int dc = -1; dc <= 1; dc++)
                        {
                            int nr = r + dr, nc = c + dc;
                            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && g[nr][nc] == 1)
                            {
                                vis[nr][nc] = 1;
                                st.push_back({nr, nc});
                            }
                        }
                }
                for (auto &p : st)
                    g[p.first][p.second] = 0;
            }
    return cnt;
}

int optimal(vector<vector<int>> g)
{
    int n = g.size(), m = g[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 1)
            {
                cnt++; // dfs
                vector<pair<int, int>> st;
                st.push_back({i, j});
                g[i][j] = 0;
                for (size_t k = 0; k < st.size(); k++)
                {
                    int r = st[k].first, c = st[k].second;
                    for (int dr = -1; dr <= 1; dr++)
                        for (int dc = -1; dc <= 1; dc++)
                        {
                            int nr = r + dr, nc = c + dc;
                            if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] == 1)
                            {
                                g[nr][nc] = 0;
                                st.push_back({nr, nc});
                            }
                        }
                }
            }
        }
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
