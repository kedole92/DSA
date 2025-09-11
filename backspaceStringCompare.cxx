Problem Description
Given 2 strings S and T containing lowercase and '#' characters. You have to check whether these 2 strings are same or not when typed into an editor('#' being the backspace character).

Note: Backspacing an empty string remains an empty string only.
For eg. a#bc means bc, and a##bcd means bcd.

Input format
There are 2t+1 lines of input.
First line contains an integer tests - Number of test cases.
First line of each test case contains a string S.
Second line of each test case contains a string T.

Output format
Print true if the 2 strings are same otherwise false, for each test case print in a different line.

Function definition
You have to complete the given function. It accepts two parameters - the two strings, and returns a boolean value, true if S and T are same and false if not.

Sample Input 1
2
as#sddff#
aa#sddf
a##b
ab

Sample Output 1
true
false

Explanation
In first test case both the strings become "asddf" when typed into an editor.
In second test case the string becomes "b" and "ab" which are not equal.

Constraints
1 <= tests <= 10
1 <= Length of each string <= 10^5

bool backspaceStringCompare(string S, string T){
    int k=0, p=0;
    for(int i=0; i<S.size(); i++)
    {
        if(S[i] == '#')
        {
            k--;
            k=max(0,k);
        }
        else
        {
            S[k] = S[i];
            k++;
        }
    }
    for(int i=0; i<T.size(); i++)
    {
        if(T[i] == '#')
        {
            p--;
            p=max(0,p);
        }
        else
        {
            T[p] = T[i];
            p++;
        }
    }
    if(k!=p)
    {
        return false;
    }
    else
    {
        for(int i=0; i<k;i++)
        {
            if(S[i] != T[i])
            {
                return false;
            }
        }
        return true;
    }
}

int main(){
    int tests;
    cin >> tests;
    while (tests--) {
        string S, T;
        cin >> S;
        cin >> T;
        bool result = backspaceStringCompare(S, T);
        if (result) {
            cout << "true" << "\n";
        }
        else {
            cout << "false" << "\n";
        }
    }
}
