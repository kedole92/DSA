Problem Description
Given an unsigned integer N, swap all odd bits with even bits. Every even position bit is swapped with the adjacent bit on the right side and every odd position bit is swapped with adjacent on the left side. Assume a 32 bit integer.
Hint: To avoid negative values caused by integer overflow, utilize BigInt in your JavaScript code for handling large integer computations.BigInt is a JavaScript built-in object used to represent integers larger than the range supported by the Number primitive.

Input format
N which represents an unsigned integer.

Output format
Single output integer after the algorithm has successfully swapped bits of the input.

Constraints
0 <= N <= 2147483647

Sample Input 1
22

Sample Output 1
41

Explanation 1
The given number is 22 (00010110), it should be converted to 41 (00101001).

Sample Input 2
13

Sample Output 2
14

Explanation 2
The given number is 13 (00001101), it should be converted to 14 (00001110).


unsigned int swapAllOddAndEvenBits(unsigned int n) {
      for (int i = 0; i < 32; i += 2) {

        // Find i th bit
        int i_bit = (n >> i) & 1;

        // Find i+1 th bit
        int i_1_bit = (n >> (i + 1)) & 1;

        // Remove i_bit
        n = n
            - (i_bit << i)
            // Remove i+1 th bit
            - (i_1_bit << (i + 1))
            // Put i_bit at i+1 location
            + (i_bit << (i + 1))
            // Put i+1 bit at i location
            + (i_1_bit << i);
    }
    return n;
}

int main()
{
	unsigned int n;
	cin >> n;
	unsigned int answer = swapAllOddAndEvenBits(n);
	cout << answer;
	return 0;
}
