class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num = 0;
        for (int i = 0; i <= nums.size(); i++)
        {
            num ^= i;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            num ^= nums[i];
        }
        return num;
    }
};