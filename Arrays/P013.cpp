#include <bits/stdc++.h>
using namespace std;

// Brute Force: for each element, check right side
vector<int> leadersBrute(const vector<int>& a) {
    int n = a.size();
    vector<int> leaders;
    for (int i=0;i<n;i++) {
        bool isLeader = true;
        for (int j=i+1;j<n;j++) {
            if (a[j] > a[i]) { isLeader = false; break; }
        }
        if (isLeader) leaders.push_back(a[i]);
    }
    return leaders;
}

// Optimal: traverse from right, track max
vector<int> leadersOptimal(const vector<int>& a) {
    int n = a.size();
    vector<int> leaders;
    int maxRight = INT_MIN;
    for (int i=n-1;i>=0;i--) {
        if (a[i] > maxRight) {
            leaders.push_back(a[i]);
            maxRight = a[i];
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for (int i=0;i<n;i++) cin >> a[i];

    auto bf = leadersBrute(a);
    auto op = leadersOptimal(a);

    cout << "Leaders (Brute Force): ";
    for (int x: bf) cout << x << " "; cout << endl;

    cout << "Leaders (Optimal): ";
    for (int x: op) cout << x << " "; cout << endl;
}
