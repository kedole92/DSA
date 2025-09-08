Problem Description
Given nxn matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Input format
First line contains two integers. N, denoting the size of the square matrix and K where we have to find the Kth Smallest element.

Next N lines contain N integers each denoting the elements of the matrix.

Output format
Single containing one integer denoting the Kth smallest element.

Sample Input 1
3 8
1 5 9
10 11 13
12 13 15

Sample Output 1
13

Explanation 1
If written in non-decreasing order, elements are,
1 5 9 10 11 12 13 13 15
Hence, 8th smallest element is 13.



int kthSmallestElementInMatrix(vector<vector<int>> matrix,int k)
{
        int n = matrix.size();

        // Create a vector to store all elements
        vector<int> arr;

        // Store all elements of the matrix into the array
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                arr.push_back(matrix[i][j]);
            }
        }

        // Sort the array
        sort(arr.begin(), arr.end());

        // Return the kth smallest element 
        // (0-based index, hence k-1)
        return arr[k - 1];
}

int main()
{
    int n,k;cin>>n>>k;

    vector<vector<int> > matrix(n);
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            int x;cin>>x;
            matrix[i].push_back(x);
        }
    }
    int ans = kthSmallestElementInMatrix(matrix,k);
    cout<<ans<<endl;
}
