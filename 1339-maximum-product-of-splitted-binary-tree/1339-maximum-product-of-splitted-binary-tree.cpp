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
    long long totSum=0, res=0;
    void getTotalSum(TreeNode* root){        
        if(root==NULL) return;
        
        totSum+=root->val;
        getTotalSum(root->right);
        getTotalSum(root->left); 
    }
    
    int SumUnder(TreeNode* root)             //Get the totalSum under the node `root` including root.
    {
       if(!root) return 0;
        //Get the sum of left and right subtree under node 'root'
       int sumUnderLeft=SumUnder(root->left),sumUnderRight=SumUnder(root->right); 
        //Get the max product after making left or right subtrees as seprarate tree. 
       res=max({res,(totSum-sumUnderLeft)*sumUnderLeft,(totSum-sumUnderRight)*sumUnderRight});
       return sumUnderLeft+sumUnderRight+root->val;
    }
    int maxProduct(TreeNode* root) {
        
        totSum=0;
        getTotalSum(root);
        
        SumUnder(root);
        int mod=1e9+7;     
        return res%mod;
    }
};