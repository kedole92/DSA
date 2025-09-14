Problem Description
You are given two strings, a main string S, and a pattern P. You have to find the starting indices of the anagrams of P in S.
Anagrams are permutations of a string. For P="abc”, its anagrams are abc,acb,bca,bac,cba,cab.
Note that indexing starts at 0.

Input format
There is one line of input, containing two space-separated strings S and P.

Output format
First-line should contain the number of such starting indices.
Next line should contain the indices in increasing order separated by a space.

Sample Input 1
aaba ab

Sample Output 1
2
1 2

Explanation 1
The anagrams of pattern "ab" are “ab” and “ba”. These are present at indices 1 and 2 of the input string “aaba”.

Sample Input 2
bacdgabcda abcd

Sample Output 2
3
0 5 6

Explanation 2
The anagrams of "abcd" can be seen as “bacd” at index 0, “abcd” at index 5 and “bcda” at index 6.

using namespace std;


vector<int> findAnagrams(string s, string p)
{
	int slen = s.length();
	int plen = p.length();

	if(s.size() < p.size())
	{
		return {};
	}

	vector<int>freq_p(26,0);
	vector<int>window_size(26,0);

	for(int i=0; i<plen; i++)
	{
		freq_p[p[i] - 'a']++;
		window_size[s[i] - 'a']++;
	}

	vector<int> ans;

	if(freq_p == window_size)
	{
		ans.push_back(0);
	}

	for(int i=plen; i<slen; i++)
	{
		window_size[s[i-plen] - 'a']--;
		window_size[s[i] - 'a']++;
	
		if(freq_p == window_size)
		{
			ans.push_back(i-plen+1);
		}
	}
	return ans;
}

int main()
{
	string s, p;
	cin >> s >> p;
	vector<int> answer = findAnagrams(s, p);
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}
