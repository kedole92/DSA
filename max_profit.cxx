You have an array in which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit by buying a share on one day and selling it on another day. You may repeat this across the days (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again)

Input format
First line contains N, the number of days for which stock price will be provided
Next line contains N space separated integers representing the stock prices on each of these N days

Output format
Print out the maximum profit possible. Print 0 if no profit is possible.

Constraints
1 <= N <= 10^5
1 <= Stock prices <= 10^5

Sample Input 1
6
7 1 5 3 6 4

Sample Output 1
7

Explanation 1
Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Again buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit of 7.


class BestTimeToBuyAndSellStocks {
    public:
        // Implement Your Solution Here
        int maxProfit(vector<int>& prices) {
            int profit = 0;
            int size = prices.size();
            for(int i=0; i<size-1; i++)
            {
                if(prices[i] < prices[i+1])
                {
                    profit += (prices[i+1] - prices[i]);
                }
            }
            return profit;
        }
};

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> prices;
    ReadMatrix<int>().OneDMatrix(n, prices);
    int result = BestTimeToBuyAndSellStocks().maxProfit(prices);
    cout << result;
    return 0;
}
