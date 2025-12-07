#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach
int bruteSolve(int i, int j, vector<vector<int>> &maze, int N, int M) {
    if (i >= N || j >= M) return 0;

    if (maze[i][j] == -1) return 0;

    if (i == N - 1 && j == M - 1) return 1;

    int down = bruteSolve(i + 1, j, maze, N, M);
    int right = bruteSolve(i, j + 1, maze, N, M);

    return down + right;
}

int bruteForce_UniquePathsObstacle(vector<vector<int>> &maze) {
    int N = maze.size();
    int M = maze[0].size();

    return bruteSolve(0, 0, maze, N, M);
}

// Optimal DP (Tabulation)
int optimal_UniquePathsObstacle(vector<vector<int>> &maze) {
    int N = maze.size();
    int M = maze[0].size();

    vector<vector<int>> dp(N, vector<int>(M, 0));

    if (maze[0][0] == -1) return 0;
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (maze[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }

            if (i == 0 && j == 0) continue;

            int fromTop = 0, fromLeft = 0;

            if (i > 0) fromTop = dp[i - 1][j];
            if (j > 0) fromLeft = dp[i][j - 1];

            dp[i][j] = fromTop + fromLeft;
        }
    }

    return dp[N - 1][M - 1];
}

// Main Function
int main() {
    int N, M;
    cout << "Enter N and M: ";
    cin >> N >> M;

    vector<vector<int>> maze(N, vector<int>(M));
    cout << "Enter maze values (0 for free cell, -1 for blocked):\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> maze[i][j];

    cout << "Brute Force Result: "
         << bruteForce_UniquePathsObstacle(maze) << endl;

    cout << "Optimal DP Result: "
         << optimal_UniquePathsObstacle(maze) << endl;

    return 0;
}
