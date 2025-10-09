#include <bits/stdc++.h>
using namespace std;

// Brute Force: mark rows/cols separately, then set zeros
void setZeroesBrute(vector<vector<int>>& mat) {
    int m=mat.size(), n=mat[0].size();
    vector<int> rows, cols;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){ rows.push_back(i); cols.push_back(j); }
        }
    }
    for(int r:rows) for(int j=0;j<n;j++) mat[r][j]=0;
    for(int c:cols) for(int i=0;i<m;i++) mat[i][c]=0;
}

// Optimal: use first row/col as markers
void setZeroesOptimal(vector<vector<int>>& mat) {
    int m=mat.size(), n=mat[0].size();
    bool firstRow=false, firstCol=false;

    for(int i=0;i<m;i++) if(mat[i][0]==0) firstCol=true;
    for(int j=0;j<n;j++) if(mat[0][j]==0) firstRow=true;

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(mat[i][j]==0){ mat[i][0]=0; mat[0][j]=0; }
        }
    }

    for(int i=1;i<m;i++) if(mat[i][0]==0) for(int j=1;j<n;j++) mat[i][j]=0;
    for(int j=1;j<n;j++) if(mat[0][j]==0) for(int i=1;i<m;i++) mat[i][j]=0;

    if(firstRow) for(int j=0;j<n;j++) mat[0][j]=0;
    if(firstCol) for(int i=0;i<m;i++) mat[i][0]=0;
}

int main() {
    int m,n;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter matrix elements: \n";
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin >> mat[i][j];

    auto b=mat, o=mat;
    setZeroesBrute(b);
    setZeroesOptimal(o);

    cout << "After Brute Force:\n";
    for(auto &row:b){ for(int x:row) cout<<x<<" "; cout<<"\n"; }

    cout << "After Optimal:\n";
    for(auto &row:o){ for(int x:row) cout<<x<<" "; cout<<"\n"; }
}
