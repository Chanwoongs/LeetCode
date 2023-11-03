class Solution {
public:    
    int maxSubArray(vector<int>& nums) {
        int dp[100004];
        int n = nums.size();
        pair<int, int> maxValue = {-1, -1};
        int stIdx = 0; 
        
        fill (dp, dp + 100004, 0);
        
        maxValue = {nums[0], 0};
        dp[0] = maxValue.first;
        
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > dp[i - 1] + nums[i])
            {
                stIdx = i;
                dp[i] = nums[i];
                if (nums[i] > maxValue.first)
                {
                    maxValue = {nums[i], i};
                }
            }
            else
            {
                dp[i] = dp[i - 1] + nums[i];
                if (dp[i - 1] + nums[i] > maxValue.first)
                {
                    maxValue = {dp[i - 1] + nums[i], i};
                }
            }
        }
        
        return maxValue.first;
    }
};