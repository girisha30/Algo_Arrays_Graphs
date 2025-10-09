#include <bits/stdc++.h>
using namespace std;

// Brute Force: merge then sort
vector<int> mergeBrute(vector<int> a, vector<int> b) {
    vector<int> res=a;
    res.insert(res.end(), b.begin(), b.end());
    sort(res.begin(),res.end());
    return res;
}

// Optimal: Gap method (Shell sort style)
void mergeOptimal(vector<int>& a, vector<int>& b) {
    int n=a.size(), m=b.size();
    int gap=(n+m+1)/2;
    auto nextGap=[&](int g){ return (g<=1)?0:(g+1)/2; };

    while(gap>0) {
        int i=0, j=gap;
        while(j<n+m) {
            int val1=(i<n)?a[i]:b[i-n];
            int val2=(j<n)?a[j]:b[j-n];
            if(val1>val2) {
                if(i<n && j<n) swap(a[i],a[j]);
                else if(i<n) swap(a[i],b[j-n]);
                else swap(b[i-n],b[j-n]);
            }
            i++; j++;
        }
        gap=nextGap(gap);
    }
}

int main() {
    int n,m;
    cout << "Enter size of first array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " sorted elements: ";
    for(int i=0;i<n;i++) cin >> a[i];

    cout << "Enter size of second array: ";
    cin >> m;
    vector<int> b(m);
    cout << "Enter " << m << " sorted elements: ";
    for(int i=0;i<m;i++) cin >> b[i];

    auto bf=mergeBrute(a,b);
    cout << "Merged (Brute Force): ";
    for(int x:bf) cout<<x<<" "; cout<<endl;

    mergeOptimal(a,b);
    cout << "Merged (Optimal): ";
    for(int x:a) cout<<x<<" ";
    for(int x:b) cout<<x<<" ";
    cout<<endl;
}
