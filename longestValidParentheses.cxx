Problem Description
Given a string S containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Input format
First line contains a string - The string S.

Output format
Print the length of the longest valid substring.

Sample Input 1
()(()(())

Sample Output 1
6

Explanation
The last 6 characters of the string forms the longest valid substring i.e. "()(())".

Constraints
0 <= length of string <= 10^5


int longestValidParentheses(string s){
      stack <int> st;

      st.push(-1);
      int maxLen = 0;

      for(int i=0; i<s.size(); i++)
      {
            if(s[i] == '(')
            {
                  st.push(i);
            }
            else
            {
                  st.pop();
            }

            if(st.empty())
            {
                  st.push(i);
            }
            else
            {
                  maxLen = max(maxLen, i-st.top());
            }
      }
      return maxLen;
}


int main(){
    string S;
    cin >> S;
    int ans = longestValidParentheses(S);
    cout << ans;
}
