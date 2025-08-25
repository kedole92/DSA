Problem Description
Given a sorted array, remove the duplicates in-place, such that each element in the array appears at most twice, and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Input format
There are two lines of input.
First line contains an integer n - Number of elements.
Second line contains n space separated integers - The array nums.

Output format
Print the new length in the first line.
In the second line print the nums array upto the new length.

Sample Input 1
7
2 2 2 3 4 4 9

Sample Output 1
6
2 2 3 4 4 9

Explanation 1
Your function should return 6 as the element 2 can only be present at most 2 times. So the first 6 elements of array nums should be modified to [2, 2, 3, 4, 4, 9].

Constraints
1 <= n <= 10^5
0 <= nums[i] <= 10^6

class RemoveDuplicatesFromSortedArrayII {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int arr[] = new int[n];

        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        int res = removeDuplicatesFromSortedArrayII(n, arr);

        System.out.println(res);

        for (int i = 0; i < res; i++)
            System.out.print(arr[i] + " ");

    }

    static int removeDuplicatesFromSortedArrayII(int n, int[] arr) {
        int count=0, val =0, j=0;

        //run for loop 
        for(int i=0; i<n;)
        {
            //store current value of arr index in val
            val = arr[i];
            count = 0;

            //run a while loop till arr length
            while(i<n && arr[i] == val)
            {
                count++;
                i++;
            }

            if(count>2) 
                count=2;

            while(count-- > 0)
            {
                arr[j] = val;
                j++;
            }
        }
        return j;
    }

}



