class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int y = n - 1, x = 0;
        
        while(true)
        {
            if (matrix[y][x] < target)
            {
                x++;
            }
            else if (matrix[y][x] > target)
            {
                y--;
            }
            else
            {
                return true;
            }
            
            if (y == -1 || x == m) return false;
        }
    }
};