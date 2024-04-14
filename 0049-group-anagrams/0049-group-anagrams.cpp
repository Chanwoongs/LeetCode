class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp = strs;
        set<string> st;

        for (auto& str : temp)
        {
            sort(str.begin(), str.end());
            st.insert(str);
        }

        vector<vector<string>> res(st.size());
        
        int i = 0;
        for (set<string>::iterator it = st.begin(); it != st.end(); it++) 
        {
	        for (int j = 0; j < temp.size(); j++)
            {          
                if (*it == temp[j])
                {
                    res[i].push_back(strs[j]);
                }
            }
            i++;
        }
        
        return res;
    }
};