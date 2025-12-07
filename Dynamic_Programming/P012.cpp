#include <bits/stdc++.h>
using namespace std;

// Brute Force - Recursive
int bruteForce(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid) {
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e9;
    if (i == n - 1) {
        if (j1 == j2) return grid[i][j1];
        return grid[i][j1] + grid[i][j2];
    }
    
    int maxi = -1e9;
    for (int dj1 = -1; dj1 <= 1; dj1++) {
        for (int dj2 = -1; dj2 <= 1; dj2++) {
            int value = 0;
            if (j1 == j2) value = grid[i][j1];
            else value = grid[i][j1] + grid[i][j2];
            value += bruteForce(i + 1, j1 + dj1, j2 + dj2, n, m, grid);
            maxi = max(maxi, value);
        }
    }
    
    return maxi;
}

// Optimal - Tabulation with space optimization
int optimal(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> prev(m, vector<int>(m, 0));
    
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2) prev[j1][j2] = grid[n - 1][j1];
            else prev[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }
    
    for (int i = n - 2; i >= 0; i--) {
        vector<vector<int>> curr(m, vector<int>(m, 0));
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = -1e9;
                for (int dj1 = -1; dj1 <= 1; dj1++) {
                    for (int dj2 = -1; dj2 <= 1; dj2++) {
                        int value = 0;
                        if (j1 == j2) value = grid[i][j1];
                        else value = grid[i][j1] + grid[i][j2];
                        
                        int nj1 = j1 + dj1;
                        int nj2 = j2 + dj2;
                        if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {
                            value += prev[nj1][nj2];
                            maxi = max(maxi, value);
                        }
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        prev = curr;
    }
    
    return prev[0][m - 1];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    cout << "Brute Force: " << bruteForce(0, 0, m - 1, n, m, grid) << endl;
    cout << "Optimal: " << optimal(grid) << endl;
    
    return 0;
}
