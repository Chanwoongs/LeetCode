class Solution {
public:
    string removeDuplicates(string s) {
        string st;
        
        for (auto& let : s)
        {
            if (!st.empty() && st.back() == let)
                st.pop_back();
            else
                st.push_back(let);
        }
        
        return st;
    }
};