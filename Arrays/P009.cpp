#include <bits/stdc++.h>
using namespace std;

// Brute Force
int maxConsecOnesBrute(const vector<int>& a) {
    int n = a.size(), best = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            int j = i;
            while (j < n && a[j] == 1) j++;
            best = max(best, j - i);
            i = j;
        }
    }
    return best;
}

// Optimal
int maxConsecOnesOptimal(const vector<int>& a) {
    int cur = 0, best = 0;
    for (int v : a) {
        if (v == 1) {
            cur++;
            best = max(best, cur);
        } else {
            cur = 0;
        }
    }
    return best;
}

int main() {
    int n;
    cout << "Enter size of binary array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " elements (only 0 or 1): ";
    for (int i=0;i<n;i++) cin >> a[i];

    cout << "Max Consecutive Ones (Brute Force): " << maxConsecOnesBrute(a) << endl;
    cout << "Max Consecutive Ones (Optimal): " << maxConsecOnesOptimal(a) << endl;
}
