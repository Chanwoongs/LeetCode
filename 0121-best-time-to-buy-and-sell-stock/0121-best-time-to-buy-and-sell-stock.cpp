class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int lo = prices[0];
        
        for(int i = 1; i < prices.size(); i++)
        {
            lo = min(prices[i], lo);
            profit = max(profit, (prices[i] - lo));
        }
        return profit;
    }
};