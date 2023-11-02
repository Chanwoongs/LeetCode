class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int INF = 99999999;
        int dp[10004];
        
        fill(dp, dp + 10004, INF);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) 
        {
            for (int j = 0; j < coins.size(); j++) 
            {
                if (i - coins[j] >= 0) 
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == INF ? -1 : dp[amount];
    }
};