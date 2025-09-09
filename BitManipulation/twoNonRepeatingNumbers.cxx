Problem Description
Given an array in which all numbers except two are repeated once. (i.e. we have 2k+2 numbers and k numbers are occurring twice and remaining two have occurred once).
Find those two numbers in the most efficient way. Return the two numbers in a sorted manner.

Input format
First line of input contains N which denotes the number of elements in the input array.

The next line of input contains N space separated integers.

Output format
Return the two numbers which are present only once in the array in a sorted manner(i.e smaller number first).

Sample Input 1
8

2 3 7 9 11 2 3 11

Sample Output 1
7 9

Explanation
All numbers except 7 and 9 are repeated once.


vector<int> twoNonRepeatingNumbers(int arr[], int n){
    int xor1 = 0;
    for(int ele : arr)
    {
        
    }
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    vector<int>ans=twoNonRepeatingNumbers(arr,n);
    cout<<ans[0]<<" "<<ans[1];

}
