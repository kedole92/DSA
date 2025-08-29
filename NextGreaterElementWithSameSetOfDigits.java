Problem Description
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Input format
A 32 bit integer N

Output format
A single integer

Sample Input 1
12

Sample Output 1
21

Explanation
There is only one number greater than 12 which is composed of 2 and 1 and it is 21.

Constraints
0<= N <= 10^9



class NextGreaterElementWithSameSetOfDigits{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n;
        n=sc.nextInt();
        System.out.print(nextGreaterElementWithSameSetOfDigits(n));
    }

    static void reverse(char[] digits, int left, int right){
        while(left <= right){
            char temp = digits[left];
            digits[left] = digits[right];
            digits[right] = temp;
            left++; right--;
        }
    }

    static int nextGreaterElementWithSameSetOfDigits(int n){
        // create a character array digits from integer n
        char[] digits = Integer.toString(n).toCharArray();

        // find dip by running a loop over i index from second last index
        int i = digits.length - 2;
        while(i >= 0){
            // if digit at i index is smaller than digit at (i + 1) index
            if(digits[i] < digits[i + 1])
                // break
                break;
            i--;
        }

        // if i index is becoming negative, then return -1
        if(i < 0) return -1;

        // find just greater digit in right side over j index from last index
        int j = digits.length - 1;
        while(j >= 0){
            // if digit at j index is greater than digit at i index
            if(digits[j] > digits[i])
                // break
                break;
            j--;
        }

        // swap the digits at i and j index
        //Arrays.swap(digits, i, j);
        char temp = digits[i];
        digits[i] = digits[j];
        digits[j] = temp;

        // reverse the array from i + 1 index till last index
        reverse(digits, i+1, digits.length-1);
        // return the character array converted into a integer
        return Integer.parseInt(String.valueOf(digits));

    }
}
