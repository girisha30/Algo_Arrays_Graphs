#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Function for Linear House Robber
int bruteSolve(int i, vector<int> &arr) {
    if (i == 0) return arr[0];
    if (i < 0) return 0;

    int pick = arr[i] + bruteSolve(i - 2, arr);
    int notPick = bruteSolve(i - 1, arr);

    return max(pick, notPick);
}

// Brute Force for Circular Houses
int bruteForce_Circular(vector<int> &arr) {
    int n = arr.size();
    if (n == 1) return arr[0];

    vector<int> temp1(arr.begin(), arr.begin() + n - 1); // exclude last
    vector<int> temp2(arr.begin() + 1, arr.end());       // exclude first

    int case1 = bruteSolve(temp1.size() - 1, temp1);
    int case2 = bruteSolve(temp2.size() - 1, temp2);

    return max(case1, case2);
}

// Optimal DP (Tabulation) for Linear House Robber
int robLinear(vector<int> &arr) {
    int n = arr.size();

    if (n == 1) return arr[0];

    vector<int> dp(n, 0);
    dp[0] = arr[0];

    for (int i = 1; i < n; i++) {
        int pick = arr[i];
        if (i > 1) pick += dp[i - 2];

        int notPick = dp[i - 1];
        dp[i] = max(pick, notPick);
    }

    return dp[n - 1];
}

// Optimal approach for circular robber problem
int optimal_Circular(vector<int> &arr) {
    int n = arr.size();
    if (n == 1) return arr[0];

    vector<int> temp1(arr.begin(), arr.begin() + n - 1);
    vector<int> temp2(arr.begin() + 1, arr.end());

    return max(robLinear(temp1), robLinear(temp2));
}

// Main Function
int main() {
    int n;
    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter money in each house: ";
