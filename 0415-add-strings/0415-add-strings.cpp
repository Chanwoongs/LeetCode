class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        
        int idx1 = num1.size() - 1;
        int idx2 = num2.size() - 1;
        
        int carry = 0;
        
        while (idx1 >= 0 || idx2 >= 0)
        {
            int a = 0, b = 0;
            if (idx1 >= 0)
                a = num1[idx1--] - '0';
            if (idx2 >= 0)
                b = num2[idx2--] - '0';
            int sum = carry + a + b;
            int remain = sum % 10;
            carry = sum / 10;
            res += remain + '0';
        }
        if (carry) res += carry + '0';
        reverse(res.begin(), res.end());
        return res;
    }
};