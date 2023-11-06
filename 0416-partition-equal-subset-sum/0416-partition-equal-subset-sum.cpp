class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bool dp[204][20004];
        int n = nums.size();
        int target = 0;
            
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = false;
            dp[i][0] = true;
        }
        
        for (auto& n : nums)
        {
            target += n;
        }
        if (target % 2 != 0)
            return false;
        else
            target /= 2;
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][target];
    }
};