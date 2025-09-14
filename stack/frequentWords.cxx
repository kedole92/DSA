Problem Description
You are given a list of words present in a book. Your younger brother is really curious to know the K most frequent words in the book, you have to find them.
Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order should come first.

Input format
There are three lines of input
The first line contains N, which is the number of input strings.
The second line contains N space separated input strings (S).
The third line contains the value of K.

Output format
Print the K most frequent words present inside the book, each in a new line. If two words have the same frequency, then the word with the lower alphabetical order should come first.

Constraints
1 <= N <= 1000
1 <= Length(S) <= 100000
'a' <= S[i] <= 'z'
1 <= K <= Number of Unique Strings

Sample Input 1
1
bus
1

Sample Output 1
bus

Explanation 1
In the given input, the frequency of "bus" is 1 and it is the 1st most frequent word.

Sample Input 2
3

car bus car
2

Sample Output 2
car
bus

Explanation 2
In the given input, the frequency of "car" is 2, frequency of “bus” is 1.
Since K = 2, both words are printed, with "car" being the most frequent, gets printed first.

struct Compare {
    bool operator() (pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};

vector<string> frequentWords(vector<string>& words , int k) {
	unordered_map<string, int> m;
        for(int i=0; i<words.size(); i++)
            m[words[i]]++;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> q;
        for(auto p : m)
            q.push({p.second, p.first});
        
        vector<string> ans;
        while(k--) {
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
}
int main() {
	int n, k;
	cin >> n;
	vector<string> v(n);
	for ( int i = 0; i < n; i++) cin >> v[i];
	cin >> k;
	vector<string> ans = frequentWords(v, k);
	for ( auto it : ans) {
		cout << it << endl;
	}
}
