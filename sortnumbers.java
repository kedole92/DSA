Problem Description
Given an array, where integers are written as strings, sort the array and return it, with the elements still being strings.

Note that the number of digits in each element may go up to 10^6.

Input format
There are 2 lines of input.

First line will contain a single integer n, the size of array.

Second line will contain n space separated integers.

Output format
Return n space separated integers in a single line

Sample Input 1
5

3 30 1 124 54644

Sample Output 1
1 3 30 124 54644

Constraints
1<=n<=2 x 10^5

1<=Number of digits in each string<=10^6

1<=Total Count of digits of all strings<=10^6

There’ll be no leading zeros in any of the strings


class NumSort {
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        String arr[] = new String[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.next();
        }

        String sortedArray[] = numSort(n, arr);

        for (String num : sortedArray) {
            System.out.print(num + " ");
        }

    }

    static String[] numSort(int n, String[] arr) {
        
        // Apply the inbuilt sorting on array of strings
        Arrays.sort(arr,
        // and pass the comparator
        (a, b) -> {
        // take two values a and b and compare them
        // if length of a length of b return -1 
        if(a.length() < b.length()) return -1;
        //else if length of a > length of b return +1;
        else if(a.length() > b.length()) return +1;
        // else return the comparison on lexicographical order 
        else return a.compareTo(b);
        // return the same array
        
    });
    return arr;
    }
};
