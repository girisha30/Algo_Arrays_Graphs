#include <bits/stdc++.h>
using namespace std;

// Brute Force - Recursive
int bruteForce(int i, int j, vector<vector<int>>& matrix, int m) {
    if (j < 0 || j >= m) return -1e9;
    if (i == 0) return matrix[0][j];
    
    int up = matrix[i][j] + bruteForce(i - 1, j, matrix, m);
    int leftDiag = matrix[i][j] + bruteForce(i - 1, j - 1, matrix, m);
    int rightDiag = matrix[i][j] + bruteForce(i - 1, j + 1, matrix, m);
    
    return max({up, leftDiag, rightDiag});
}

// Optimal - Tabulation with space optimization
int optimal(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev = matrix[0];
    
    for (int i = 1; i < n; i++) {
        vector<int> curr(m);
        for (int j = 0; j < m; j++) {
            int up = matrix[i][j] + prev[j];
            int leftDiag = -1e9, rightDiag = -1e9;
            if (j > 0) leftDiag = matrix[i][j] + prev[j - 1];
            if (j < m - 1) rightDiag = matrix[i][j] + prev[j + 1];
            curr[j] = max({up, leftDiag, rightDiag});
        }
        prev = curr;
    }
    
    return *max_element(prev.begin(), prev.end());
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
    
    int maxBrute = -1e9;
    for (int j = 0; j < m; j++) {
        maxBrute = max(maxBrute, bruteForce(n - 1, j, matrix, m));
    }
    
    cout << "Brute Force: " << maxBrute << endl;
    cout << "Optimal: " << optimal(matrix) << endl;
    
    return 0;
}
