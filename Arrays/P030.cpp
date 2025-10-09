#include <bits/stdc++.h>
using namespace std;

// Brute Force: check all triplets
vector<vector<int>> threeSumBrute(vector<int> a) {
    int n=a.size();
    set<vector<int>> res;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]+a[j]+a[k]==0){
                    vector<int> trip={a[i],a[j],a[k]};
                    sort(trip.begin(),trip.end());
                    res.insert(trip);
                }
            }
        }
    }
    return vector<vector<int>>(res.begin(),res.end());
}

// Optimal: sort + two-pointer
vector<vector<int>> threeSumOptimal(vector<int> a) {
    vector<vector<int>> res;
    sort(a.begin(),a.end());
    int n=a.size();
    for(int i=0;i<n;i++){
        if(i>0 && a[i]==a[i-1]) continue;
        int l=i+1,r=n-1;
        while(l<r){
            int sum=a[i]+a[l]+a[r];
            if(sum==0){
                res.push_back({a[i],a[l],a[r]});
                while(l<r && a[l]==a[l+1]) l++;
                while(l<r && a[r]==a[r-1]) r--;
                l++; r--;
            } else if(sum<0) l++;
            else r--;
        }
    }
    return res;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for(int i=0;i<n;i++) cin >> a[i];

    auto bf=threeSumBrute(a);
    auto op=threeSumOptimal(a);

    cout << "Triplets (Brute Force):\n";
    for(auto& t:bf){ for(int x:t) cout<<x<<" "; cout<<"\n"; }

    cout << "Triplets (Optimal):\n";
    for(auto& t:op){ for(int x:t) cout<<x<<" "; cout<<"\n"; }
}
