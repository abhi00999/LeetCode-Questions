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
    int calcl(TreeNode* root){
        if(root==NULL) return 0;
        
        return 1+ calcl(root->left);
    }
    
    int calcr(TreeNode* root){
        if(root==NULL) return 0;
        
        return 1+calcr(root->right);
    }
    
    int f(TreeNode *root){
        if(root==NULL) return 0;
        
        int lh= calcl(root), rh=calcr(root);
        if(lh==rh){
            return pow(2,lh)-1;
        }
        return 1+f(root->left)+f(root->right);
    }
    int countNodes(TreeNode* root) {
        return f(root);
    }
};