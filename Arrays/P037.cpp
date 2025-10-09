#include <bits/stdc++.h>
using namespace std;

// Brute Force: check all pairs
long long countInvBrute(const vector<int>& a) {
    long long cnt=0;
    for(int i=0;i<a.size();i++)
        for(int j=i+1;j<a.size();j++)
            if(a[i]>a[j]) cnt++;
    return cnt;
}

// Optimal: merge sort method
long long mergeAndCount(vector<int>& a,int l,int m,int r){
    vector<int> left(a.begin()+l,a.begin()+m+1);
    vector<int> right(a.begin()+m+1,a.begin()+r+1);
    int i=0,j=0,k=l;
    long long cnt=0;
    while(i<left.size() && j<right.size()){
        if(left[i]<=right[j]) a[k++]=left[i++];
        else{ a[k++]=right[j++]; cnt += left.size()-i; }
    }
    while(i<left.size()) a[k++]=left[i++];
    while(j<right.size()) a[k++]=right[j++];
    return cnt;
}

long long countInvOptimal(vector<int>& a,int l,int r){
    if(l>=r) return 0;
    int m=(l+r)/2;
    long long cnt=0;
    cnt+=countInvOptimal(a,l,m);
    cnt+=countInvOptimal(a,m+1,r);
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
    cout << "Inversion Count (Brute Force): " << countInvBrute(a) << endl;
    cout << "Inversion Count (Optimal): " << countInvOptimal(b,0,n-1) << endl;
}
