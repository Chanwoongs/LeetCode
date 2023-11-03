class Solution {
public:
string longestPalindrome(string s) {
        int dp[1004][1004];
        fill (&dp[0][0], &dp[0][0] + 1004 * 1004, 0);
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 2;
            }
        }

        for (int i = 2; i < n; i++)
        {
            int row = 0, col = i;

            while (col < n)
            {
                if (s[row] == s[col] && dp[row + 1][col - 1] != 0)
                {
                    dp[row][col] = dp[row + 1][col - 1] + 2;
                }
                row++;
                col++;
            }
        }

        string res;
        int mx = -1;
        int st, ed;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int cur = dp[i][j];
                if (mx < cur)
                {
                    mx = cur; st = i; ed = j;
                }
            }
        }
        return s.substr(st, ed - st + 1);
    }
};