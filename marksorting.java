Problem Description
You are given a list of marks over 5 subjects scored by n students. You need to sort the student by following rules.
The student whose sum of marks will be highest must come at the top of the leaderboard.
Students whose total sum of marks are the same will be sorted alphabetically ascending by name.
In all other cases, student with lesser id will come before in the leaderboard

Input format
First line will contain a single integer n number of students.
Next n lines will contain space separated unique integer Id, string S name of the student followed by 5 integers marks scored out of 100.

Output format
Print space separated list of sorted ids of the student in a single line

Sample Input 1
3
1 Alan 45 56 21 32 74
2 Fabien 95 94 93 92 91
3 Gamora 85 65 54 65 76

Sample Output 1
2 3 1

Explanation 1
Fabien has the most marks obtained and then Gamora and followed by Alan


class Student {
    int id;
    String name;
    int marks[] = new int[5];

    public Student(int id, String name, int marks[]) {
        this.id = id;
        this.name = name;

        for (int i = 0; i < 5; i++) {
            this.marks[i] = marks[i];
        }
    }
}

class MarksSort {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        Student arr[] = new Student[n];

        for (int i = 0; i < n; i++) {

            int id = sc.nextInt();
            String name = sc.next();
            int marks[] = new int[5];

            for (int j = 0; j < 5; j++)
                marks[j] = sc.nextInt();
            arr[i] = new Student(id, name, marks);
        }

        int res[] = marksSort(n, arr);

        for (int j : res) {
            System.out.print(j + " ");
        }
    }

    static int[] marksSort(int n, Student arr[]) {
        // Call the inbuilt sorting method to sort all array of students
        Arrays.sort(arr, (a, b) -> {
            // Inside the inbuilt sorting method, pass the comparator
            // Lets say two parameters in comparator are a and b
            // calculate sum of marks of student a
            int sumA = a.marks[0] + a.marks[1] + a.marks[2] + a.marks[3] + a.marks[4];
            // calculate sum of marks of student b
            int sumB = b.marks[0] + b.marks[1] + b.marks[2] + b.marks[3] + b.marks[4];
            // if sumA != sumB, sort on decreasing order of sum
            if(sumA != sumB)
                // return (sumB - sumA)
                return (sumB - sumA);
            // if nameA = nameB, sort on alphabetical order of names
            if(a.name.equals(b.name) == false)
                return a.name.compareTo(b.name);
            // sort on increasing order of ids
            // return (a.id - b.id)
            return (a.id - b.id);
        });

        // create an array of integers and store all ids from sorted
        // students input array into the result array
        int[] res = new int[n];
        for(int idx = 0; idx < n; idx++) {
            res[idx] = arr[idx].id;
        }
        return res;
    }
}
