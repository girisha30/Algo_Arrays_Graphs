#include <bits/stdc++.h>
using namespace std;

// Brute Force - Recursive
bool bruteForce(int ind, int target, vector<int>& arr) {
    if (target == 0) return true;
    if (ind == 0) return arr[0] == target;
    
    bool notTake = bruteForce(ind - 1, target, arr);
    bool take = false;
    if (target >= arr[ind]) {
        take = bruteForce(ind - 1, target - arr[ind], arr);
    }
    
    return take || notTake;
}

// Optimal - Tabulation with space optimization
bool optimal(vector<int>& arr, int target) {
    int n = arr.size();
    vector<bool> prev(target + 1, false);
    prev[0] = true;
    if (arr[0] <= target) prev[arr[0]] = true;
    
    for (int ind = 1; ind < n; ind++) {
        vector<bool> curr(target + 1, false);
        curr[0] = true;
        for (int k = 1; k <= target; k++) {
            bool notTake = prev[k];
            bool take = false;
            if (k >= arr[ind]) {
                take = prev[k - arr[ind]];
            }
            curr[k] = take || notTake;
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
    
    cout << "Brute Force: " << (bruteForce(n - 1, target, arr) ? "true" : "false") << endl;
    cout << "Optimal: " << (optimal(arr, target) ? "true" : "false") << endl;
    
    return 0;
}
