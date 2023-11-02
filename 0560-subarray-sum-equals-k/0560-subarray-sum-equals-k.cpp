class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int pSum = 0;
        int res = 0;
        
        mp[0] = 1; // 초기 합이 0인 경우를 고려
        
        for (int i = 0; i < nums.size(); i++) {
            pSum += nums[i];
            int target = pSum - k;
            
            if (mp.find(target) != mp.end()) {
                res += mp[target];
            }
            
            mp[pSum]++;
        }
        
        return res;
    }
};