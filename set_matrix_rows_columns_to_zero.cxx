Problem Description
Given an m x n matrix, if an element is 0, set its entire row and column to 0.
Do it in-place, that is, modify the same matrix. Do not create a new one.

Input format
First line contains 2 integers m,n - number of rows and columns respectively.
Next m lines contain space separated n integers.

Output format
Output the same matrix.

Sample Input 1
3 3

1 1 1
1 0 1
1 1 1

Sample Output 1
1 0 1
0 0 0
1 0 1

Explanation 1
There is one ‘0’ in the 2nd row and 2nd column, so all the elements in that row and column become 0.

class SetMatrixZeroes {
  public:

    void setMatrixZeroes(vector<vector<int>>& matrix) {
        //declare 2 variables m and n as rows and columns
        int m=matrix.size(), n=matrix[0].size();

        //create 2 boolean vectors to store tru false values on occurent of 0
        vector<bool> rows(m);
        vector<bool> cols(n);

        //run a loop over matrix rows and colums
        for(int r=0; r<m; r++)
        {
            for(int c=0; c<n; c++)
            {
                //check if the value at  m and n is 0
                if(matrix[r][c] == 0)
                {
                    //if true then set the value of that row and col vecor as true
                    rows[r] = cols[c] = true;
                }
            }
        }

        //run a for loop again to make the actual matrix value as 0
        for(int r=0; r<m; r++)
        {
            for(int c=0; c<n; c++)
            {
                //check if the alues are true, if yes then make changes in original matrix
                if(rows[r] == true || cols[c] == true)
                {
                    matrix[r][c] = 0;
                }
            }
        }

    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m,vector<int> (n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
        cout<<"\n";
    }
    SetMatrixZeroes().setMatrixZeroes(grid);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
