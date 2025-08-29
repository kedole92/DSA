Problem Description
A string S is given consisting of lowercase alphabetical characters only. You need to return a sorted string using Count Sort.

Input format
First line will contain a single integer n representing size of the given string.

Second line will contain a single string S of size n.

Output format
Output the string in a single line.

Sample Input 1
10

abcdeedcba

Sample Output 1
aabbccddee

Constraints
1<=n<=10^6

String S will contain lowercase alphabetical characters only


class CountSort {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        String s = sc.next();

        String res = countSort(n, s);

        System.out.println(res);

    }

    static String countSort(int n, String s) {
        // create a hashmap of keys as characters, values as integers
        HashMap<Character, Integer> hm = new HashMap<>();

        // run a for loop over each character in the string s
        for(int idx = 0; idx < s.length(); idx++){
            char ch = s.charAt(idx);
            // do frequency (value) of key as current character
            // increment by 1 in the hashmap
            int old = hm.getOrDefault(ch, 0);
            hm.put(ch, old + 1);
        }

        // create a output dynamic string which is initially empty
        StringBuilder res = new StringBuilder();

        // run a for loop over all characters from 'a' to 'z'
        for(char ch = 'a'; ch <= 'z'; ch++){
            // check the frequency of character in hashmap
            int frequency = hm.getOrDefault(ch, 0);
            // append the character frequency times in the output
            while(frequency-- > 0)
            {
                res.append(ch);
            }

        }
        return res.toString();
    }
}
