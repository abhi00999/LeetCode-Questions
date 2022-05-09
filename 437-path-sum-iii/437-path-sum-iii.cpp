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
    int fun(TreeNode* root, long long sum, long long sum_till_now){
        if(!root) return 0;
        
        long long cur= sum_till_now + root->val;
        
        if(cur==sum) return 1+ fun(root->left,sum, cur)+ fun(root->right, sum, cur);
        return fun(root->left,sum, cur)+ fun(root->right, sum, cur);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return fun(root,targetSum,0)+ pathSum(root->left, targetSum)+ pathSum(root->right, targetSum);
    }
};