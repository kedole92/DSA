Given a number represented as an array of digits, increment the number by 1, and return the resulting sum as an array.

Input format
There are two lines of input.
First line will contain a single integer N .
Next line will contain N space separated integers for Array A.

Output format
Single integer which will be the incremented number.

Sample Input 1
3
1 1 1

Sample Output 1
112

Explanation
111 + 1 = 112

Constraints
0<=Ai<10
Most significant value will be non-zero in the array.
1<=N<=5000

vector<int> incrementNumber(int n, vector<int > A){
        //run a for loop over the vector
        for(int idx=n-1; idx>=0; idx--)
        {
            //check if the value at idx is 9
            if(A[idx] == 9)
            {
                //replace that digit with 0;
                A[idx] = 0;
            }
            else
            {
                //increment the digit at idx
                ++A[idx];
                //return the vector
                return A;
            }
        }

        //handle corner case of 9999
        vector<int> newVector(n+1);
        newVector.insert(newVector.begin(), 1);
        return newVector;
}


int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &i : A)
    {
        cin >> i;
    }
    vector<int> result = incrementNumber(n, A);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
}
