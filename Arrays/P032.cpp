#include <bits/stdc++.h>
using namespace std;

// Brute Force: sort + merge with set
vector<vector<int>> mergeBrute(vector<vector<int>> intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    vector<bool> used(intervals.size(), false);
    for(int i=0;i<intervals.size();i++) {
        if(used[i]) continue;
        int start=intervals[i][0], end=intervals[i][1];
        for(int j=i+1;j<intervals.size();j++) {
            if(intervals[j][0]<=end) {
                end=max(end, intervals[j][1]);
                used[j]=true;
            }
        }
        res.push_back({start,end});
    }
    return res;
}

// Optimal: sort + linear merge
vector<vector<int>> mergeOptimal(vector<vector<int>> intervals) {
    if(intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++) {
        if(intervals[i][0]<=res.back()[1]) res.back()[1]=max(res.back()[1],intervals[i][1]);
        else res.push_back(intervals[i]);
    }
    return res;
}

int main() {
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;
    vector<vector<int>> intervals(n,vector<int>(2));
    cout << "Enter " << n << " intervals (start end):\n";
    for(int i=0;i<n;i++) cin >> intervals[i][0] >> intervals[i][1];

    auto bf=mergeBrute(intervals);
    auto op=mergeOptimal(intervals);

    cout << "Merged Intervals (Brute Force): ";
    for(auto &v:bf) cout<<"["<<v[0]<<","<<v[1]<<"] ";
    cout<<endl;

    cout << "Merged Intervals (Optimal): ";
    for(auto &v:op) cout<<"["<<v[0]<<","<<v[1]<<"] ";
    cout<<endl;
}
