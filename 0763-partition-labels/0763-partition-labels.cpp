class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        unordered_map<char, int> mp;
        
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]] = i;
        }
        
        int curPartStartIdx = 0;
        int curPartLastIdx = 0;
        for (int i = 0; i < s.size(); i++)
        {
            curPartLastIdx = max(curPartLastIdx, mp[s[i]]);
            if (curPartLastIdx == i) 
            {
                res.emplace_back(i - curPartStartIdx + 1);
                curPartStartIdx = i + 1; 
            }
        }
        return res;
    }
};