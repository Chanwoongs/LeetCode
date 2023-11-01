class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int al[127];
        int idx1 = 0, idx2 = 0;
        int maxLength = 0;
        int begin = -1, end = -1;
        
        memset(al, -1, sizeof(al));
        
        if (s.size() <= 1) return s.size();
        
        while (idx2 < s.size())
        {
            if (al[s[idx2]] >= idx1) idx1 = al[s[idx2]] + 1;
            al[s[idx2]] = idx2;
            
            int tempLength = idx2 - idx1 + 1;
            if (tempLength > maxLength)
            {
                maxLength = tempLength;
                begin = idx1;
                end = idx2;
            }
            idx2++;
        }
        
        return maxLength;
    }
};