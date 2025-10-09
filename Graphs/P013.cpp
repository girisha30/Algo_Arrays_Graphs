#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> bruteForce(vector<vector<int>> img, int sr, int sc, int newColor)
{
    int m = img.size(), n = img[0].size();
    int old = img[sr][sc];
    if (old == newColor)
        return img;
    bool changed = true;
    while (changed)
    {
        changed = false;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if ((i == sr && j == sc) || img[i][j] == newColor)
                {
                    int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + di[k], nj = j + dj[k];
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && img[ni][nj] == old)
                        {
                            img[ni][nj] = newColor;
                            changed = true;
                        }
                    }
                }
            }
        if (img[sr][sc] != newColor)
        {
            img[sr][sc] = newColor;
            changed = true;
        }
    }
    return img;
}
vector<vector<int>> optimal(vector<vector<int>> img, int sr, int sc, int newColor)
{
    int m = img.size(), n = img[0].size();
    int old = img[sr][sc];
    if (old == newColor)
        return img;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    img[sr][sc] = newColor;
    int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int r = cur.first, c = cur.second;
        for (int k = 0; k < 4; k++)
        {
            int nr = r + di[k], nc = c + dj[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && img[nr][nc] == old)
            {
                img[nr][nc] = newColor;
                q.push({nr, nc});
            }
        }
    }
    return img;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> img(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> img[i][j];
    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;
    auto a = bruteForce(img, sr, sc, newColor), b = optimal(img, sr, sc, newColor);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << b[i][j] << " ";
        cout << "\n";
    }
}
