class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[304][5004];
        int n = coins.size();
        
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (i == 0) 
                {
                    dp[i][j] = 0;
                    continue;
                }
                else if (j == 0) 
                {
                    dp[i][j] = 1;
                    continue;
                }
                
                if (coins[i - 1] <= j)
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][amount];
    }
};