#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Helper function to count subsets with given sum
int countSubsets(int ind, int target, vector<int>& arr) {
    if (ind == 0) {
        if (target == 0 && arr[0] == 0) return 2;
        if (target == 0 || arr[0] == target) return 1;
        return 0;
    }
    
    int notTake = countSubsets(ind - 1, target, arr);
    int take = 0;
    if (target >= arr[ind]) {
        take = countSubsets(ind - 1, target - arr[ind], arr);
    }
    
    return (take + notTake) % MOD;
}

// Brute Force
int bruteForce(vector<int>& arr, int d) {
    int n = arr.size();
    int totalSum = 0;
    for (int x : arr) totalSum += x;
    
    if ((totalSum - d) < 0 || (totalSum - d) % 2 != 0) return 0;
    int target = (totalSum - d) / 2;
    
    return countSubsets(n - 1, target, arr);
}

// Optimal - Tabulation
int optimal(vector<int>& arr, int d) {
    int n = arr.size();
    int totalSum = 0;
    for (int x : arr) totalSum += x;
    
    if ((totalSum - d) < 0 || (totalSum - d) % 2 != 0) return 0;
    int target = (totalSum - d) / 2;
    
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    
    if (arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;
    
    if (arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;
    
    for (int ind = 1; ind < n; ind++) {
        for (int k = 0; k <= target; k++) {
            int notTake = dp[ind - 1][k];
            int take = 0;
            if (k >= arr[ind]) {
                take = dp[ind - 1][k - arr[ind]];
            }
            dp[ind][k] = (take + notTake) % MOD;
        }
    }
    
    return dp[n - 1][target];
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Brute Force: " << bruteForce(arr, d) << endl;
    cout << "Optimal: " << optimal(arr, d) << endl;
    
    return 0;
}
