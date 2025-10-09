#include <bits/stdc++.h>
using namespace std;

// Brute Force
bool bruteForce(const vector<int>& arr) {
    for (int i=0;i<arr.size();i++) {
        for (int j=i+1;j<arr.size();j++) {
            if (arr[i] > arr[j]) return false;
        }
    }
    return true;
}

// Optimal
bool optimal(const vector<int>& arr) {
    for (int i=1;i<arr.size();i++) {
        if (arr[i] < arr[i-1]) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i=0;i<n;i++) cin >> arr[i];

    cout << "Is Sorted (Brute Force): " << (bruteForce(arr) ? "Yes" : "No") << endl;
    cout << "Is Sorted (Optimal): " << (optimal(arr) ? "Yes" : "No") << endl;
}
