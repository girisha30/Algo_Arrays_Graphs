#include <bits/stdc++.h>
using namespace std;

// Brute Force: generate all permutations (not practical, just demo)
vector<int> nextPermBrute(vector<int> a) {
    vector<int> b=a;
    sort(b.begin(),b.end());
    do {
        if(b==a) {
            if(next_permutation(b.begin(),b.end())) return b;
            else return vector<int>(a.begin(),a.end()); // last perm -> return sorted
        }
    } while(next_permutation(b.begin(),b.end()));
    return a;
}

// Optimal: STL next_permutation
vector<int> nextPermOptimal(vector<int> a) {
    if(!next_permutation(a.begin(),a.end())) sort(a.begin(),a.end());
    return a;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for(int i=0;i<n;i++) cin >> a[i];

    auto bf=nextPermBrute(a);
    auto op=nextPermOptimal(a);

    cout << "Next Permutation (Brute Force): ";
    for(int x:bf) cout << x << " "; cout << endl;

    cout << "Next Permutation (Optimal): ";
    for(int x:op) cout << x << " "; cout << endl;
}
