#include <bits/stdc++.h>
using namespace std;

// Memoization (Bruteforce + DP)
int frogMemo(int i, vector<int> &height, vector<int> &dp) {
    if (i == 0) return 0;

    if (dp[i] != -1) return dp[i];

    int jumpOne = frogMemo(i - 1, height, dp) 
                  + abs(height[i] - height[i - 1]);

    int jumpTwo = INT_MAX;
    if (i > 1) {
        jumpTwo = frogMemo(i - 2, height, dp) 
                  + abs(height[i] - height[i - 2]);
    }

    return dp[i] = min(jumpOne, jumpTwo);
}

int bruteForce_FrogJump(vector<int> &height) {
    int n = height.size();
    vector<int> dp(n, -1);
    return frogMemo(n - 1, height, dp);
}

// Optimal Approach (Space Optimized DP)
int optimal_FrogJump(vector<int> &height) {
    int n = height.size();
    if (n == 1) return 0;

    int prev1 = 0;  // dp[i-1]
    int prev2 = 0;  // dp[i-2]

    for (int i = 1; i < n; i++) {
        int jumpOne = prev1 + abs(height[i] - height[i - 1]);

        int jumpTwo = INT_MAX;
        if (i > 1) {
            jumpTwo = prev2 + abs(height[i] - height[i - 2]);
        }

        int curr = min(jumpOne, jumpTwo);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

// Main Function
int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) cin >> height[i];

    cout << "Brute Force (Memoization) Result: " 
         << bruteForce_FrogJump(height) << endl;

    cout << "Optimal (Space Optimized DP) Result: " 
         << optimal_FrogJump(height) << endl;

    return 0;
}
