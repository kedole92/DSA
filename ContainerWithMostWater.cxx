Problem Description
You are given an array of N non-negative integers where each represents the height of a line. 
N vertical lines are drawn at points marked 1 to n on the x axis as shown in the diagram.
Find two lines, which together with the x axis forms a container, such that the container holds the most water.
Assume the width of lines to be negligible.

Note: You may not slant the container and n is at least 2.

Input format
The first line consists of an integer, N, denoting the size of the array.
The second line consists of N space separated integers which denote the elements of the array,

Output format
Single integer denoting the capacity of the largest container.

Constraints
2 <= N <= 10^6

Sample Input 1
9
1 8 6 2 5 4 8 3 7

Sample Output 1
49

Explanation 1
The lines of length 8 and 7 form a container that can hold 7*7=49 units of water. Here, the first 7 is the minimum of the two line heights and the second 7 is the number of units they are apart. This is the largest container that can be formed with the given input.


class ContainerWithMostWater {

    // Complete the function implementation below
    public int maxArea(int[] height) {
        int answer = 0;
        int left= 0, right=height.length-1;

        while(left < right)
        {
            int area = Math.min(height[left], height[right]) * (right-left);

            answer = Math.max(answer, area);

            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return answer;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int height[] = new int[n];
        for(int i = 0 ; i < n ; i++) {
            height[i] = scanner.nextInt();
        }
        scanner.close();
        int result = new ContainerWithMostWater().maxArea(height);
        System.out.println(result);
    }
}
