Problem Description
Ujjwal loves to read story books. There are n piles of books, the ith pile has a[i] books. His mom has gone to market and will come back in h hours.

Ujjwal can decide his books-per-hour reading speed of k. Each hour, he chooses some pile of books and reads k books from that pile. If the pile has less than k books, he reads all of them instead and will not read any more books during this hour.

Ujjwal likes to read slowly but still wants to finish reading all the books before his mom returns.

Return the minimum integer k such that he can read all the books within h hours.

Input format
First line contains n and h.

Second line contains n space integers given by a[i].

Output format
A single integer k.

Sample Input 1
4 8

3 6 7 11

Sample Output 1
4

Explanation
The minimum books-per-hour reading speed is 4 such that ujjwal can read all the books within h hours.

Constraints
1 <= n <= 10^4

n <= h <= 10^9

1 <= a[i] <= 10^9




static bool isPossible(vector<int> a, int h, long mid)
{
    long totalTime = 0;

    for(int books:a)
    {
        double time= ceil(1.0 * books / mid);
        totalTime += (long)time;
    }

    if(totalTime <= h)
    {
        return true;
    }

    return false;
}

int bookReading(int n,int h,vector<int> &a){
    int left=1, right=(long)1e9;
    long ans = right;

    while(left<=right)
    {
        int mid = (left+right)/2;

        if(isPossible(a,h,mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return int(ans);
}

int main(){
    
    
    int n,h;
    cin >> n >> h;

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int res = bookReading(n,h,a);
    cout << res << "\n";
   
}
