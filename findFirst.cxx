Problem Description
Given an array of integers of length n sorted in ascending order and Q number of queries, for each query you have to find the first and last position (0-based indexed) of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

Input format
First line has an integer denoting the size of array (n)
Second line contains n space separated integers denoting the array(nums).
Third line contains an integer representing the value of Q.
In the next Q lines, each line will contain an integer K (target value).

Output format
Two integers representing the first and last position of the target value from the corresponding query given in the input.


class Solution {

    public:

        static int findFirst(vector<int>& nums, int target)
        {
            int first = -1;
            int low = 0, high = nums.size()-1;

            while(low <= high)
            {
                int mid = (low + high)/2;

                if(target == nums[mid])
                {
                    first = mid;
                    high = mid - 1;
                }
                else if(target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return first;
        }

        static int findLast(vector<int>& nums, int target)
        {
            int last = -1;
            int low = 0, high = nums.size()-1;

            while(low <= high)
            {
                int mid = (low + high)/2;

                if(target == nums[mid])
                {
                    last = mid;
                    low = low + 1;
                }
                else if(target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return last;
        }

        vector<int> findFirstAndLastPositionOfElementInSortedArray(vector<int> &nums, int target) {
        	
            int first = findFirst(nums, target);
            int last = findLast(nums, target);

            vector<int> result = {first, last};
            
            return result;
        }
};
