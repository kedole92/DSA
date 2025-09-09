Problem Description
Given two numbers, write a program to count the number of bits that need to be flipped to convert the first number to the second number.
Hint: To avoid negative values caused by integer overflow, utilize BigInt in your JavaScript code for handling large integer computations.BigInt is a JavaScript built-in object used to represent integers larger than the range supported by the Number primitive.

Input format
A single line that contains two space separated integers A and B.

Output format
A single line that contains an integer which represents the number of bits needed to flip to convert integer A to integer B

Constraints
0 <= A, B <= 10^18

Sample Input 1
29 15

Sample Output 1
2

Explanation 1
Binary of 29 is 11101 and Binary of 15 is 01111. So, 2 bits need to be flipped.

Sample Input 2
7 10

Sample Output 2
3

Explanation 2
Binary of 7 is 00000111 and Binary of 10 is 00001010. So, 3 bits need to be flipped.

int countConversionBits(long long a, long long b) {
     // initially flips is equal to 0
    int flips = 0;

    // & each bits of a && b with 1
    // and store them if t1 and t2
    // if t1 != t2 then we will flip that bit

    while (a > 0 || b > 0) {

        int t1 = (a & 1);
        int t2 = (b & 1);

        if (t1 != t2) {
            flips++;
        }
        // right shifting a and b
        a >>= 1;
        b >>= 1;
    }

    return flips;
}

int main() {
	long long a , b;
	cin >> a >> b;
	int answer = countConversionBits(a, b);
	cout << answer;
	return 0;
}

