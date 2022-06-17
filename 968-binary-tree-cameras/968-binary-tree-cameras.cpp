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
    struct it{
        TreeNode* root;
        bool hasCamera;
        bool monitored;
    };
    map< pair<TreeNode*, pair<bool,bool> > , int> m;
    int f(TreeNode* root, bool hasCamera, bool monitored){
        if(root==NULL) return 0;
        
        if(m.count({root, {hasCamera, monitored}}) ) return m[{root, {hasCamera, monitored}}];
        if(hasCamera) return 1+ f(root->left, false, true) + f(root->right, false, true);
        
        if(monitored){
            int putCam= 1+ f(root->left, false, true) + f(root->right, false, true);
            int noCam= f(root->left, false, false) + f(root->right, false, false);
            return min(putCam, noCam);
        }
        
        int putCam= 1+ f(root->left, false, true)+ f(root->right, false, true);
        
        int leftCam=INT_MAX, rightCam=INT_MAX;
        if(root->left) leftCam= f(root->left, true, false)+ f(root->right, false, false);
        if(root->right) rightCam= f(root->left, false, false )+ f(root->right, true, false);
        
        return m[{root, {hasCamera, monitored}}]= min({putCam, leftCam, rightCam});             
    }
    int minCameraCover(TreeNode* root) {
        
        
        return f(root,false, false);
    }
};