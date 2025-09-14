Problem Description
You are given a string consisting of lower and upper case characters.
You need to find the length of the longest palindrome which you can create by using the characters from the string.
Note: Upper case and lower case characters are different from each other i.e, "Aa" is not a palindrome as 'A' != 'a'.

Input format
There are 2 lines of input
First line contains the size of the string
Second line contains the string.

Output format
Print the length of the longest palindrome possible.

Sample Input 1
4 bbde

Sample Output 1
3

Explanation
The possible 3 size palindrome strings are :- beb and bdb

int longestPalindrome(int n, string s)
{
      int oddCountFreq = 0;
      map<char, int> freqMap;

      for(char ch : s)
      {
            freqMap[ch]++;
            if(freqMap[ch] % 2 == 1)
            {
                  oddCountFreq++;
            }
            else
            {
                  oddCountFreq--;
            }
      }
      if(oddCountFreq > 1)
      {
            return n-oddCountFreq+1;
      }
      return s.length();
}

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = longestPalindrome(n, s);
    cout << ans << endl;
}
