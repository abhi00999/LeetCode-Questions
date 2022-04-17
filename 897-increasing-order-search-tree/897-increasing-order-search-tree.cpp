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
    void fun(vector<int> &v, TreeNode* root){
        if(root==NULL) return;
        
        fun(v, root->left);
        v.push_back(root->val);
        fun(v, root->right);
        return;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        fun(v, root);
        TreeNode* head= new TreeNode(v[0]);
        TreeNode* ans=head;
        TreeNode* cur=head;
        // cur=cur->right;
        cur= head;
        for(int i=1;i<v.size();i++){
            TreeNode* tmp= new TreeNode(v[i]);
            cur->right= tmp;
            cur=cur->right;
        }
        return head;
    }
};