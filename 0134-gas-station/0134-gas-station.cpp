class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int idx = 0;    
        
        int g = 0, c = 0, tg = 0, tc = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            tg += gas[i];
            tc += cost[i];
            g += gas[i];
            c = cost[i];
            g -= c;

            if (g < 0)
            {
                idx = i + 1;
                g = 0;
            }
        }
        return tg < tc ? -1 : idx;
    }
};