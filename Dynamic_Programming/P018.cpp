#include <bits/stdc++.h>
using namespace std;

// Brute Force - Recursive
int bruteHelper(int ind, int target, vector<int>& arr) {
    if (ind == 0) {
        if (target == 0 && arr[0] == 0) return 2;
        if (target == 0 || abs(target) == arr[0]) return 1;
        return 0;
    }
    
    int positive = bruteHelper(ind - 1, target - arr[ind], arr);
    int negative = bruteHelper(ind - 1, target + arr[ind], arr);
    
    return positive + negative;
}

int bruteForce(vector<int>& arr, int target) {
    int n = arr.size();
    return bruteHelper(n - 1, target, arr);
}

// Optimal - Convert to subset sum problem
int countSubsets(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    
    if (arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;
    
    if (arr[0] != 0 && arr[0] <= sum) dp[0][arr[0]] = 1;
    
    for (int ind = 1; ind < n; ind++) {
        for (int k = 0; k <= sum; k++) {
            int notTake = dp[ind - 1][k];
            int take = 0;
            if (k >= arr[ind]) {
                take = dp[ind - 1][k - arr[ind]];
            }
            dp[ind][k] = take + notTake;
        }
    }
    
    return dp[n - 1][sum];
}

int optimal(vector<int>& arr, int target) {
    int totalSum = 0;
    for (int x : arr) totalSum += x;
    
    if ((totalSum - target) < 0 || (totalSum - target) % 2 != 0) return 0;
    int sum = (totalSum - target) / 2;
    
    return countSubsets(arr, sum);
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Brute Force: " << bruteForce(arr, target) << endl;
    cout << "Optimal: " << optimal(arr, target) << endl;
    
    return 0;
}
