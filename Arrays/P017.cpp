#include <bits/stdc++.h>
using namespace std;

// Brute Force: merge into set
vector<int> unionBrute(const vector<int>& a, const vector<int>& b) {
    set<int> s;
    for (int x : a) s.insert(x);
    for (int x : b) s.insert(x);
    return vector<int>(s.begin(), s.end());
}

// Optimal: two-pointer merge
vector<int> unionOptimal(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int i=0, j=0;
    while (i<a.size() && j<b.size()) {
        if (a[i] <= b[j]) {
            if (res.empty() || res.back()!=a[i]) res.push_back(a[i]);
            i++;
        } else {
            if (res.empty() || res.back()!=b[j]) res.push_back(b[j]);
            j++;
        }
    }
    while (i<a.size()) { if (res.empty()||res.back()!=a[i]) res.push_back(a[i]); i++; }
    while (j<b.size()) { if (res.empty()||res.back()!=b[j]) res.push_back(b[j]); j++; }
    return res;
}

int main() {
    int n,m;
    cout << "Enter size of first sorted array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i=0;i<n;i++) cin >> a[i];

    cout << "Enter size of second sorted array: ";
    cin >> m;
    vector<int> b(m);
    cout << "Enter " << m << " sorted elements: ";
    for (int i=0;i<m;i++) cin >> b[i];

    auto bf = unionBrute(a,b);
    auto op = unionOptimal(a,b);

    cout << "Union (Brute Force): ";
    for (int x: bf) cout << x << " "; cout << endl;

    cout << "Union (Optimal): ";
    for (int x: op) cout << x << " "; cout << endl;
}
