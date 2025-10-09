#include <bits/stdc++.h>
using namespace std;

// Brute Force: use set
int missingBrute(const vector<int>& a) {
    unordered_set<int> s(a.begin(), a.end());
    for (int x = 0; x <= (int)a.size(); x++) {
        if (!s.count(x)) return x;
    }
    return -1;
}

// Optimal: XOR trick
int missingOptimal(const vector<int>& a) {
    int n = a.size();
    int xo = 0;
    for (int i = 0; i <= n; i++) xo ^= i;
    for (int v : a) xo ^= v;
    return xo;
}

int main() {
    int n;
    cout << "Enter size of array (n): ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " elements (distinct, from 0..n, one missing): ";
    for (int i=0;i<n;i++) cin >> a[i];

    cout << "Missing Number (Brute Force): " << missingBrute(a) << endl;
    cout << "Missing Number (Optimal): " << missingOptimal(a) << endl;
}
