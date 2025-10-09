#include <bits/stdc++.h>
using namespace std;

// Brute Force
pair<int,int> bruteForce(const vector<int>& arr) {
    set<int> st(arr.begin(), arr.end());
    if (st.size() < 2) return {-1,-1};
    auto it = st.begin(); advance(it,1);
    int secondSmallest = *it;
    it = st.end(); advance(it,-2);
    int secondLargest = *it;
    return {secondSmallest, secondLargest};
}

// Optimal
pair<int,int> optimal(const vector<int>& arr) {
    int n = arr.size();
    if (n < 2) return {-1,-1};
    int smallest = INT_MAX, secondSmall = INT_MAX;
    int largest = INT_MIN, secondLarge = INT_MIN;

    for (int num: arr) {
        if (num < smallest) { secondSmall = smallest; smallest = num; }
        else if (num < secondSmall && num != smallest) secondSmall = num;

        if (num > largest) { secondLarge = largest; largest = num; }
        else if (num > secondLarge && num != largest) secondLarge = num;
    }
    if (secondSmall == INT_MAX) secondSmall = -1;
    if (secondLarge == INT_MIN) secondLarge = -1;
    return {secondSmall, secondLarge};
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter " << n << " elements: ";
    for (int i=0;i<n;i++) cin >> arr[i];

    auto bf = bruteForce(arr);
    auto op = optimal(arr);

    cout << "Brute Force -> Second Smallest: " << bf.first << " Second Largest: " << bf.second << endl;
    cout << "Optimal     -> Second Smallest: " << op.first << " Second Largest: " << op.second << endl;
}
