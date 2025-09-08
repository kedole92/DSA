Problem Description
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Input format
The first line of input contains N, which denotes the number of elements in the array.
The next line of input contains N distinct array elements in the range [0, n].

Output format
Return the only number in the range that is missing from the array.

Sample Input 1
4
3 0 2 4

Sample Output 1
1

Explanation
n = 4 since there are 4 numbers, so all numbers are in the range [0,4].
1 is the missing number in the range since it does not appear in nums.


int singleMissingNumber(vector<int>nums, int n){
    int ans = 0;
    for(int i=0; i<=n; i++)
    {
        ans = ans ^ i;
    }
    for(int i=0; i<n; i++)
    {
        ans = ans ^ nums[i];
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<singleMissingNumber(nums,n);

}
