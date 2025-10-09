#include <bits/stdc++.h>
using namespace std;

// Brute Force: for each number, check forward
int longestConsecBrute(vector<int>& a) {
    sort(a.begin(), a.end());
    int longest = 1, cur = 1;
    for (int i=1;i<a.size();i++) {
        if (a[i] == a[i-1]+1) {
            cur++;
        } else if (a[i] != a[i-1]) {
            cur = 1;
        }
        longest = max(longest, cur);
    }
    return longest;
}

// Optimal: use set for O(n)
int longestConsecOptimal(const vector<int>& a) {
    unordered_set<int> s(a.begin(), a.end());
    int best = 0;
    for (int num : a) {
        if (!s.count(num-1)) {
            int cur = num, streak = 1;
            while (s.count(cur+1)) { cur++; streak++; }
            best = max(best, streak);
        }
    }
    return best;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for (int i=0;i<n;i++) cin >> a[i];

    cout << "Longest Consecutive Sequence (Brute Force): " << longestConsecBrute(a) << endl;
    cout << "Longest Consecutive Sequence (Optimal): " << longestConsecOptimal(a) << endl;
}
