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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> tmp;
        
        while(!q.empty()){
            int sz=q.size();
            
            while(sz--){
                TreeNode* top= q.front();
                q.pop();
                tmp.push_back(top->val);
                
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                
            }
            res.push_back(tmp);
            tmp.clear();            
        }
        reverse(res.begin(),res.end());
        return res;
    }
};