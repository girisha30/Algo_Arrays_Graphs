#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach
int bruteSolve(int i, vector<int> &height, int K) {
    if (i == 0) return 0;

    int minEnergy = INT_MAX;

    for (int j = 1; j <= K; j++) {
        if (i - j >= 0) {
            int cost = bruteSolve(i - j, height, K) +
                       abs(height[i] - height[i - j]);
            minEnergy = min(minEnergy, cost);
        }
    }

    return minEnergy;
}

int bruteForce_FrogK(vector<int> &height, int K) {
    int n = height.size();
    return bruteSolve(n - 1, height, K);
}

// Optimal DP Approach (Tabulation)
int optimal_FrogK(vector<int> &height, int K) {
    int n = height.size();

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= K; j++) {
            if (i - j >= 0) {
                int cost = dp[i - j] + abs(height[i] - height[i - j]);
                dp[i] = min(dp[i], cost);
            }
        }
    }

    return dp[n - 1];
}

// Main Function
int main() {
    int n, K;
    cout << "Enter number of stairs: ";
    cin >> n;

    cout << "Enter K (maximum jump): ";
    cin >> K;

    vector<int> height(n);
    cout << "Enter heights array: ";
    for (int i = 0; i < n; i++) cin >> height[i];

    cout << "Brute Force Result: "
         << bruteForce_FrogK(height, K) << endl;

    cout << "Optimal DP Result: "
         << optimal_FrogK(height, K) << endl;

    return 0;
}
