Problem Description
Find the minimum difference possible between any two elements in the given array.

Input format
There are 2 lines of input.

First line will contain a single integer n representing the size of the array.

Second line will contain n space separated integers representing the array.

Output format
Output the answer in single line.

Sample Input 1
3

1 2 4

Sample Output 1
1

Explanation 1
2 - 1 = 1 minimum difference


class MinDiff {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int res = minDiff(n, a);

        System.out.println(res);

    }

    static int minDiff(int n, int arr[]) {
        // Sort array on increasing order using inbuilt method 
        Arrays.sort(arr);

        // set an integer ans as 1000000000 + 1

        int ans = 1000000001;

        // run a for loop over idx from 0 to n - 2
         for(int i = 0; i <= n-2; i++){

            // if arr at i + 1 - arr at 1 &lt; ans 
            if(arr[i + 1] - arr[i] < ans) {

            // update ans as arr at i + 1 - arr at i 
                ans = arr[i + 1] - arr[i];

            }
        }

        // return ans

        return ans;
    }
}
