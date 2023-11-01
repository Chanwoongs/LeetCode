class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> mp;
        int al[26];
        
        for (auto& s : strs)
        {
            memset(al, 0, sizeof(al));
            
            string key;
            for (auto& let : s)
            {
                al[let - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                if (al[i] > 0)
                {
                    key += i + 'a';
                    key += al[i];
                }
            }
            mp[key].emplace_back(s);
        }
        
        for (auto& it : mp)
        {
            res.push_back(it.second);
        }
        
        return res;
    }
};