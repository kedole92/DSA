Problem Description
Given a string S which consists of both lowercase and uppercase alphabetical letters, you have to write a function to check if string S is a permutation of a palindrome or not. Note: Characters are case sensitive i.e. ‘a’ is not the same as ‘A’.

Input format
First line contains an integer representing the value of T, the number of test cases.
In next T lines each line contains the string S.

Output format
For each test case, print "True"(without quotes) if it is a permutation of a palindrome and "False" otherwise.

Constraints
1 <= T <= 10
1 <= length(S) <= 100000

Sample Input 1
3
nnaamm
hello
Aab

Sample Output 1
True
False
False

Explanation 1
nnaamm is a permutation of namman, which is a palindrome
hello is not a permutation of any palindrome

bool isPermutationPalindrome(string &s) {
	
	// Create a list
    vector<char> list;
 
    // For each character in input strings,
    // remove character if list contains
    // else add character to list
    for (int i = 0; i < s.length(); i++) 
    {
        auto pos = find(list.begin(), list.end(), s[i]);
        if (pos != list.end()) {
            auto posi = find(list.begin(), list.end(), s[i]);
            list.erase(posi);
        }
        else
            list.push_back(s[i]);
    }
 
    // if character length is even list is 
    // expected to be empty or if character 
    // length is odd list size is expected to be 1
   
    // if string length is even
   
    if (s.length() % 2 == 0
            && list.empty() 
        || (s.length() % 2 == 1
            && list.size() == 1)) 
        return true;
   
    // if string length is odd
    else
        return false;

}

int main()
{
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		bool answer = isPermutationPalindrome(s);
		if(answer) {
			cout << "True\n";
		} else {
			cout << "False\n";
		}
	}
	return 0;
}
