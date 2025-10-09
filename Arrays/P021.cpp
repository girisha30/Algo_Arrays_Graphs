#include <bits/stdc++.h>
using namespace std;

// Brute Force: check all pairs
pair<int,int> twoSumBrute(const vector<int>& a, int target) {
    int n=a.size();
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(a[i]+a[j]==target) return {i,j};
        }
    }
    return {-1,-1};
}

// Optimal: hashmap
pair<int,int> twoSumOptimal(const vector<int>& a, int target) {
    unordered_map<int,int> mp;
    for(int i=0;i<a.size();i++) {
        int need = target - a[i];
        if(mp.count(need)) return {mp[need],i};
        mp[a[i]]=i;
    }
    return {-1,-1};
}

int main() {
    int n,target;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for(int i=0;i<n;i++) cin >> a[i];

    cout << "Enter target sum: ";
    cin >> target;

    auto bf = twoSumBrute(a,target);
    auto op = twoSumOptimal(a,target);

    cout << "Two Sum Indices (Brute Force): " << bf.first << " " << bf.second << endl;
    cout << "Two Sum Indices (Optimal): " << op.first << " " << op.second << endl;
}
