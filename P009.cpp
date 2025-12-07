#include <bits/stdc++.h>
using namespace std;

// Brute Force - Recursive
int bruteForce(int i, int j, vector<vector<int>>& matrix) {
    if (i == 0 && j == 0) return matrix[0][0];
    if (i < 0 || j < 0) return 1e9;
    
    int up = matrix[i][j] + bruteForce(i - 1, j, matrix);
    int left = matrix[i][j] + bruteForce(i, j - 1, matrix);
    
    return min(up, left);
}

// Optimal - Tabulation with space optimization
int optimal(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m, 0);
    
    for (int i = 0; i < n; i++) {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                curr[j] = matrix[0][0];
            } else {
                int up = 1e9, left = 1e9;
                if (i > 0) up = prev[j];
                if (j > 0) left = curr[j - 1];
                curr[j] = matrix[i][j] + min(up, left);
            }
        }
        prev = curr;
    }
    
    return prev[m - 1];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << "Brute Force: " << bruteForce(n - 1, m - 1, matrix) << endl;
    cout << "Optimal: " << optimal(matrix) << endl;
    
    return 0;
}
