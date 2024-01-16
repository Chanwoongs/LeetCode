/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode*, char>> q;     
        q.push({root, 'r'});                
        
        int ans = 0;                        
        
        while(!q.empty()) 
        {
            TreeNode* temp = q.front().first;
            char ch = q.front().second;
            q.pop();
            
            if(temp->left == NULL && temp->right == NULL) 
            {
                if(ch == 'l') 
                {
                    ans += temp->val;
                }
            }
            if(temp->left) 
            {
                q.push({temp->left, 'l'});  
            }
            if(temp->right) 
            {
                q.push({temp->right, 'r'});   
            }
        }
        return ans;
    }
};