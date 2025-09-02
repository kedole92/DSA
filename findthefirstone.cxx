Problem Description:
Given a sorted array consisting of 0s and 1s only, find the index of the first 1. If there’s no 1 present in the array, return -1

Input format
There are 2 lines of input
First line will contain a single integer n.
Next line will contain n space separated integers.

Output format
Print the index of first occuring if present, otherwise print -1.

Sample Input 1
4
0 0 1 1

Sample Output 1
2

int zeroOnes(int n, vector<int > arr){
    int s = 0;
    int e = n-1;
    int ans = -1;

    while(s<=e)
    {
        int mid = (s+e)/2;

        if(arr[mid] == 0)
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
            ans = mid;
        }
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int > arr(n);
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    int result = zeroOnes(n, arr);
    cout << result << "\n";
}
