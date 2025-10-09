#include <bits/stdc++.h>
using namespace std;

// Brute Force
int longestSubBrute(const vector<int>& a, int k) {
    int n=a.size(), best=0;
    for (int i=0;i<n;i++) {
        int sum=0;
        for (int j=i;j<n;j++) {
            sum+=a[j];
            if (sum==k) best=max(best,j-i+1);
        }
    }
    return best;
}

// Optimal: prefix sum + hashmap
int longestSubOptimal(const vector<int>& a, int k) {
    unordered_map<int,int> firstOccur;
    int sum=0, best=0;
    for (int i=0;i<a.size();i++) {
        sum += a[i];
        if (sum==k) best=max(best,i+1);
        if (firstOccur.count(sum-k)) best=max(best,i-firstOccur[sum-k]);
        if (!firstOccur.count(sum)) firstOccur[sum]=i;
    }
    return best;
}

int main() {
    int n,k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> a(n);

    cout << "Enter " << n << " elements (can be +ve/-ve): ";
    for (int i=0;i<n;i++) cin >> a[i];

    cout << "Enter target sum: ";
    cin >> k;

    cout << "Longest Subarray Length (Brute Force): " << longestSubBrute(a, k) << endl;
    cout << "Longest Subarray Length (Optimal): " << longestSubOptimal(a, k) << endl;
}
