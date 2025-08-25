Problem Description
Given two sorted arrays of size M and N, merge the two arrays and return the final array, sorted.

Input format
A single Integer M, that contains the number of elements in the first array.
A single Integer N, that contains the number of elements in the second array.
Next Line contains M space Integers of the array nums1.
Next Line contains N space Integers of the array nums2.

Output format
Print the array after merging.

Sample Input 1
3
3
1 2 3
2 5 6

Sample Output 1
1 2 2 3 5 6

Explanation 1
The sorted array is returned after merging.

Constraints
1 <= N,M <= 10^5
|nums1[i] | <= 10^9
|nums2[i] | <= 10^9

public class MergeSortedArray {
    // Implement your solution by completing the below function
    public static int [] mergeSortedArray(int[] nums1, int m, int[] nums2, int n) {
        //initialize three pointers
        int p1=0, p2=0, p3=0;
        //create a  resultant array
        int[] resultantArr = new int[m+n];
        
        while(p3 < m+n)
        {
            int val1 = (p1<m) ? nums1[p1] : (int)(1e9 +5);
            int val2 = (p2<n) ?nums2[p2] : (int)(1e9 +5);

            if(val1 < val2)
            {
                resultantArr[p3] = val1;
                p1++;
                p3++;
            }
            else
            {
                resultantArr[p3] = val2;
                p2++;
                p3++;
            }
        }
        return resultantArr;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        int[] nums1 = new int[m];
        int[] nums2 = new int[n];

        for (int i = 0; i < m; i++)
            nums1[i] = scanner.nextInt();
        for (int i = 0; i < n; i++)
            nums2[i] = scanner.nextInt();

        scanner.close();

        int[] nums = mergeSortedArray(nums1, m, nums2, n);
        for (int i = 0; i < nums.length; i++)
            System.out.print(nums[i] + " ");
    }
}
