Problem Description
Reverse the bits of a given 32 bits unsigned integer.
Hint: To avoid negative values caused by integer overflow, utilize BigInt in your JavaScript code for handling large integer computations.BigInt is a JavaScript built-in object used to represent integers larger than the range supported by the Number primitive.

Input format
First line contains the number of test cases.

Each line contains a 32 bit unsigned integer.

Output format
Output the Reversed unsigned integer.

Sample Input 1
1

43261596

Sample Output 1
964176192

Explanation 1
The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 whose binary representation is 00111001011110000010100101000000


unsigned int reverseBits(unsigned int n) {
	uint32_t reversedNumber = 0; // Initialize the result to represent the reversed number.
      
        // Loop through all 32 bits of the input number.
        for (int bitPosition = 0; bitPosition < 32; ++bitPosition) {
            // Isolate the least-significant bit (rightmost bit) of 'n' and shift it to the correct position
            // in 'reversedNumber' (which starts from the leftmost bit and goes rightwards with each iteration).
            reversedNumber |= (n & 1) << (31 - bitPosition);
            // Shift input number 'n' right by one bit to process the next bit in the next iteration.
            n >>= 1;
        }
      
        // Return the reversed number after all 32 bits have been processed.
        return reversedNumber;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		unsigned int n;
		cin >> n;
		unsigned int ans = reverseBits(n);
		cout << ans << endl;
	}
}
