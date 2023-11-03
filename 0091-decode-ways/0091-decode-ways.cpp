class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        
        vector<int> dp(n + 1);
        dp[n] = 1;
        
        char lastLet = s[n - 1];
        if ((lastLet - '0') == 0)
            dp[n - 1] = 0;
        else dp[n - 1] = 1;
        
        for (int i = n - 2; i >= 0; i--)
        {
            int singleNum = s[i] - '0';
            if (singleNum > 0) dp[i] += dp[i + 1];
            
            int doubleNum = stoi(s.substr(i, 2));
            if (doubleNum >= 10 && doubleNum <= 26) dp[i] += dp[i + 2];
        }
        
        return dp[0];
    }
};