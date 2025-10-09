#include <bits/stdc++.h>
using namespace std;

// Brute Force & Optimal are same here
vector<int> spiralOrder(const vector<vector<int>>& mat) {
    int m=mat.size(), n=mat[0].size();
    int top=0, bottom=m-1, left=0, right=n-1;
    vector<int> res;
    while(top<=bottom && left<=right){
        for(int j=left;j<=right;j++) res.push_back(mat[top][j]);
        top++;
        for(int i=top;i<=bottom;i++) res.push_back(mat[i][right]);
        right--;
        if(top<=bottom){
            for(int j=right;j>=left;j--) res.push_back(mat[bottom][j]);
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--) res.push_back(mat[i][left]);
            left++;
        }
    }
    return res;
}

int main() {
    int m,n;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter matrix elements:\n";
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin >> mat[i][j];

    auto res=spiralOrder(mat);
    cout << "Spiral Order: ";
    for(int x:res) cout<<x<<" ";
    cout<<endl;
}
