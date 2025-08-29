Problem Description
Given an array of integers, sort the array based on the absolute value of the elements.

Input format
First line contains an integer n - The number of elements.
Second line contains n space separated integers - The array nums.

Output format
For each test case print the minimum changes required on a separate line.

Sample Input 1
5
2 -5 1 -2 4

Sample Output 1
1 2 -2 4 -5

Explanation 1
Absolute values of elements are [2,5,1,2,4] respectively, so in the sorted order based on absolute values elements will be [1,2,-2,4,-5] or [1,-2,2,4,-5]. Both are accepted answers.

Constraints
1 <= n <= 10^5
-10^9 <= nums[i] <= 10^9


class SortArrayAbsolute {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int arr[] = new int[n];

        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        int res[] = sortArrayAbsolute(n, arr);

        for (int j : res)
            System.out.print(j + " ");
    }

    static int[] sortArrayAbsolute(int n, int arr[]) {
        // Convert Primitive int array into Array of Integers (Objects)
        Integer[] nums = new Integer[n];
        for(int idx = 0; idx < n; idx++){
            nums[idx] = arr[idx];
        }

        // Apply inbuilt sorting method on array of objects
        // and also pass the comparator
        Arrays.sort(nums,
        // Inside comparator, compare two values a and b
            (a, b) -> {
                // if |a| < |b| return -ve value
                if(Math.abs(a) < Math.abs(b)) return -1;
                // else if |a| > |b| return +ve value
                else if(Math.abs(a) > Math.abs(b)) return 1;
                // else return 0
                else return 0;
            }
        );

        // Convert the Array of Integers into primitive array
        for(int idx = 0; idx < n; idx++){
            arr[idx] = nums[idx];
        }

        // return primitive array
        return arr;

    }
}
