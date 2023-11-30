class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int m = haystack.size(), n = needle.size(), p = 0;
        while(p + n-1 < m)
        {
            if (haystack.substr(p, n) == needle)
            return p;
            p++;
        }
        return -1;
    }
};