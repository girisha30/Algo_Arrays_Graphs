#include <iostream>
#include <vector>
#include <set>
using namespace std;

void dfsShape(int r, int c, int br, int bc, vector<vector<int>> &g, vector<pair<int, int>> &shape)
{
    g[r][c] = 0;
    shape.push_back({r - br, c - bc});
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (auto &d : dirs)
    {
        int nr = r + d[0], nc = c + d[1];
        if (nr >= 0 && nr < (int)g.size() && nc >= 0 && nc < (int)g[0].size() && g[nr][nc] == 1)
            dfsShape(nr, nc, br, bc, g, shape);
    }
}

int bruteForce(vector<vector<int>> g)
{
    int n = g.size(), m = g[0].size();
    set<vector<pair<int, int>>> shapes;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 1)
            {
                vector<pair<int, int>> shape;
                dfsShape(i, j, i, j, g, shape);
                shapes.insert(shape);
            }
    return shapes.size();
}

int optimal(vector<vector<int>> g)
{
    return bruteForce(g);
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
