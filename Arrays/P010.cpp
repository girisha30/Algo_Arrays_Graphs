#include <bits/stdc++.h>
using namespace std;

// Brute Force: frequency map
int majorityBrute(const vector<int>& a) {
    unordered_map<int,int> freq;
    for (int v : a) {
        freq[v]++;
        if (freq[v] > (int)a.size()/2) return v;
    }
    return -1;
}

// Optimal: Boyer–Moore
int majorityOptimal(const vector<int>& a) {
    int cand = 0, cnt = 0;
    for (int v : a) {
        if (cnt == 0) { cand = v; cnt = 1; }
        else cnt += (v == cand) ? 1 : -1;
    }
    return cand; // guaranteed to exist
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for (int i=0;i<n;i++) cin >> a[i];

    cout << "Majority Element (Brute Force): " << majorityBrute(a) << endl;
    cout << "Majority Element (Optimal): " << majorityOptimal(a) << endl;
}
