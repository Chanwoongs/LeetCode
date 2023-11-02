class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> mp;
        int n = points.size();
        int res = 99999999;
        for (int i = 0; i < n; i++)
        {
            mp[points[i][0]].insert(points[i][1]);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (points[i][0] == points[j][0] || points[i][1] == points[j][1]) continue;
                auto p1 = mp.find(points[i][0]);
                auto p2 = mp.find(points[j][0]);

                if (p1 == mp.end() || p2 == mp.end()) continue;

                if (p1->second.find(points[j][1]) != p1->second.end() && 
                    p2->second.find(points[i][1]) != p2->second.end())
                {
                    int area = abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]);
                    res = min(res, area);
                }
            }
        }
        return res == 99999999 ? 0 : res;
    }
};