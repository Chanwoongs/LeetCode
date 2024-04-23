class Solution {
public:
    int titleToNumber(string columnTitle) {
        int num = 0;
        for(int i = 0; i < columnTitle.size(); i++)
        {
            int val = columnTitle[i] - 'A' + 1;
            num = num * 26 + val;
        }
        return num;
    }
};