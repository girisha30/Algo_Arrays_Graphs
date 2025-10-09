#include <bits/stdc++.h>
using namespace std;

// Brute Force: frequency map
int singleBrute(const vector<int>& a) {
    unordered_map<int,int> freq;
    for (int v: a) freq[v]++;
    for (auto &p: freq) if (p.second==1) return p.first;
    return -1;
}

// Optimal: XOR trick
int singleOptimal(const vector<int>& a) {
    int xo=0;
    for (int v: a) xo ^= v;
    return xo;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> a(n);

    cout << "Enter " << n << " elements (all twice except one): ";
    for (int i=0;i<n;i++) cin >> a[i];

    cout << "Single Number (Brute Force): " << singleBrute(a) << endl;
    cout << "Single Number (Optimal): " << singleOptimal(a) << endl;
}
