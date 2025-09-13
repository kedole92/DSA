Problem Description
Given an array of N elements and an integer B, you have to find the count of distinct numbers in all windows of size B.
You have to return an array of size N-B+1 where i'th element in the array is the number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1. If B > N, return an empty array.

Input format
There are 2 lines of input
First line contains two space separated integers N and B.
Second line contains N space separated integers representing the array A.

Output format
Return the array space separated in the first line.

Function definition
You have to implement the given function. It accepts three arguments - n, b and the input array. You have to return the new array as described.

Sample Input 1
6 3

1 2 1 3 4 3

Sample Output 1
2 3 3 2

Explanation
First range will be [1,2,1] , in which number of distinct elements are 2
Second range will be [2,1,3], in which number of distinct elements are 3
Third range will be [1,3,4], in which number of distinct elements are 3
Fourth range will be [3,4,3], in which number of distinct elements are 2

vector<int> countDistinctElements(int n, int b, vector<int> a){ 
    vector<int> result;

    if (b > n) return result; // If window size is greater than array size

    unordered_map<int, int> freq;

    // Count frequency in the first window
    for (int i = 0; i < b; ++i) {
    freq[a[i]]++;
    }

    // Add the distinct count of the first window
    result.push_back(freq.size());

    // Slide the window
    for (int i = b; i < n; ++i) {
    int out_elem = a[i - b];
    int in_elem = a[i];

    // Remove the outgoing element
    freq[out_elem]--;
    if (freq[out_elem] == 0) {
        freq.erase(out_elem);
    }

    // Add the incoming element
    freq[in_elem]++;

    // Add the current window's distinct count
    result.push_back(freq.size());
    }

    return result;
}


int main(){
    int n, b;
    cin>> n >> b;
    vector<int> a(n);
    for(auto &i: a)
        cin>> i;
    vector<int> result = countDistinctElements(n, b, a);
    assert( result.size() == max(0,n - b + 1) );
    for(auto &i: result){
        cout << i << " " ;
    }
}
