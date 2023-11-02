class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int pSum = 0;
        mp[0] = {-1};
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                pSum += -1;
            else 
                pSum += 1; 
            mp[pSum].push_back(i);
        }
        
        int maxLength = -1;
        for (auto& ele : mp)
        {
            if (maxLength < ele.second.back() - ele.second.front())
            {
                maxLength = ele.second.back() - ele.second.front();
            }
        }
        return maxLength;
    }
};