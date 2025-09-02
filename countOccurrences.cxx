Problem Description
Given a sorted integer array of length n with possible duplicate elements. Find the number of occurrences of an integer k using binary search.

Input format
There are 2 lines of input.
First line contains 2 space separated integers n, k - Number of elements, the integer k.
Second line contains n space separated integers - The integer array.

Output format
Print the number of occurrences of the integer k.

Sample Input 1
5 2
-1 2 2 4 7

Sample Output 1
2

Explanation 1
The integer 2 occurs 2 times in the given array.

static int firstIndex (vector<int> nums, int k)
{
    int left = 0, right = nums.size()-1;

    while(left <= right)
    {
        int mid = (left + right)/2;

        if(nums[mid] == k)
        {
            right = mid - 1;
        }
        else if(nums[mid] < k)
        {
            left = mid + 1; 
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}


static int lastIndex (vector<int> nums, int k)
{
    int left = 0, right = nums.size()-1;

    while(left <= right)
    {
        int mid = (left + right)/2;

        if(nums[mid] == k)
        {
            left = mid + 1;
        }
        else if(nums[mid] < k)
        {
            left = mid + 1; 
        }
        else
        {
            right = mid - 1;
        }
    }
    return right;
}

int countOccurrences(int n, vector<int> &arr, int k){
    int first = firstIndex(arr, k);

    int last = lastIndex(arr, k);

    if(first > last) return 0;

    return last - first + 1;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int result = countOccurrences(n, arr, k);
    cout << result;
}
