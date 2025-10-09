#include <bits/stdc++.h>
using namespace std;

// Brute Force: check all quadruplets
vector<vector<int>> fourSumBrute(vector<int> a, int target) {
    int n=a.size();
    set<vector<int>> res;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
                for(int l=k+1;l<n;l++)
                    if(a[i]+a[j]+a[k]+a[l]==target) {
                        vector<int> quad={a[i],a[j],a[k],a[l]};
                        sort(quad.begin(),quad.end());
                        res.insert(quad);
                    }
    return vector<vector<int>>(res.begin(),res.end());
}

// Optimal: sort + 2 pointers
vector<vector<int>> fourSumOptimal(vector<int> a, int target) {
    vector<vector<int>> res;
    sort(a.begin(),a.end());
    int n=a.size();
    for(int i=0;i<n;i++) {
        if(i>0 && a[i]==a[i-1]) continue;
        for(int j=i+1;j<n;j++) {
            if(j>i+1 && a[j]==a[j-1]) continue;
            long long newTarget=(long long)target - a[i] - a[j];
            int l=j+1,r=n-1;
            while(l<r) {
                long long sum=a[l]+a[r];
                if(sum==newTarget) {
                    res.push_back({a[i],a[j],a[l],a[r]});
                    while(l<r && a[l]==a[l+1]) l++;
                    while(l<r && a[r]==a[r-1]) r--;
                    l++; r--;
                } else if(sum<newTarget) l++;
                else r--;
            }
        }
    }
    return res;
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

    auto bf=fourSumBrute(a,target);
    auto op=fourSumOptimal(a,target);

    cout << "Quadruplets (Brute Force):\n";
    for(auto& v:bf){ for(int x:v) cout<<x<<" "; cout<<"\n"; }

    cout << "Quadruplets (Optimal):\n";
    for(auto& v:op){ for(int x:v) cout<<x<<" "; cout<<"\n"; }
}
