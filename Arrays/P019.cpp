#include <bits/stdc++.h>
using namespace std;

// Brute Force
int longestSubBrute(const vector<int>& a, int k) {
    int n = a.size(), best=0;
    for (int i=0;i<n;i++) {
        int sum=0;
        for (int j=i;j<n;j++) {
            sum += a[j];
            if (sum==k) best = max(best, j-i+1);
        }
    }
    return best;
}

// Optimal: sliding window (positives only)
int longestSubOptimal(const vector<int>& a, int k) {
    int n=a.size(), left=0, sum=0, best=0;
    for (int right=0; right<n; right++) {
        sum += a[right];
        while (sum>k && left<=right) sum -= a[left++];
        if (sum==k) best = max(best, right-left+1);
    }
    return best;
}

int main() {
    int n,k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> a(n);

    cout << "Enter " << n << " elements (positives): ";
    for (int i=0;i<n;i++) cin >> a[i];

    cout << "Enter target sum: ";
    cin >> k;

    cout << "Longest Subarray Length (Brute Force): " << longestSubBrute(a, k) << endl;
    cout << "Longest Subarray Length (Optimal): " << longestSubOptimal(a, k) << endl;
}
