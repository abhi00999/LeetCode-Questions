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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        if(root==NULL) return ans;

        while(!q.empty()){
            int sz=q.size(),flag;

            while(sz--){
                TreeNode* f= q.front();
                if(f->left!=NULL) q.push(f->left);
                if(f->right!=NULL) q.push(f->right);
                flag=f->val;
                q.pop();
            }
            ans.push_back(flag);
        }
        return ans;
    }
};