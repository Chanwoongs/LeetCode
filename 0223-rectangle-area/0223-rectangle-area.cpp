class Solution {
public:
	int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
		int a1 = (ax2 - ax1) * (ay2 - ay1);
        int a2 = (bx2 - bx1) * (by2 - by1);
        
		if(ax1 >= bx2 || ax2 <= bx1 || ay1 >= by2 || ay2 <= by1) { return a1 + a2; }
        
		vector<int> v, v1;
		v.push_back(ax1); 
        v.push_back(ax2); 
        v.push_back(bx1); 
        v.push_back(bx2);
        
		sort(v.begin(), v.end());
        
		v1.push_back(ay1); 
        v1.push_back(ay2); 
        v1.push_back(by1); 
        v1.push_back(by2);
        
		sort(v1.begin(), v1.end());
    
		return a1 + a2 - (v[2] - v[1]) * (v1[2] - v1[1]);
	}
};