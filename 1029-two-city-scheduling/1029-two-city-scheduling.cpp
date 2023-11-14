class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res = 0;
        vector<pair<vector<int>, int>> v;
        
        for (auto& ele : costs)
        {
            v.emplace_back(make_pair(ele, ele[1] - ele[0]));
        }
        
        sort(v.begin(), v.end(), [](auto& a, auto& b){return a.second > b.second;});
        
        int cnt = costs.size();
        for (int i = 0; i < v.size(); i++)
        {
            if (i < cnt / 2)
                res += v[i].first[0];
            else res += v[i].first[1];
        }
        return res;
    }
};