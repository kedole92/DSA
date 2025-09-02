Problem Description
A peak element is an element that is strictly greater than its neighbors. Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks. You may imagine that nums[-1] = nums[n] = -∞. You must write an algorithm that runs in O(log n) time.

Input format
The first line contains an integer N, the size of the input array. The second line contains N integers, the elements of the given array.

Output format
Return a single integer, the index of the peak element in the array (0-based).

Sample Input 1
4
1 2 3 1

Sample Output 1
2

Explanation
3 is a peak element and your function should return the index number 2.

int peakElement(vector<int>&nums){
      int left=0, right=nums.size();

      while(left <= right)
      {
            int mid = (left+right)/2;

            int lval = (mid==0) ? INT_MIN : nums[mid-1];

            int rval = (mid == nums.size()-1) ? INT_MIN : nums[mid+1];

            if(nums[mid] > lval && nums[mid] > rval)
            {
                  return mid;
            } 
            else if(nums[mid] < lval)
            {
                  right = mid - 1;
            }
            else
            {
                  left = mid+1;
            }
      }
      return 0;
}

int main(){
    int N;
    cin>>N;
    vector<int>nums(N);
    for(auto &x:nums)cin>>x;
    cout<<peakElement(nums)<<"\n";
}
