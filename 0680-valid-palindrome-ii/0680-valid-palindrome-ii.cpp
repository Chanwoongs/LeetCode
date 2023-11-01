class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        int cnt = 0;
        while (i <= j)
        {
            if (s[i] == s[j])
            {
                i++; j--;
            }
            else
            {
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
            }
        }
        return true;
    }
    
    bool isPalindrome(string s, int st, int ed)
    {
        while (st <= ed)
        {
            if(s[st] != s[ed])
            {
                return false;
            }
            st++;
            ed--;
        }
        return true;
    }
};