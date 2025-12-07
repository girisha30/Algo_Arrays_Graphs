#include <bits/stdc++.h>
using namespace std;

// Brute Force - Recursive
int bruteForce(int ind, int target, vector<int>& arr) {
    if (target == 0) return 1;
    if (ind == 0) return (arr[0] == target) ? 1 : 0;
    
    int notTake = bruteForce(ind - 1, target, arr);
    int take = 0;
    if (target >= arr[ind]) {
        take = bruteForce(ind - 1, target - arr[ind], arr);
    }
    
    return take + notTake;
}

// Optimal - Tabulation with space optimization
int optimal(vector<int>& arr, int target) {
    int n = arr.size();
    vector<int> prev(target + 1, 0);
    prev[0] = 1;
    if (arr[0] <= target) prev[arr[0]] = 1;
    
    for (int ind = 1; ind < n; ind++) {
        vector<int> curr(target + 1, 0);
        curr[0] = 1;
        for (int k = 1; k <= target; k++) {
            int notTake = prev[k];
            int take = 0;
            if (k >= arr[ind]) {
                take = prev[k - arr[ind]];
            }
            curr[k] = take + notTake;
        }
        prev = curr;
    }
    
    return prev[target];
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Brute Force: " << bruteForce(n - 1, target, arr) << endl;
    cout << "Optimal: " << optimal(arr, target) << endl;
    
    return 0;
}
