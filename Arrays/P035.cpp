#include <bits/stdc++.h>
using namespace std;

// Brute Force: check all subarrays
int countXorBrute(const vector<int>& a, int k) {
    int n=a.size(), cnt=0;
    for(int i=0;i<n;i++) {
        int xo=0;
        for(int j=i;j<n;j++) {
            xo ^= a[j];
            if(xo==k) cnt++;
        }
    }
    return cnt;
}

// Optimal: prefix xor + hashmap
int countXorOptimal(const vector<int>& a, int k) {
    unordered_map<int,int> freq;
    freq[0]=1;
    int xo=0, cnt=0;
    for(int v:a) {
        xo ^= v;
        if(freq.count(xo^k)) cnt+=freq[xo^k];
        freq[xo]++;
    }
    return cnt;
}

int main() {
    int n,k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for(int i=0;i<n;i++) cin >> a[i];
    cout << "Enter target XOR value: ";
    cin >> k;

    cout << "Count of Subarrays (Brute Force): " << countXorBrute(a,k) << endl;
    cout << "Count of Subarrays (Optimal): " << countXorOptimal(a,k) << endl;
}
