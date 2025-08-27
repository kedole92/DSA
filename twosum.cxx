Problem Description:
Given an array of integers as input, output the indices of two numbers in the array which add up to a specified target.
Assume that each input would have exactly one solution and you cannot use the same element twice. If 2 different elements have the same value, they can be used.
Print the indices in increasing order.

Input format
First line contains an Integer N that represents the number of elements in the array.
Second line contains N space separated integers, which are members of the array.
Third line contains an integer X, which is the target value.

Output format
Print two space separated indices(in increasing order) of the numbers which add up to the specified target.

Constraints
2 <= Length of array <= 100000
1 <= Range of values <= 1000000

Sample Input 1
5 --> Number of elements in array
2 4 5 9 8 --> Array elements
7 --> Target sum value

Sample Output 1
0 2

Explanation 1
Since 0 and 2 are the indices where the numbers 2 and 5 which add up to 7 are seen


class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //create a map of int,int to store the key as array element and value as index of that element
        map<int, int> hm;
        vector<int> returnVector;

        //run a loop over all elements from the given array
        for(int j=0; j<nums.size(); j++)
        {
            //calculate the ith index by subtacting
            int x = target - nums[j];

            //find in map if the i is present. if yes then return the elements
            if( hm.find(x) != hm.end())
            {
                //find the index of x
                int idx1 = hm[x];
                int idx2 = j;

                returnVector.push_back(idx1);
                returnVector.push_back(idx2);
                return returnVector;
            }
            hm[nums[j]] =j;
        }
        return returnVector;
    }
};

int main() {
    FastIO();
    int n, target;
    cin >> n;
    vector<int> nums;
    ReadMatrix<int>().OneDMatrix(n, nums);
    cin >> target;
    vector<int> result = TwoSum().twoSum(nums, target);
    PrintMatrix<int>().OneDMatrix(result, " ");
    return 0;
}
