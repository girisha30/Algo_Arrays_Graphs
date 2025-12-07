#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach
int bruteSolve(int day, int last, vector<vector<int>> &points) {
    if (day == 0) {
        int maxi = 0;
        for (int act = 0; act < 3; act++) {
            if (act != last)
                maxi = max(maxi, points[0][act]);
        }
        return maxi;
    }

    int maxi = 0;
    for (int act = 0; act < 3; act++) {
        if (act != last) {
            int val = points[day][act] + bruteSolve(day - 1, act, points);
            maxi = max(maxi, val);
        }
    }
    return maxi;
}

int bruteForce_NinjaTraining(vector<vector<int>> &points) {
    int n = points.size();
    return bruteSolve(n - 1, 3, points); // 3 means no restriction initially
}

// Optimal DP (Tabulation Approach)
int optimal_NinjaTraining(vector<vector<int>> &points) {
    int n = points.size();

    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Base case for day 0
    for (int last = 0; last < 4; last++) {
        int maxi = 0;
        for (int act = 0; act < 3; act++) {
            if (act != last)
                maxi = max(maxi, points[0][act]);
        }
        dp[0][last] = maxi;
    }

    // Fill DP table
    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            int maxi = 0;
            for (int act = 0; act < 3; act++) {
                if (act != last) {
                    int val = points[day][act] + dp[day - 1][act];
                    maxi = max(maxi, val);
                }
            }
            dp[day][last] = maxi;
        }
    }

    return dp[n - 1][3]; // No restriction on last day
}

// Main Function
int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(3));
    cout << "Enter merit points (N rows, 3 columns):\n";
    for (int i = 0; i < n; i++)
        cin >> points[i][0] >> points[i][1] >> points[i][2];

    cout << "Brute Force Result: "
         << bruteForce_NinjaTraining(points) << endl;

    cout << "Optimal DP Result: "
         << optimal_NinjaTraining(points) << endl;

    return 0;
}
