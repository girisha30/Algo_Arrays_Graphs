#include <bits/stdc++.h>
using namespace std;

// Brute Force: collect pos and neg separately, then merge
vector<int> rearrangeBrute(const vector<int>& a) {
    vector<int> pos,neg,res;
    for(int x:a) (x>=0?pos:neg).push_back(x);
    for(int i=0;i<pos.size();i++) {
        res.push_back(pos[i]);
        if(i<neg.size()) res.push_back(neg[i]);
    }
    return res;
}

// Optimal: two queues
vector<int> rearrangeOptimal(const vector<int>& a) {
    queue<int> pos,neg;
    for(int x:a) (x>=0?pos:neg).push(x);
    vector<int> res;
    while(!pos.empty() && !neg.empty()) {
        res.push_back(pos.front()); pos.pop();
        res.push_back(neg.front()); neg.pop();
    }
    return res;
}

int main() {
    int n;
    cout << "Enter size of array (even, equal pos & neg): ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements (mix of +ve/-ve): ";
    for(int i=0;i<n;i++) cin >> a[i];

    auto bf=rearrangeBrute(a);
    auto op=rearrangeOptimal(a);

    cout << "Rearranged (Brute Force): ";
    for(int x:bf) cout << x << " "; cout << endl;

    cout << "Rearranged (Optimal): ";
    for(int x:op) cout << x << " "; cout << endl;
}
