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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        
        //searching in left subtree
        else if(key<root->val){
            root->left= deleteNode(root->left,key);
            return root;
        }
        
        //searching in right subtree
        else if(key>root->val){
            root->right= deleteNode(root->right,key);
            return root;
        }
        
        //else we found the node to be deleted
        
        else if(key==root->val){
            //it will have three cases
            //Case 1: the node to be deleted has 0 children
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            
            //Case 2: the node to be deleted has 1 child
            if(root->left!=NULL && root->right==NULL){
                TreeNode* tmp=root->left;
                delete root;
                return tmp;
            }
            if(root->left==NULL && root->right!=NULL){
                TreeNode* tmp=root->right;
                delete root;
                return tmp;
            }
            
            //Case 3: the node to be deleted has 2 children
            //We have two choices for the deleted node, either replace it with minimum of right subtree or with maximum of left subtree, here we are replacing with minimum of right subtree
            TreeNode* replace= root->right;
            while(replace->left!=NULL) replace=replace->left;
            
            root->val= replace->val;
            
            root->right= deleteNode(root->right,replace->val);
            return root;           
            
        }
        return root;
    }
};