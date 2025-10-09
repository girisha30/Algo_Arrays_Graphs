#include <bits/stdc++.h>
using namespace std;

// Brute Force
int linearSearchBrute(const vector<int>& a, int target) {
    for (int i = 0; i < (int)a.size(); i++)
        if (a[i] == target) return i;
    return -1;
}

// Optimal (STL find)
int linearSearchOptimal(const vector<int>& a, int target) {
    auto it = find(a.begin(), a.end(), target);
    if (it == a.end()) return -1;
    return int(it - a.begin());
}

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for (int i=0;i<n;i++) cin >> a[i];

    cout << "Enter target element to search: ";
    cin >> target;

    cout << "Index (Brute Force): " << linearSearchBrute(a, target) << endl;
    cout << "Index (Optimal): " << linearSearchOptimal(a, target) << endl;
}
