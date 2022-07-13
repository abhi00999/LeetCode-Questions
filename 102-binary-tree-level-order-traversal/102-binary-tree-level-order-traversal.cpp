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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        if(!root) return ans;
        
        q.push(root);
        vector<int> tmp;
        
        while(!q.empty()){
            int sz=q.size();
            tmp.clear();
            
            while(sz--){
                TreeNode* f=q.front();
                tmp.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                q.pop();
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};