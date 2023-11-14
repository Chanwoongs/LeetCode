class Solution {
public:
    bool checkOverlap(vector<int>& a, vector<int>& b)
    {
        return b[0] < a[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){return a[1] < b[1];});
        
        for (auto& ele : intervals)
        {
            cout << ele[0] << ele[1] << '\n';
        }
        
        vector<int> cur = intervals[0];
        res = 1;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (checkOverlap(cur, intervals[i]))
                continue;
            else
            {
                cur = intervals[i];
                res++;
            }
        }
        
        return intervals.size() - res;
    }
};