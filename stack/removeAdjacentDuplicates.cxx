Problem Description
You are given a string s, consisting of lowercase letters. You need to make duplicate removal on s until you no longer can.
A duplicate removal consists of choosing two adjacent equal characters and removing both of them.
Return the final string after all such duplicate removals have been made.

Input format
The first line contains a single string s.

Output format
Print the final string after duplicate removals.

Function definition
You have to complete the given function. It accepts one argument -the input string, and returns the updated string.

Sample Input 1
abbaca

Sample Output 1
ca

Explanation
Initial String: abbaca
After removing "bb" : aaca
After removing "aa" : ca (There are no more duplicates)
Constraints
1 <= |s| <= 10^5

string removeAdjacentDuplicates(string s)
{
      string res;
      for(char ch : s)
      {
            if(!res.empty() && res.back() == ch)
            {
                  res.pop_back();
            }
            else
            {
                  res.push_back(ch);
            }
      }
      return res;
}

int main()
{

    string s;
    cin >> s;

    string res = removeAdjacentDuplicates(s);

    cout << res << "\n";
}
