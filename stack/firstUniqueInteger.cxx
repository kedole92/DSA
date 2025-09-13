Problem Description
Hello Crio Warriors. You don't know me, but I know you and I want to play a game. Here's what happens if you lose. The question you are looking for is loaded with marks. When the timer in the back goes off, your marks will be permanently ripped off. Here is the question:
All the Bollywood superstars from the likes of Shah Rukh to Amitabh are lining up to entertain our Crio warriors. However due to certain security concerns they also brought their body doubles with them. A superstar can accompany any number of body doubles they want. Each superstar is represented by an integer, and all body doubles have the same integer representing them as the superstart.
We have to find the first superstar who came to entertain Crio warriors without a body double. If all the superstars have arrived with a body double then print -1.

Input format
You are given an integer N denoting the number of Bollywood superstars who arrived at Crio station, followed by N integers where ith integer denotes the Bollywood superstar.

Output format
You are required to output a single integer denoting the bollywood superstar who arrived without a body double. If all the superstars arrived with a body double print a -1

Constraints
1 <= N <= 1e5
0 <= Superstar <= 1e9

Sample Input 1
4
9 6 7 6

Sample Output 1
9

Explanation 1
Among the superstars who attended, 6 came with a body double whereas 9 and 7 came without any body doubles. The first superstar who arrived without a body double is 9.

Sample Input 2
5
7 6 1 6 1

Sample Output 2
7

Explanation 2
Among the superstars who attended, only 7 came without a body double.

using namespace std;
int firstUniqueInteger(vector<int> &v) {
	int result;
	map<int, int> freq;
	queue<int> q;

	for(int i=0; i< v.size(); ++i)
	{
		freq[v[i]]++;
		q.push(v[i]);
	}

	while(!q.empty())
	{
		if(freq[q.front()] == 1)
		{
			return q.front();
		}
		q.pop();
	}


	return -1;
}
int main() {
	int n, m;
	cin >> n;
	vector<int> v(n);
	for ( int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int ans = firstUniqueInteger(v);
	cout << ans << endl;
}

