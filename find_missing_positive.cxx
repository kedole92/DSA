Problem Description
Given an unsorted array of integers, find the smallest missing positive integer. The space complexity need not be O(1), you can also implement a O(N) space complexity solution.

Input format
There are 2 lines of input.
First line contains 1 integer N - Number of elements in the array.
Second line contains space separated N integers.

Output format
Print the smallest missing positive integer.

Sample Input 1
4
3 4 -1 1
Sample Output 1
2

Explanation 1
2 is the smallest positive integer which is missing as 1 is already present in the array. Note that 0 will not be considered as positive.

Constraints
N <= 200000
-2 ^ 31 <= Range of values <= 2 ^ 31 - 1

class FirstMissingPositive {
  public:
    int firstMissingPositive(vector<int> nums) {
        //create a hash set to store all the values from nums
       set<int> visited;

       //run a loop over nums and add all values into set
       for(int idx = 0; idx<nums.size(); idx++)
       {
            //insert the value in set
            visited.insert(nums[idx]);
       }

        for(int idx = 1; idx<=nums.size(); idx++)
        {
            if(visited.contains(idx) == false)
            {
                return idx;
            }
        }
        return nums.size() + 1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    int result = FirstMissingPositive().firstMissingPositive(nums);
    cout << result;
    return 0;
}
