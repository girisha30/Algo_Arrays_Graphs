#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

bool can(int mid, const vector<vector<int>> &h)
{
    int r = h.size(), c = h[0].size();
    vector<vector<int>> vis(r, vector<int>(c, 0));
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 1;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        if (x == r - 1 && y == c - 1)
            return true;
        for (auto &d : dirs)
        {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && !vis[nx][ny])
            {
                if (abs(h[nx][ny] - h[x][y]) <= mid)
                {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return false;
}
int bruteForce(const vector<vector<int>> &h)
{
    int lo = 0, hi = 0, r = h.size(), c = h[0].size();
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (i)
                hi = max(hi, abs(h[i][j] - h[i - 1][j]));
            if (j)
                hi = max(hi, abs(h[i][j] - h[i][j - 1]));
        }
    int ans = hi;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (can(mid, h))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}
int optimal(const vector<vector<int>> &h)
{
    int r = h.size(), c = h[0].size();
    vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
    using T = pair<int, pair<int, int>>;
    priority_queue<T, vector<T>, greater<T>> pq;
    dist[0][0] = 0;
    pq.push({0, {0, 0}});
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int d = cur.first, x = cur.second.first, y = cur.second.second;
        if (d != dist[x][y])
            continue;
        if (x == r - 1 && y == c - 1)
            return d;
        for (auto &dd : dirs)
        {
            int nx = x + dd[0], ny = y + dd[1];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c)
            {
                int w = abs(h[nx][ny] - h[x][y]);
                int nd = max(d, w);
                if (nd < dist[nx][ny])
                {
                    dist[nx][ny] = nd;
                    pq.push({nd, {nx, ny}});
                }
            }
        }
    }
    return dist[r - 1][c - 1];
}
int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> h(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> h[i][j];
    cout << bruteForce(h) << "\n";
    cout << optimal(h) << "\n";
}
