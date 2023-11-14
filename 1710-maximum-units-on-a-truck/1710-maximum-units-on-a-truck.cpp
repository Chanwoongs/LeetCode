class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res = 0;
        
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        
        for (auto& ele : boxTypes)
        {
            if (truckSize <= 0) break;
            res += min(truckSize, ele[0]) * ele[1];
            truckSize -= ele[0];
        }
        return res;
    }
};