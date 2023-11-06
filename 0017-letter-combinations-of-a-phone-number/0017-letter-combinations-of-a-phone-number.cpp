class Solution {
public:
    vector<string> res;
    unordered_map<int, string> mp;
    int n = 0;
    
    void go(int idx, string lets, string& digits)
    {
        if (idx >= n) res.emplace_back(lets);
        
        int num = digits[idx] - '0';
        string chars = mp[num];
        
        for (auto& c : chars)
        {
            go(idx + 1, lets += c, digits);
            lets.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        if(n == 0) return {};
        
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        
        go (0, "", digits);
        
        return res;
    }
};