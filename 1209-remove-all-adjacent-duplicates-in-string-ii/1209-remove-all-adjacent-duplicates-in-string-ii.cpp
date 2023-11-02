class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res;
        stack<pair<char, int>> st;
        
        for (auto& let : s)
        {
            if (!st.empty() && st.top().first == let)
            {
                if (++(st.top().second) == k)
                {
                    st.pop();
                }
            }
            else
                st.push({let, 1});
        }
        
        while (!st.empty())
        {  
            for (int i = 0; i < st.top().second; i++) 
            {
                res += st.top().first;
            }
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};