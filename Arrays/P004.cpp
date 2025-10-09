#include <bits/stdc++.h>
using namespace std;

// Brute Force (using set)
int bruteForce(vector<int>& arr) {
    set<int> st(arr.begin(), arr.end());
    int k = 0;
    for (int x: st) arr[k++] = x;
    return k;
}

// Optimal (two pointer)
int optimal(vector<int>& arr) {
    if (arr.empty()) return 0;
    int k=1;
    for (int i=1;i<arr.size();i++) {
        if (arr[i]!=arr[k-1]) arr[k++] = arr[i];
    }
    return k;
}

int main() {
    int n;
    cout << "Enter size of sorted array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i=0;i<n;i++) cin >> arr[i];

    vector<int> arr1=arr, arr2=arr;

    int k1 = bruteForce(arr1);
    cout << "After Brute Force, unique count = " << k1 << ", array: ";
    for (int i=0;i<k1;i++) cout << arr1[i] << " ";
    cout << endl;

    int k2 = optimal(arr2);
    cout << "After Optimal, unique count = " << k2 << ", array: ";
    for (int i=0;i<k2;i++) cout << arr2[i] << " ";
    cout << endl;
}
