#include <bits/stdc++.h>
using namespace std;

// Brute Force: try all subarrays
int maxProdBrute(const vector<int>& a) {
    int n = a.size();
    int best = INT_MIN;
    for (int i=0;i<n;i++) {
        int prod = 1;
        for (int j=i;j<n;j++) {
            prod *= a[j];
            best = max(best, prod);
        }
    }
    return best;
}

// Optimal: track max/min product
int maxProdOptimal(const vector<int>& a) {
    int n = a.size();
    int curMax = a[0], curMin = a[0], best = a[0];
    for (int i=1;i<n;i++) {
        if (a[i] < 0) swap(curMax, curMin);
        curMax = max(a[i], curMax * a[i]);
        curMin = min(a[i], curMin * a[i]);
        best = max(best, curMax);
    }
    return best;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> a(n);

    cout << "Enter " << n << " elements: ";
    for (int i=0;i<n;i++) cin >> a[i];

    cout << "Maximum Product Subarray (Brute Force): " << maxProdBrute(a) << endl;
    cout << "Maximum Product Subarray (Optimal): " << maxProdOptimal(a) << endl;
}
