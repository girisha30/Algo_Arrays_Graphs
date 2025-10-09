#include <bits/stdc++.h>
using namespace std;

// Brute Force: try all subarrays
int countSubBrute(const vector<int>& a, int k) {
    int n = a.size(), cnt = 0;
    for (int i=0;i<n;i++) {
        int sum=0;
        for (int j=i;j<n;j++) {
            sum += a[j];
            if (sum == k) cnt++;
        }
    }
    return cnt;
}

// Optimal: prefix sum + hashmap
int countSubOptimal(const vector<int>& a, int k) {
    unordered_map<int,int> prefixCount;
    prefixCount[0] = 1;
    int sum=0, cnt=0;
    for (int v : a) {
        sum += v;
        if (prefixCount.count(sum-k)) cnt += prefixCount[sum-k];
        prefixCount[sum]++;
    }
    return cnt;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for (int i=0;i<n;i++) cin >> a[i];

    cout << "Enter target sum: ";
    cin >> k;

    cout << "Subarrays with sum " << k << " (Brute Force): " << countSubBrute(a, k) << endl;
    cout << "Subarrays with sum " << k << " (Optimal): " << countSubOptimal(a, k) << endl;
}
