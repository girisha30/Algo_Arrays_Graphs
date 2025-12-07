#include <bits/stdc++.h>
using namespace std;

// Brute Force - Recursive
int bruteForce(int i, int j, vector<vector<int>>& triangle, int n) {
    if (i == n - 1) return triangle[i][j];
    
    int down = triangle[i][j] + bruteForce(i + 1, j, triangle, n);
    int diagonal = triangle[i][j] + bruteForce(i + 1, j + 1, triangle, n);
    
    return min(down, diagonal);
}

// Optimal - Tabulation with space optimization
int optimal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> prev = triangle[n - 1];
    
    for (int i = n - 2; i >= 0; i--) {
        vector<int> curr(i + 1);
        for (int j = 0; j <= i; j++) {
            int down = triangle[i][j] + prev[j];
            int diagonal = triangle[i][j] + prev[j + 1];
            curr[j] = min(down, diagonal);
        }
        prev = curr;
    }
    
    return prev[0];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }
    
    cout << "Brute Force: " << bruteForce(0, 0, triangle, n) << endl;
    cout << "Optimal: " << optimal(triangle) << endl;
    
    return 0;
}
