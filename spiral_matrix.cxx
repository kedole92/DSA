<TODO-- Add the problem description>


#include <bits/stdc++.h>
using namespace std;

bool conditionFail(pair<int, int > &pos, vector<vector<int>> &matrix, int &n){
    int x = pos.first, y = pos.second;
    if(x >= n || x < 0 || y >= n || y < 0)
        return true;
    if (matrix[x][y] != 0)
        return true;
    return false;
}

vector<vector<int > > spiralMatrixII(int n){
    //create a result matrix of n rows and n columns
    vector<vector<int>> arr(n,vector<int>(n));
    vector<int> intermediate_matrix;

    int val=1;

    int firstRow=0; int firstCol=0; int lastRow = n-1; int lastCol = n-1;

    for(int col=0; col<=lastCol; col++)
    {
        intermediate_matrix.push_back(val);
    }
    arr.push_back(intermediate_matrix);
    

}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > result = spiralMatrixII(n);
    for(auto &row: result){
        for(auto &element: row){
            cout<<element<<" ";
        }
        cout<<"\n";
    } 
}
