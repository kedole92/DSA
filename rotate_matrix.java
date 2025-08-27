You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.

Input format
There are N+1 lines of input.
First line contains one integer N.
Next N line contains N space separated integers

Output format
Print the NxN rotated matrix.

Sample Input 1
3

1 2 3
4 5 6
7 8 9

Sample Output 1
7 4 1
8 5 2
9 6 3


public class RotateImage {
    public void swap(int [][]matrix, int r1, int c1, int r2, int c2)
    {
        int temp = matrix[r1][c1];
        matrix[r1][c1] = matrix[r2][c2];
        matrix[r2][c2] = temp; 
    }

    public void transpose(int [][] matrix)
    {
        for(int row=0; row<matrix.length; row++)
        {
            for(int col=row; col<matrix[0].length; col++)
            {
                swap(matrix, row, col, col, row);
            }
        }
    }

    public void reverseRows(int[][] matrix)
    {
        for(int row=0; row<matrix.length; row++)
        {
            int left=0, right=matrix.length-1;
            while(left<right)
            {
                swap(matrix, row, left, row, right);
                left++;
                right--;
            }
        }
    }

    public void rotateImage(int[][] matrix) {
        transpose(matrix);
        reverseRows(matrix);
        
    }
    
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int matrixSize = scanner.nextInt();
        int[][] matrix = new int[matrixSize][matrixSize];
        for (int i = 0; i < matrixSize; ++i) {
            for (int j = 0; j < matrixSize; ++j) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        scanner.close();

        new RotateImage().rotateImage(matrix);
        for (int i = 0; i < matrixSize; ++i) {
            for (int j = 0; j < matrixSize; ++j) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
