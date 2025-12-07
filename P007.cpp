#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach
int bruteSolve(int i, int j, int M, int N) {
    if (i == M - 1 && j == N - 1)
        return 1;  // Reached destination

    if (i >= M || j >= N)
        return 0;  // Out of bounds

    int down = bruteSolve(i + 1, j, M, N);
    int right = bruteSolve(i, j + 1, M, N);

    return down + right;
}

int bruteForce_UniquePaths(int M, int N) {
    return bruteSolve(0, 0, M, N);
}

// Optimal DP (Tabulation)
int optimal_UniquePaths(int M, int N) {
    vector<vector<int>> dp(M, vector<int>(N, 1));

    for (int i = 1; i < M; i++) {
        for (int j = 1; j < N; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[M - 1][N - 1];
}

// Main Function
int main() {
    int M, N;
    cout << "Enter matrix size M and N: ";
    cin >> M >> N;

    cout << "Brute Force Result: " 
         << bruteForce_UniquePaths(M, N) << endl;

    cout << "Optimal DP Result: "
         << optimal_UniquePaths(M, N) << endl;

    return 0;
}
