#include <bits/stdc++.h>
using namespace std;

// Brute Force - Recursive
bool bruteForce(int i, int j, string& s1, string& s2) {
    if (i < 0 && j < 0) return true;
    if (i < 0 && j >= 0) return false;
    if (j < 0 && i >= 0) {
        for (int k = 0; k <= i; k++) {
            if (s1[k] != '*') return false;
        }
        return true;
    }
    
    if (s1[i] == s2[j] || s1[i] == '?') {
        return bruteForce(i - 1, j - 1, s1, s2);
    }
    
    if (s1[i] == '*') {
        return bruteForce(i - 1, j, s1, s2) || bruteForce(i, j - 1, s1, s2);
    }
    
    return false;
}

// Optimal - Tabulation
bool optimal(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int k = 1; k <= i; k++) {
            if (s1[k - 1] != '*') {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (s1[i - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            } else {
                dp[i][j] = false;
            }
        }
    }
    
    return dp[n][m];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    cout << "Brute Force: " << (bruteForce(s1.size() - 1, s2.size() - 1, s1, s2) ? "true" : "false") << endl;
    cout << "Optimal: " << (optimal(s1, s2) ? "true" : "false") << endl;
    
    return 0;
}
