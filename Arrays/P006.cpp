#include <bits/stdc++.h>
using namespace std;

// Brute Force: use extra vector
void moveZerosBrute(vector<int>& a) {
    vector<int> nonz; 
    int zeroCount = 0;
    for (int x : a) {
        if (x == 0) zeroCount++;
        else nonz.push_back(x);
    }
    a = nonz;
    a.insert(a.end(), zeroCount, 0);
}

// Optimal: two-pointer (in-place)
void moveZerosOptimal(vector<int>& a) {
    int k = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] != 0) a[k++] = a[i];
    }
    while (k < (int)a.size()) a[k++] = 0;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for (int i=0;i<n;i++) cin >> a[i];

    vector<int> b = a, c = a;
    moveZerosBrute(b);
    moveZerosOptimal(c);

    cout << "After Brute Force (zeros moved): ";
    for (int x: b) cout << x << " ";
    cout << endl;

    cout << "After Optimal (zeros moved): ";
    for (int x: c) cout << x << " ";
    cout << endl;
}
