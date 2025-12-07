#include <bits/stdc++.h>
using namespace std;

// Brute Force - Generate all subsets
void generateSubsets(int ind, vector<int>& arr, vector<int>& subset, int& minDiff, int totalSum) {
    if (ind == arr.size()) {
        int sum1 = 0;
        for (int x : subset) sum1 += x;
        int sum2 = totalSum - sum1;
        minDiff = min(minDiff, abs(sum1 - sum2));
        return;
    }
    
    subset.push_back(arr[ind]);
    generateSubsets(ind + 1, arr, subset, minDiff, totalSum);
    subset.pop_back();
    
    generateSubsets(ind + 1, arr, subset, minDiff, totalSum);
}

int bruteForce(vector<int>& arr) {
    int totalSum = 0;
    for (int x : arr) totalSum += x;
    
    int minDiff = totalSum;
    vector<int> subset;
    generateSubsets(0, arr, subset, minDiff, totalSum);
    
    return minDiff;
}

// Optimal - DP tabulation
int optimal(vector<int>& arr) {
    int n = arr.size();
    int totalSum = 0;
    for (int x : arr) totalSum += x;
    
    vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));
    
    for (int i = 0; i < n; i++) dp[i][0] = true;
    if (arr[0] <= totalSum) dp[0][arr[0]] = true;
    
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= totalSum; target++) {
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if (target >= arr[ind]) {
                take = dp[ind - 1][target - arr[ind]];
            }
            dp[ind][target] = take || notTake;
        }
    }
    
    int minDiff = totalSum;
    for (int s1 = 0; s1 <= totalSum / 2; s1++) {
        if (dp[n - 1][s1]) {
            int s2 = totalSum - s1;
            minDiff = min(minDiff, abs(s1 - s2));
        }
    }
    
    return minDiff;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Brute Force: " << bruteForce(arr) << endl;
    cout << "Optimal: " << optimal(arr) << endl;
    
    return 0;
}
