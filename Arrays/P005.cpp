#include <bits/stdc++.h>
using namespace std;

// Brute Force
void bruteForce(vector<int>& arr) {
    if(arr.empty()) return;
    int first = arr[0];
    arr.erase(arr.begin());
    arr.push_back(first);
}

// Optimal
void optimal(vector<int>& arr) {
    if(arr.empty()) return;
    rotate(arr.begin(), arr.begin()+1, arr.end());
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i=0;i<n;i++) cin >> arr[i];

    vector<int> arr1=arr, arr2=arr;

    bruteForce(arr1);
    cout << "After Brute Force rotation: ";
    for (int x: arr1) cout << x << " ";
    cout << endl;

    optimal(arr2);
    cout << "After Optimal rotation: ";
    for (int x: arr2) cout << x << " ";
    cout << endl;
}
