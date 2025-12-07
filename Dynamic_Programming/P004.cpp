#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach
int bruteSolve(int i, vector<int> &arr) {
    if (i == 0) return arr[0];
    if (i < 0) return 0;

    int pick = arr[i] + bruteSolve(i - 2, arr);
    int notPick = bruteSolve(i - 1, arr);

    return max(pick, notPick);
}

int bruteForce_NonAdjacent(vector<int> &arr) {
    int n = arr.size();
    return bruteSolve(n - 1, arr);
}


// Optimal DP (Tabulation)
int optimal_NonAdjacent(vector<int> &arr) {
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

// Main Function
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Brute Force Result: "
         << bruteForce_NonAdjacent(arr) << endl;

    cout << "Optimal DP Result: "
         << optimal_NonAdjacent(arr) << endl;

    return 0;
}
