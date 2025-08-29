Problem Description
Given an unsorted array, sort it in wave form. That is, reorder it such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

Input format
There are 2 lines of input.
First line contains an integer N ,the number of input integers in the array.
Second line contains N space separated integers.

Output format
N space separated elements which satisfy the given condition.

Sample Input 1
6
1 5 1 1 6 4

Sample Output 1
1 4 1 5 1 6

Explanation 1
nums[0] <= nums[1] >= nums[2] <= nums[3] >= nums[4] <= nums[5].

Constraints
1 <= N <= 100000
-10^9 <= A[i] <= 10^9


class WiggleSort{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer>nums = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            nums.add(sc.nextInt());
        }
        List<Integer>ans = wiggleSort(n,nums);
        for (int i = 0; i < n; i++) {
            System.out.print(ans.get(i)+" ");
        }
    }

    static List<Integer> wiggleSort(int n, List<Integer> nums) {
    // run a for loop over all odd indices from 1 to n - 1
    for(int idx = 1; idx < nums.size(); idx += 2){
        // if left neighbour (val at idx - 1) is greater than val at idx
        if(nums.get(idx - 1) > nums.get(idx)){
            Collections.swap(nums, idx - 1, idx);
        }

        // swap arr at idx with arr at idx - 1
        // if right neighbour (val at idx + 1) is greater than val at idx
        if(idx != nums.size() -1 && nums.get(idx + 1) > nums.get(idx)){
            Collections.swap(nums, idx + 1, idx);
        }

        // swap arr at idx with arr at idx + 1
        // Note: if right neighbour does not exist (idx is n - 1), ignore
    }

    // return the same input array
    return nums;
    }
}
