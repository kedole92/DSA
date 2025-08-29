Problem Description
An interval is a range, with a starting value and ending value. [1, 3] indicates elements 1, 2, 3 and so on.

Given a collection of intervals, merge all overlapping intervals. The result should only have mutually exclusive intervals - meaning that no number should be common between two intervals, in the result.

Note: The merged intervals should be printed in increasing order of start value.

Input format
There are N+1 lines of input.

First line contains N, the number of intervals

Next N lines contain 2 space separated integers A and B, which represent the start and end of an interval

Output format
For the X merged intervals, print each interval (the start and end being space separated) on a separate line

Constraints
1 <= N <= 50000

0 <= A, B <= 1e9

B >= A

Sample Input 1
4
1 3
2 6
8 10
15 18

Sample Output 1
1 6
8 10
15 18

Explanation 1
Since intervals [1 3] and [2 6] overlap, merge them into [1 6]



class MergeIntervals {

    public int[][] mergeIntervals(int[][] intervals) {
        // sort all intervals on the basis of starting point

        // using comparator

        // return first interval's starting pt - second intervals's ending pt 
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        // create an arraylist (dynamic array) result containing intervals 
        ArrayList<int[]> result = new ArrayList<>();

        // run a for loop over all intervals

        for(int[] curr: intervals){

            int[] last = (result.size() == 0) ? null : result.get(result.size() - 1);

            // if last interval is not present or last intervals' ending pt &lt; curr's starting pt 
            if(last == null || last [1] < curr[0])

            // add the current interval in the output

            result.add(curr);

            // else

            else

            // update last intervals' ending pt as maximum of last or curr's ending pt 
            last [1] = Math.max(last [1], curr[1]);

        }

        // convert dynamic array into static array and return the static array 
        int[][] ans = new int[result.size()] [2];

        for (int idx = 0; idx < ans.length; idx++){

            ans [idx] = result.get(idx);

        }
        return ans;
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        int[][] nums = new int[n][2];

        for(int i = 0 ; i < n ;i++) {
            nums[i][0] = scanner.nextInt();
            nums[i][1] = scanner.nextInt();
        }

        int[][] results = new MergeIntervals().mergeIntervals(nums);

        for (int i = 0; i < results.length; ++i) {
            System.out.printf("%d %d\n", results[i][0], results[i][1]);
        }
    }
}
