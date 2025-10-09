#include <bits/stdc++.h>
using namespace std;

// Brute Force: count frequency
vector<int> majorityBrute(const vector<int>& a) {
    unordered_map<int,int> freq;
    for(int v:a) freq[v]++;
    vector<int> res;
    for(auto&p:freq) if(p.second>(int)a.size()/3) res.push_back(p.first);
    return res;
}

// Optimal: Extended Boyer-Moore
vector<int> majorityOptimal(const vector<int>& a) {
    int cand1=0,cand2=0,count1=0,count2=0;
    for(int v:a){
        if(v==cand1) count1++;
        else if(v==cand2) count2++;
        else if(count1==0){ cand1=v; count1=1; }
        else if(count2==0){ cand2=v; count2=1; }
        else{ count1--; count2--; }
    }
    count1=count2=0;
    for(int v:a){ if(v==cand1) count1++; else if(v==cand2) count2++; }
    vector<int> res;
    if(count1>(int)a.size()/3) res.push_back(cand1);
    if(count2>(int)a.size()/3) res.push_back(cand2);
    return res;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for(int i=0;i<n;i++) cin >> a[i];

    auto bf=majorityBrute(a);
    auto op=majorityOptimal(a);

    cout << "Majority Elements (Brute Force): ";
    for(int x:bf) cout<<x<<" "; cout<<endl;

    cout << "Majority Elements (Optimal): ";
    for(int x:op) cout<<x<<" "; cout<<endl;
}
