#include <bits/stdc++.h>
using namespace std;

// Brute Force: check all subarrays
int largestZeroSubBrute(const vector<int>& a) {
    int n=a.size(), best=0;
    for(int i=0;i<n;i++) {
        int sum=0;
        for(int j=i;j<n;j++) {
            sum+=a[j];
            if(sum==0) best=max(best,j-i+1);
        }
    }
    return best;
}

// Optimal: prefix sum + hashmap
int largestZeroSubOptimal(const vector<int>& a) {
    unordered_map<int,int> firstOccur;
    int sum=0, best=0;
    for(int i=0;i<a.size();i++) {
        sum+=a[i];
        if(sum==0) best=max(best,i+1);
        if(firstOccur.count(sum)) best=max(best,i-firstOccur[sum]);
        else firstOccur[sum]=i;
    }
    return best;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements (+/-): ";
    for(int i=0;i<n;i++) cin >> a[i];

    cout << "Largest Zero-Sum Subarray Length (Brute Force): " << largestZeroSubBrute(a) << endl;
    cout << "Largest Zero-Sum Subarray Length (Optimal): " << largestZeroSubOptimal(a) << endl;
}
