#include <bits/stdc++.h>
using namespace std;

// Brute Force: just sort
void sortBrute(vector<int>& a) {
    sort(a.begin(),a.end());
}

// Optimal
void sortOptimal(vector<int>& a) {
    int low=0,mid=0,high=a.size()-1;
    while(mid<=high) {
        if(a[mid]==0) swap(a[low++],a[mid++]);
        else if(a[mid]==1) mid++;
        else swap(a[mid],a[high--]);
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements (only 0/1/2): ";
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> b=a,c=a;
    sortBrute(b);
    sortOptimal(c);

    cout << "Sorted (Brute Force): ";
    for(int x:b) cout << x << " "; cout << endl;

    cout << "Sorted (Optimal): ";
    for(int x:c) cout << x << " "; cout << endl;
}
