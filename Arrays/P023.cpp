#include <bits/stdc++.h>
using namespace std;

// Brute Force
int kadaneBrute(const vector<int>& a) {
    int n=a.size();
    int best=INT_MIN;
    for(int i=0;i<n;i++) {
        int sum=0;
        for(int j=i;j<n;j++) {
            sum+=a[j];
            best=max(best,sum);
        }
    }
    return best;
}

// Optimal
int kadaneOptimal(const vector<int>& a) {
    int cur=a[0],best=a[0];
    for(int i=1;i<a.size();i++) {
        cur=max(a[i],cur+a[i]);
        best=max(best,cur);
    }
    return best;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for(int i=0;i<n;i++) cin >> a[i];

    cout << "Maximum Subarray Sum (Brute Force): " << kadaneBrute(a) << endl;
    cout << "Maximum Subarray Sum (Optimal): " << kadaneOptimal(a) << endl;
}
