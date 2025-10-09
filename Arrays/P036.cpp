#include <bits/stdc++.h>
using namespace std;

// Brute Force: check all substrings
int longestSubBrute(const string& s) {
    int n=s.size(), best=0;
    for(int i=0;i<n;i++) {
        set<char> st;
        for(int j=i;j<n;j++) {
            if(st.count(s[j])) break;
            st.insert(s[j]);
            best=max(best,j-i+1);
        }
    }
    return best;
}

// Optimal: sliding window + hashmap
int longestSubOptimal(const string& s) {
    vector<int> last(256,-1);
    int left=0,best=0;
    for(int right=0; right<s.size(); right++) {
        if(last[s[right]]>=left) left=last[s[right]]+1;
        last[s[right]]=right;
        best=max(best,right-left+1);
    }
    return best;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "Longest Substring Length (Brute Force): " << longestSubBrute(s) << endl;
    cout << "Longest Substring Length (Optimal): " << longestSubOptimal(s) << endl;
}
