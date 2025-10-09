#include <bits/stdc++.h>
using namespace std;

// Brute Force
int reversePairsBrute(const vector<int>& a) {
    int cnt=0;
    for(int i=0;i<a.size();i++)
        for(int j=i+1;j<a.size();j++)
            if((long long)a[i] > 2LL*a[j]) cnt++;
    return cnt;
}

// Optimal: merge sort trick
int mergeAndCount(vector<int>& a,int l,int m,int r){
    int cnt=0;
    int j=m+1;
    for(int i=l;i<=m;i++){
        while(j<=r && (long long)a[i]>2LL*a[j]) j++;
        cnt+=j-(m+1);
    }
    vector<int> tmp;
    int i=l; j=m+1;
    while(i<=m && j<=r){
        if(a[i]<=a[j]) tmp.push_back(a[i++]);
        else tmp.push_back(a[j++]);
    }
    while(i<=m) tmp.push_back(a[i++]);
    while(j<=r) tmp.push_back(a[j++]);
    for(int k=l;k<=r;k++) a[k]=tmp[k-l];
    return cnt;
}

int countRevOptimal(vector<int>& a,int l,int r){
    if(l>=r) return 0;
    int m=(l+r)/2;
    int cnt=0;
    cnt+=countRevOptimal(a,l,m);
    cnt+=countRevOptimal(a,m+1,r);
    cnt+=mergeAndCount(a,l,m,r);
    return cnt;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> b=a;
    cout << "Reverse Pairs (Brute Force): " << reversePairsBrute(a) << endl;
    cout << "Reverse Pairs (Optimal): " << countRevOptimal(b,0,n-1) << endl;
}
