class Solution {
public:
    void go(vector<int> v, int prev, int sum, vector<int>& candidates, int& target, vector<vector<int>>& res)
    {
        if (sum > target) return;
        if (sum == target)
        {
            res.emplace_back(v);
            return;
        }
        
        for (auto& ele : candidates)
        {
            if (ele < prev) continue;
            
            v.emplace_back(ele);
            go (v, ele, sum + ele, candidates, target, res);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        
        go({}, 0, 0, candidates, target, res);
        
        return res;
    }
};