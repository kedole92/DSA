Problem Description
Given two strings s and t, write a function to determine if t is an anagram of s.
Note: You may assume the string contains only lowercase alphabets.
Note:-
There's a test case where both the strings are empty but the js compiler is treating one as empty and other as undefined. So, update the readline function accordingly.

Input format
You will be given two strings in two separate lines.

Output format
Print "true" if both the strings are anagram otherwise “false”.

Constraints
Length of string <= 100000

Sample Input 1
anagram
nagaram

Sample Output 1
true


class ValidAnagram {
    public:
        bool validAnagram(string s, string t) {
            if(s.size() != t.size())
            {
                return false;
            }
            std::sort(s.begin(),s.end());
            std::sort(t.begin(),t.end());

            for(int i=0; i<s.size(); i++)
            {
                if(s[i] != t[i])
                {
                    return false;
                }
            }
            return true;
        }
};

int main() {
    FastIO();
    string s, t;
    getline(cin, s);
    getline(cin, t);
    bool result = ValidAnagram().validAnagram(s, t);
    cout<< boolalpha << result;
    return 0;
}
