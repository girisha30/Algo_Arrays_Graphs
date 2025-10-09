#include <bits/stdc++.h>
using namespace std;

// Brute Force: use extra matrix
vector<vector<int>> rotateBrute(const vector<vector<int>>& mat) {
    int n=mat.size();
    vector<vector<int>> res(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            res[j][n-1-i]=mat[i][j];
    return res;
}

// Optimal: transpose + reverse rows
void rotateOptimal(vector<vector<int>>& mat) {
    int n=mat.size();
    for(int i=0;i<n;i++) for(int j=i;j<n;j++) swap(mat[i][j],mat[j][i]);
    for(int i=0;i<n;i++) reverse(mat[i].begin(), mat[i].end());
}

int main() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter matrix elements:\n";
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> mat[i][j];

    auto b=rotateBrute(mat);
    auto o=mat;
    rotateOptimal(o);

    cout << "After Brute Force:\n";
    for(auto &row:b){ for(int x:row) cout<<x<<" "; cout<<"\n"; }

    cout << "After Optimal:\n";
    for(auto &row:o){ for(int x:row) cout<<x<<" "; cout<<"\n"; }
}
