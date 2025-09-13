Problem Description
Given a string S containing the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
For an input string to be valid:
Open brackets must be closed by the same type of brackets.( can be closed by ) only
Open brackets must be closed in the correct order. ([]) is valid, ([)] is not.
Note: An empty string is also considered valid.

Input format
One line containing a string with a bracket sequence.

Output format
Return "true" if balanced, false otherwise.

Constraints
0 <= | S | <= 10^5

Sample Input 1
()[]{}

Sample Output 1
true

Explanation 1
The given sequence of brackets is valid as per the rules specified.

Sample Input 2
([)]

Sample Output 2
false

Explanation 2
The given sequence of brackets is invalid as per the rules specified.

class ValidParenthesis
{
public:
	// Implement your solution here
	string isValid(string s)
	{
		stack<char> st ; 
        for (int i = 0 ;  i< s.length() ; i++)
        {
            char ch = s[i];

            // if opening bracket then push into the stack 
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch) ; 
            }

            else {
                // if a closing bracket then we compare with the top of the stack 
                // while comparing with top of stack we have 2 cases 
                // the stack can be empty or the stack is not empty 
                if (!st.empty())
                {
                    char top = st.top() ;
                    if ((ch == ')' && top == '(') || 
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '[')) 
                        {
                            // if matches then pop 
                            st.pop() ;
                        }
                        else 
                        {
                            return "false" ; 
                        }
                }
                else 
                {
                    // if stack is empty and we get a closing bracket means the string is unbalanced 
                    return "false" ;
                }
            }
        }

        // in the end if the stack is empty -- meaning there is no opening bracket present in the stack -- meaning all opening brackets have found their corresponding closing bracket and have been popped then we return trie 
        if (st.empty())
        {
            return "true" ; 
        }
        return "false" ;
	}
};

// NOTE: Please do not modify this function
int main()
{
	string s;
	getline(cin, s);
	string result = ValidParenthesis().isValid(s);
	cout << result;
	return 0;
}
