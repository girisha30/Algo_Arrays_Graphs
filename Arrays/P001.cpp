#include <bits/stdc++.h>
using namespace std;

// Brute Force
int largestBruteForce(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        bool isLargest = true;
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] > arr[i]) {
                isLargest = false;
                break;
            }
        }
        if (isLargest) return arr[i];
    }
    return -1;
}

// Optimal
int largestOptimal(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Largest element (Brute Force): " << largestBruteForce(arr) << endl;
    cout << "Largest element (Optimal): " << largestOptimal(arr) << endl;
}
