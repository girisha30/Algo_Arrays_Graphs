#include <bits/stdc++.h>
using namespace std;

// Brute Force Function
int bruteForce(int n) {
    if (n == 0) return 1;      // Reached exactly
    if (n < 0) return 0;       // Invalid path

    return bruteForce(n - 1) + bruteForce(n - 2);
}

// Optimal DP Function
int optimalDP(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    if (n >= 1) dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Main Function
int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    cout << "Brute Force Result: " << bruteForce(n) << endl;
    cout << "Optimal DP Result: " << optimalDP(n) << endl;

    return 0;
}
