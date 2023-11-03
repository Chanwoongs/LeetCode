class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        
        int dp[104];
        fill(dp, dp + 104, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++)
        {
            int oneDigit = stoi(s.substr(i - 1, 1));
            int twoDigit = stoi(s.substr(i - 2, 2));
            
            if (oneDigit >= 1) dp[i] += dp[i - 1];
            if (twoDigit >= 10 && twoDigit <= 26) dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};